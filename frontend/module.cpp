#include "module.hpp"

#include <frontend/exception.hpp>
#include <frontend/event.hpp>
#include <frontend/expression.hpp>
#include <libraries/core/logic_intr.hpp>
#include <libraries/core/comm_intr.hpp>

#include <analysis/constant.hpp>

#include <llvm/IR/Constants.h>
#include <boost/format.hpp>

using namespace std;

namespace spatialc {

SpatialCModule::SpatialCModule(Package* pkg, std::string name) : 
    ContainerModule(pkg->set()->design(), name),
    _package(pkg)
{ }

llpm::InputPort* SpatialCModule::addInputPort(Type ty,
                                              std::string name) {
    if (_nameTypes.count(name) > 0) {
        throw new SemanticError("input port " + name +
                                " has invalid name. Name already in use");
    }
    assert(!ty.isArray());
    _nameTypes.insert(make_pair(name, ty));
    auto sink = new NullSink(ty.llvm());
    auto ip = ContainerModule::addInputPort(sink->din(), name);
    _namedInputs[name] = ip;
    return ip;
}

llpm::OutputPort* SpatialCModule::addOutputPort(Type ty,
                                              std::string name) {
    if (_nameTypes.count(name) > 0) {
        throw new SemanticError("output port " + name +
                                " has invalid name. Name already in use");
    }
    assert(!ty.isArray());
    _nameTypes.insert(make_pair(name, ty));
    auto sel = new Select(0, ty.llvm());
    auto op = ContainerModule::addOutputPort(sel->dout(), name);
    _namedOutputs[name] = op;
    _outputSelects[op] = sel;
    return op;
}

llpm::Identity* SpatialCModule::addInternalPort(Type ty,
                                                std::string name) {
    if (_nameTypes.count(name) > 0) {
        throw new SemanticError("internal port " + name +
                                " has invalid name. Name already in use");
    }
    assert(!ty.isArray());
    _nameTypes.insert(make_pair(name, ty));
    auto id = new Identity(ty.llvm());
    _namedInternal[name] = id;
    auto sel = new Select(0, ty.llvm());
    conns()->connect(sel->dout(), id->din());
    _internalSelects[id] = sel;
    return id;
}

void SpatialCModule::addSubmodule(std::string name, llpm::Module* mod) {
    if (_submodules.find(name) != _submodules.end()) {
        throw CodeError("Submodule name already in use!");
    }
    _submodules[name] = mod;

    // For each submodule port, automatically add and connect an internal
    // channel to make it easier for users
    for (auto ip: mod->inputs()) {
        auto ipName = name + "." + ip->name();
        auto id = addInternalPort(Type(ip->type()), ipName);
        conns()->connect(id->dout(), ip);
    }
    for (auto op: mod->outputs()) {
        auto opName = name + "." + op->name();
        auto id = addInternalPort(Type(op->type()), opName);
        conns()->connect(_internalSelects[id]->createInput(), op);
    }
}

void SpatialCModule::addReg(Type ty, std::string name) {
    if (_nameTypes.count(name) > 0) {
        throw new SemanticError("storage " + name +
                                " has invalid name. Name already in use");
    }
    _nameTypes.insert(make_pair(name, ty));

    if (!ty.isSimple() && !ty.isStruct() && !ty.isVector())
        throw CodeError("Can only create register of simple, struct, "
                        "or vector types");
    // Create a register
    auto reg = new Register(ty.llvm());
    _namedStorage[name] = reg;
    reg->name(name);
}

void SpatialCModule::addMem(Type ty, std::string name) {
    if (_nameTypes.count(name) > 0) {
        throw new SemanticError("storage " + name +
                                " has invalid name. Name already in use");
    }
    _nameTypes.insert(make_pair(name, ty));

    if (!ty.asArray())
        throw CodeError("Can only create memory from array type");

    auto arrTy = ty.asArray();
    auto contained = arrTy->contained();
    if (contained.isSimple() || contained.isStruct()) {
        auto mem = new FiniteArray(contained.llvm(), (unsigned)arrTy->length());
        _namedStorage[name] = mem;
        mem->name(name);

    } else {
        throw CodeError("Array type for " + name + 
                        " must be simple or struct type");
    }
}

void SpatialCModule::addSubmodule(Type ty, std::string name) {
    if (_nameTypes.count(name) > 0) {
        throw new SemanticError("storage " + name +
                                " has invalid name. Name already in use");
    }
    _nameTypes.insert(make_pair(name, ty));

    if (ty.isArray()) {
        auto arrTy = ty.asArray();
        auto contained = arrTy->contained();
        if (!contained.isModule()) {
            throw CodeError("Type specified for submodule is not a module!");
        }
        for (unsigned i=0; i<arrTy->length(); i++) {
            auto mod = contained.asModule()->instantiate();
            string instName = str(boost::format("%1%[%2%]") % name % i);
            mod->name(instName);
            addSubmodule(instName, mod);
            _submoduleArrays[name].push_back(mod);
        }
    } else {
        if (!ty.isModule()) {
            throw CodeError("Type specified for submodule is not a module!");
        }

        // Add submodule
        auto mod = ty.asModule()->instantiate();
        mod->name(name);
        addSubmodule(name, mod);
    }
}

void SpatialCModule::addEvent(Event* ev) {
    for (auto npPair : ev->ioConnections()) {
        auto name = npPair.first;
        auto ports = npPair.second;
        
        int connCount = 0;

        auto inpF = _namedInputs.find(name);
        if (inpF != _namedInputs.end()) {
            // Input port connection!
            for (auto port: ports) {
                auto ip = dynamic_cast<InputPort*>(port);
                assert(ip != nullptr);
                auto driver = getDriver(inpF->second);
                conns()->connect(driver, ip);
                connCount++;
            }
        }

        auto outpF = _namedOutputs.find(name);
        if (outpF != _namedOutputs.end()) {
            // Output port connection!
            for (auto port: ports) {
                auto op = dynamic_cast<OutputPort*>(port);
                assert(op != nullptr);
                auto sel = _outputSelects[outpF->second];
                assert(sel != nullptr);
                conns()->connect(op, sel->createInput());
                connCount++;
            }
        }

        auto intpF = _namedInternal.find(name);
        if (intpF != _namedInternal.end()) {
            // Internal port connection!
            auto id = intpF->second;
            auto sel = _internalSelects[id];
            assert(sel != nullptr);
            for (auto port: ports) {
                auto op = port->asOutput();
                if (op != nullptr) {
                    conns()->connect(op, sel->createInput());
                    connCount++;
                }

                auto ip = port->asInput();
                if (ip != nullptr) {
                    conns()->connect(ip, id->dout());
                    connCount++;
                }
            }
        }

        if (connCount == 0) {
            throw SemanticError(
                "Could not find I/O '" + name + "' specified by event '"
                + ev->name() + "'.");
        }
    }

    for (auto memPair: ev->memWriteConnections()) {
        auto name = memPair.first;
        auto storF = _namedStorage.find(name);
        if (storF != _namedStorage.end()) {
            for (auto ifacePair: memPair.second)  {
                auto mem = storF->second;
                auto mux = mem->write()->multiplexer(*conns());
                auto srvr = mux->createServer();
                conns()->connect(ifacePair.first, srvr->req()->asInput());
                conns()->connect(srvr->resp()->asOutput(), ifacePair.second);
            }
        } else {
            throw CodeError("Could not find storage: " + name);
        }
    }

    for (auto memPair: ev->memReadConnections()) {
        auto name = memPair.first;
        auto storF = _namedStorage.find(name);
        if (storF != _namedStorage.end()) {
            for (auto ifacePair: memPair.second)  {
                auto mem = storF->second;
                auto mux = mem->read()->multiplexer(*conns());
                auto srvr = mux->createServer();
                conns()->connect(ifacePair.first, srvr->req()->asInput());
                conns()->connect(srvr->resp()->asOutput(), ifacePair.second);
            }
        } else {
            throw CodeError("Could not find storage: " + name);
        }
    }

    _events.push_back(ev);
}

void SpatialCModule::addConnection(Context& ctxt, ::DefConnect* conn) {
    auto portA = resolve(ctxt, conn->channelspecifier_1, true)->asOutput();
    auto portB = resolve(ctxt, conn->channelspecifier_2, false)->asInput(); 
    if (portA == nullptr || portB == nullptr) {
        throw CodeError("Could not resolve ports specified", conn->line_number);
    }
    conns()->connect(portA, portB);
}

llpm::Port* SpatialCModule::resolve(Context& ctxt, std::string id, bool isOutput) {
    if (isOutput) {
        auto inpF = _namedInputs.find(id);
        if (inpF != _namedInputs.end()) {
            // Submodule port is driven by one of our inputs
            return getDriver(inpF->second);
        } else {
            // Submodule port is driver by one of our internal channels
            auto intF = _namedInternal.find(id);
            if (intF != _namedInternal.end()) {
                return intF->second->dout();
            } else {
                throw CodeError("Could not find driver " + id);
            }
        }
        throw CodeError("Could not find output called " +
                        id);
    } else {
        auto outF = _namedOutputs.find(id);
        if (outF != _namedOutputs.end()) {
            // Submodule port is drives one of our outputs 
            return _outputSelects[outF->second]->createInput();
        } else {
            // Submodule port is drives one of our internal channels
            auto intF = _namedInternal.find(id);
            if (intF != _namedInternal.end()) {
                return _internalSelects[intF->second]->createInput();
            } else {
                throw CodeError("Could not find sink " + id);
            }
        }
        throw CodeError("Could not find output called " + id);
    }
}

std::string SpatialCModule::nameChannelSpecifier(Context& ctxt, ::ChannelSpecifier* cs) {
    auto simple = dynamic_cast<SimpleCS*>(cs);
    if (simple != nullptr) {
        return simple->id_;
    }

    auto arrayDot = dynamic_cast<ArrayDotCS*>(cs);
    if (arrayDot != nullptr) {
        auto idx = Expression::evalExpression(ctxt, arrayDot->exp_);
        auto c = llpm::EvalConstant(ctxt.conns(), idx.val);
        if (c == nullptr) {
            throw CodeError("Array connections at module-level must have "
                            "compile-time resolvable indexes",
                            arrayDot->line_number);
        }
        if (!c->getType()->isIntegerTy()) {
            throw CodeError("Array indexes must resolve to integers!",
                            arrayDot->line_number);
        }
        string name = str(boost::format("%1%[%2%].%3%")
                            % arrayDot->id_1
                            % c->getUniqueInteger().getLimitedValue()
                            % arrayDot->id_2);
        return name;
    }

    auto dot = dynamic_cast<DotCS*>(cs);
    if (dot != nullptr) {
        auto smF = _submodules.find(dot->id_1);
        if (smF == _submodules.end()) {
            throw CodeError("Could not find submodule " + dot->id_1, dot->line_number);
        }
        return dot->id_1 + "." + dot->id_2;
    }

    return "";
}
llpm::Port* SpatialCModule::resolve(Context& ctxt, ::ChannelSpecifier* cs, bool isOutput) {
    auto name = nameChannelSpecifier(ctxt, cs);
    if (name != "")
        return resolve(ctxt, name, isOutput);

    assert(false);
}

Type SpatialCModule::getType(const Context* ctxt, string typeName) {
    return Type::resolve(ctxt, typeName);
}

Type SpatialCModule::getType(const Context* ctxt, ::Type* astType) {
    return Type::resolve(ctxt, astType);
}


bool SpatialCModule::handleDeclDef(Context& ctxt, ModDef* def) {
    auto reg = dynamic_cast<DefReg*>(def);
    if (reg != nullptr) {
        string id = reg->id_;
        auto ty = getType(&ctxt, reg->type_);
        addReg(ty, id);
        return true;
    }

    auto mem = dynamic_cast<DefMem*>(def);
    if (mem!= nullptr) {
        string id = mem->id_;
        auto ty = getType(&ctxt, mem->type_);
        addMem(ty, id);
        return true;
    }

    auto sub = dynamic_cast<DefSubmodule*>(def);
    if (sub != nullptr) {
        string id = sub->id_;
        auto ty = getType(&ctxt, sub->type_);
        addSubmodule(ty, id);
        return true;
    }

    auto inp = dynamic_cast<DefInput*>(def);
    if (inp != nullptr) {
        string id = inp->id_;
        auto ty = getType(&ctxt, inp->type_);
        if (ty.isArray())
            throw CodeError("Ports cannot be arrays", def->line_number);

        addInputPort(ty, id);
        return true;
    }

    auto outp = dynamic_cast<DefOutput*>(def);
    if (outp != nullptr) {
        string id = outp->id_;
        auto ty = getType(&ctxt, outp->type_);
        if (ty.isArray())
            throw CodeError("Ports cannot be arrays", def->line_number);

        addOutputPort(ty, id);
        return true;
    }

    auto intp = dynamic_cast<DefInternal*>(def);
    if (intp != nullptr) {
        string id = intp->id_;
        auto ty = getType(&ctxt, intp->type_);
        if (ty.isArray())
            throw CodeError("Ports cannot be arrays", def->line_number);

        addInternalPort(ty, id);
        return true;
    }

    return false;
}

bool SpatialCModule::handleModDef(Context& ctxt, ModDef* def) {
    auto event = dynamic_cast<DefEvent*>(def);
    if (event != nullptr) {
        auto ev = Event::create(&ctxt, event, this);
        addEvent(ev);
        return true;
    }

    auto connection = dynamic_cast<DefConnect*>(def);
    if (connection != nullptr) {
        addConnection(ctxt, connection);
        return true;
    }

    auto forDef = dynamic_cast<DefFor*>(def);
    if (forDef != nullptr) {
        Context forCtxt(&ctxt);
        int64_t from = Expression::resolveToInt(ctxt, forDef->exp_1);
        int64_t to   = Expression::resolveToInt(ctxt, forDef->exp_2);
        auto intTy = llvm::Type::getInt64Ty(ctxt.llvmCtxt());
        for (int i=from; i<to; i++) {
            auto llvmConst = llvm::ConstantInt::get(intTy, i, true);
            Variable v(Type(intTy),
                       nullptr,
                       forDef->id_,
                       llvmConst);
            forCtxt.push(v);
            for (auto def: *forDef->listmoddef_) {
                handleModDef(forCtxt, def);
            }
        }
        return true;
    }

    return false;
}

void SpatialCModuleTemplate::parseParams() {
    auto ctxt = _pkg->ctxt();
    SomeParams* modParams = dynamic_cast<SomeParams*>(_modAst->metaparamdecl_);
    if (modParams != nullptr) {
        for (auto param: *modParams->listmetaparam_) {
            auto pname = ((MetaParam1*)param)->id_;
            auto ty = Type::resolve(ctxt, ((MetaParam1*)param)->type_);
            _params[pname] = ty;
        }
    }
}

SpatialCModuleTemplate* SpatialCModuleTemplate::args(
        std::map<std::string, Variable> templArgs) {
    if (templArgs.size() == 0)
        return this;
    return new SpatialCModuleTemplate(this, templArgs);
}

SpatialCModule* SpatialCModuleTemplate::instantiate() {
    SpatialCModule* mod = new SpatialCModule(_pkg, _modAst->id_);
    Context ctxt(_pkg->ctxt(), mod);

    SomeParams* modParams = dynamic_cast<SomeParams*>(_modAst->metaparamdecl_);
    if (modParams != nullptr) {
        for (auto param: *modParams->listmetaparam_) {
            auto pname = ((MetaParam1*)param)->id_;
            auto f = _args.find(pname);
            if (f != _args.end()) {
                auto v = f->second;
                v.name = pname;
                ctxt.push(v);
            } else {
                auto eqExp = dynamic_cast<EqExp*>(((MetaParam1*)param)->optionaleqexp_);
                if (eqExp == nullptr) {
                    throw CodeError("Module parameter '" + pname +
                                    "' must be specified!", param->line_number);
                }
                ValTy val = Expression::evalExpression(ctxt, eqExp->exp_);
                val = Expression::truncOrExtend(ctxt, val, _params[pname]);
                if (val.ty != _params[pname]) {
                    throw CodeError("Metaparameter/argument type mismatch",
                                    param->line_number);
                }
                auto c = llpm::EvalConstant(mod->conns(), val.val);
                ctxt.push(Variable(val.ty, val.val, pname, c));
            }
        }
    }

    set<ModDef*> done;
    for (ModDef* def: *_modAst->listmoddef_) {
        if (mod->handleDeclDef(ctxt, def))
            done.insert(def);
    }

    for (ModDef* def: *_modAst->listmoddef_) {
        auto rc = mod->handleModDef(ctxt, def);
        if (done.count(def) == 0 && rc == false) {
            assert(false && "Couldn't deal with module def!");
        }
    }

    return mod;
}

} // namespace spatialc
