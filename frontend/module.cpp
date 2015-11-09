#include "module.hpp"

#include <frontend/exception.hpp>
#include <frontend/event.hpp>
#include <libraries/core/logic_intr.hpp>
#include <libraries/core/comm_intr.hpp>

using namespace std;

namespace spatialc {

SpatialCModule::SpatialCModule(Package* pkg, std::string name) : 
    ContainerModule(pkg->set()->trans()->design(), name),
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

void SpatialCModule::addStorage(Type ty, std::string name) {
    if (_nameTypes.count(name) > 0) {
        throw new SemanticError("storage " + name +
                                " has invalid name. Name already in use");
    }
    _nameTypes.insert(make_pair(name, ty));

    if (ty.isSimple() || ty.isStruct() || ty.isVector()) {
        // Create a register
        auto reg = new Register(ty.llvm());
        _namedStorage[name] = reg;
        reg->name(name);
    } else if (ty.isModule()) {
        if (_submodules.find(name) != _submodules.end()) {
            throw CodeError("Submodule name already in use!");
        }
        auto mod = ty.asModule();
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
    } else if (ty.isArray()) {
        auto arrTy = ty.asArray();
        auto contained = arrTy->contained();
        if (contained.isSimple() || contained.isStruct()) {
            auto mem = new FiniteArray(contained.llvm(), (unsigned)arrTy->length());
            _namedStorage[name] = mem;
            mem->name(name);
        } else {
            throw CodeError("Array type for " + name + " must be simple or struct type");
        }
    } else {
        assert(false && "Unsupported storage type");
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

void SpatialCModule::addConnection(::DefConnect* conn) {
    auto portA = resolve(conn->channelspecifier_1, true)->asOutput();
    auto portB = resolve(conn->channelspecifier_2, false)->asInput(); 
    if (portA == nullptr || portB == nullptr) {
        throw CodeError("Could not resolve ports specified", conn->line_number);
    }
    conns()->connect(portA, portB);
}

llpm::Port* SpatialCModule::resolve(::ChannelSpecifier* cs, bool isOutput) {
    auto simple = dynamic_cast<SimpleCS*>(cs);
    if (simple != nullptr) {
        if (isOutput) {
            auto inpF = _namedInputs.find(simple->id_);
            if (inpF != _namedInputs.end()) {
                // Submodule port is driven by one of our inputs
                return getDriver(inpF->second);
            } else {
                // Submodule port is driver by one of our internal channels
                auto intF = _namedInternal.find(simple->id_);
                if (intF != _namedInternal.end()) {
                    return intF->second->dout();
                } else {
                    throw CodeError("Could not find driver " + simple->id_,
                                    simple->line_number);
                }
            }
            throw CodeError("Could not find output called " +
                            simple->id_, simple->line_number);
        } else {
            auto outF = _namedOutputs.find(simple->id_);
            if (outF != _namedOutputs.end()) {
                // Submodule port is drives one of our outputs 
                return _outputSelects[outF->second]->createInput();
            } else {
                // Submodule port is drives one of our internal channels
                auto intF = _namedInternal.find(simple->id_);
                if (intF != _namedInternal.end()) {
                    return _internalSelects[intF->second]->createInput();
                } else {
                    throw CodeError("Could not find sink " + simple->id_,
                                    simple->line_number);
                }
            }
            throw CodeError("Could not find output called " +
                            simple->id_, simple->line_number);
        }
    }

    auto dot = dynamic_cast<DotCS*>(cs);
    if (dot != nullptr) {
        auto smF = _submodules.find(dot->id_1);
        if (smF == _submodules.end()) {
            throw CodeError("Could not find submodule " + dot->id_1, dot->line_number);
        }
        auto sm = smF->second;

        Port* smPort = nullptr;
        if (isOutput) {
            for (auto op: sm->outputs()) {
                if (op->name() == dot->id_2) {
                    if (smPort != nullptr) {
                        throw CodeError("Found multiple ports called " + dot->id_2);
                    }
                    smPort = op;
                }
            }
        } else {
            InputPort* smIP = nullptr;
            for (auto ip: sm->inputs()) {
                if (ip->name() == dot->id_2) {
                    if (smPort != nullptr) {
                        throw CodeError("Found multiple ports called " + dot->id_2);
                    }
                    smIP = ip;
                    smPort = ip;
                }
            }

            auto id = _namedInternal[dot->id_1 + "." + smIP->name()];
            assert(id != nullptr);
            smIP = _internalSelects[id]->createInput();
            smPort = smIP; 
        }

        if (smPort == nullptr) {
            if (isOutput)
                throw CodeError("Could not find output port called " + dot->id_2);
            else
                throw CodeError("Could not find input port called " + dot->id_2);
        }

        return smPort;
    }

    assert(false);
}

Type SpatialCModule::getType(const Context* ctxt, string typeName) {
    return Type::resolve(ctxt, typeName);
}

Type SpatialCModule::getType(const Context* ctxt, ::Type* astType) {
    return Type::resolve(ctxt, astType);
}

} // namespace spatialc
