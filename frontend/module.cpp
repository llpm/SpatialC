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
    } else if (ty.isModule()) {
        if (_submodules.find(name) != _submodules.end()) {
            throw CodeError("Submodule name already in use!");
        }
        _submodules[name] = ty.asModule();
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
    auto smF = _submodules.find(conn->id_1);
    if (smF == _submodules.end()) {
        throw CodeError("Could not find submodule " + conn->id_1, conn->line_number);
    }
    auto sm = smF->second;

    Port* smPort = nullptr;
    for (auto ip: sm->inputs()) {
        if (ip->name() == conn->id_2) {
            if (smPort != nullptr) {
                throw CodeError("Found multiple ports called " + conn->id_2);
            }
            smPort = ip;
        }
    }

    for (auto op: sm->outputs()) {
        if (op->name() == conn->id_2) {
            if (smPort != nullptr) {
                throw CodeError("Found multiple ports called " + conn->id_2);
            }
            smPort = op;
        }
    }

    if (smPort == nullptr) {
        if (smPort != nullptr) {
            throw CodeError("Could not fine port called " + conn->id_2);
        }
    }

    auto smIP = smPort->asInput();
    if (smIP != nullptr) {
        // Submodule port is an INPUT
        if (conns()->findSource(smIP) != nullptr) {
            throw CodeError("Port connected to multiple sources", conn->line_number);
        }

        auto inpF = _namedInputs.find(conn->id_3);
        if (inpF != _namedInputs.end()) {
            // Submodule port is driven by one of our inputs
            conns()->connect(getDriver(inpF->second), smIP);
        } else {
            // Submodule port is driver by one of our internal channels
            auto intF = _namedInternal.find(conn->id_3);
            if (intF != _namedInternal.end()) {
                conns()->connect(intF->second->dout(), smIP);
            } else {
                throw CodeError("Could not find driver " + conn->id_3, conn->line_number);
            }
        }
    }

    auto smOP = smPort->asOutput();
    if (smOP != nullptr) {
        // Submodule port is an OUTPUT
        
        auto outF = _namedOutputs.find(conn->id_3);
        if (outF != _namedOutputs.end()) {
            // Submodule port is drives one of our outputs 
            conns()->connect(_outputSelects[outF->second]->createInput(), smOP);
        } else {
            // Submodule port is drives one of our internal channels
            auto intF = _namedInternal.find(conn->id_3);
            if (intF != _namedInternal.end()) {
                conns()->connect(_internalSelects[intF->second]->createInput(), smOP);
            } else {
                throw CodeError("Could not find sink " + conn->id_3, conn->line_number);
            }
        }
    }
}

Type SpatialCModule::getType(string typeName) {
    return Type::resolve(_package, typeName);
}

} // namespace spatialc
