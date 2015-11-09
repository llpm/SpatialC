#ifndef __SPATIALC_FRONTEND_MODULE_HPP__
#define __SPATIALC_FRONTEND_MODULE_HPP__

#include <llpm/module.hpp>
#include <frontend/type.hpp>
#include <libraries/core/mem_intr.hpp>

namespace llpm {
// fwd defs
class Select;
}

// AST fwd. defs
class DefConnect;
class Type;
class ChannelSpecifier;

namespace spatialc {

// Fwd defs
class Event;
class Translator;
class Package;

class SpatialCModule : public llpm::ContainerModule {
    friend class Translator;
    friend class Event;

    Package* _package;

    std::map<std::string, llpm::InputPort*>  _namedInputs;
    std::map<std::string, llpm::OutputPort*> _namedOutputs;
    std::map<std::string, llpm::Identity*>   _namedInternal;
    std::map<std::string, llpm::Memory*>     _namedStorage;
    std::map<std::string, Type>              _nameTypes;

    std::map<std::string, llpm::Module*>     _submodules;

    std::map<llpm::OutputPort*, llpm::Select*> _outputSelects;
    std::map<llpm::Identity*,   llpm::Select*> _internalSelects;
    std::vector<Event*>                        _events;

    SpatialCModule(Package* pkg, std::string name);

public:
    ~SpatialCModule() { }

    DEF_GET(namedInputs);
    DEF_GET(namedOutputs);
    DEF_GET(namedStorage);
    DEF_GET(namedInternal);
    DEF_GET(nameTypes);
    DEF_GET(submodules);

    Type getType(const Context*, std::string typeName);
    Type getType(const Context*, ::Type* astType);

private:
    llpm::InputPort*  addInputPort(Type, std::string name);
    llpm::OutputPort* addOutputPort(Type, std::string name);
    llpm::Identity*   addInternalPort(Type, std::string name);
    void addStorage(Type, std::string name);
    void addEvent(Event*);
    void addConnection(::DefConnect*);
    llpm::Port* resolve(::ChannelSpecifier*, bool isOutput);
};

}

#endif // __SPATIALC_FRONTEND_MODULE_HPP__

