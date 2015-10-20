#include "module.hpp"

#include <frontend/exception.hpp>
#include <frontend/event.hpp>
#include <libraries/core/logic_intr.hpp>
#include <libraries/core/comm_intr.hpp>

#include <regex>

using namespace std;

namespace spatialc {

llpm::InputPort* SpatialCModule::addInputPort(Type ty,
                                              std::string name) {
    if (_nameTypes.count(name) > 0) {
        throw new SemanticError("input port " + name +
                                " has invalid name. Name already in use");
    }
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

    if (ty.isSimple() || ty.isStruct()) {
        // Create a register
        auto reg = new Register(ty.llvm());
        _namedStorage[name] = reg;
        reg->name(name);
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

regex intTypeNameR("u?int(\\d*)");

Type SpatialCModule::getType(string typeName) {
    if (typeName == "void") {
        return Type(llvm::Type::getVoidTy(design().context()));
    } else if (typeName == "bool") {
        return Type(
            llvm::Type::getIntNTy(design().context(), 1));
    }

    smatch rResult;
    if (regex_search(typeName, rResult, intTypeNameR)) {
        int width = 32;
        auto widthStr = rResult[1].str();
        if (widthStr.size() > 0) {
            width = atol(widthStr.c_str());
        }

        return Type(
            llvm::Type::getIntNTy(design().context(), width));
    }

    throw SemanticError("Could not resolve type: " + typeName);
}

} // namespace spatialc
