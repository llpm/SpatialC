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

void SpatialCModule::addStorage(Type ty, std::string name) {
    if (_nameTypes.count(name) > 0) {
        throw new SemanticError("storage " + name +
                                " has invalid name. Name already in use");
    }
    _nameTypes.insert(make_pair(name, ty));

    if (ty.isSimple() || ty.isStruct()) {
        // Create a register
        _namedStorage[name] = new Register(ty.llvm());
    } else {
        assert(false && "Unsupported storage type");
    }
}

void SpatialCModule::addEvent(Event* ev) {
    for (auto npPair : ev->ioConnections()) {
        auto name = npPair.first;
        auto port = npPair.second;
        
        int connCount = 0;

        auto inpF = _namedInputs.find(name);
        if (inpF != _namedInputs.end()) {
            // Input port connection!
            auto ip = dynamic_cast<InputPort*>(port);
            assert(ip != nullptr);
            auto driver = getDriver(inpF->second);
            conns()->connect(driver, ip);
            connCount++;
        }

        auto outpF = _namedOutputs.find(name);
        if (outpF != _namedOutputs.end()) {
            // Output port connection!
            auto op = dynamic_cast<OutputPort*>(port);
            assert(op != nullptr);
            auto sel = _outputSelects[outpF->second];
            assert(sel != nullptr);
            conns()->connect(op, sel->createInput());
            connCount++;
        }

        auto storF = _namedStorage.find(name);
        if (storF != _namedStorage.end()) {
            // Output port connection!
            auto op = dynamic_cast<OutputPort*>(port);
            assert(op != nullptr);
            auto mux = storF->second->write()->multiplexer(*conns());
            assert(mux != nullptr);
            auto iface = mux->createServer();
            conns()->connect(op, iface->din());
            auto ns = new NullSink(iface->dout()->type());
            conns()->connect(iface->dout(), ns->din());
            connCount++;
        }

        if (connCount == 0) {
            throw SemanticError(
                "Could not find I/O '" + name + "' specified by event '"
                + ev->name() + "'.");
        } else {
            assert(connCount == 1 && "Multiple I/O by the same name?");
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
