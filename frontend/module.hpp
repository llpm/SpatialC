#ifndef __SPATIALC_FRONTEND_MODULE_HPP__
#define __SPATIALC_FRONTEND_MODULE_HPP__

#include <llpm/module.hpp>
#include <frontend/translate.hpp>
#include <frontend/type.hpp>
#include <libraries/core/mem_intr.hpp>

namespace llpm {
// fwd defs
class Select;
}

namespace spatialc {

// Fwd defs
class Event;

class SpatialCModule : public llpm::ContainerModule {
    friend class Translator;
    friend class Event;

    std::map<std::string, llpm::InputPort*>  _namedInputs;
    std::map<std::string, llpm::OutputPort*> _namedOutputs;
    std::map<std::string, llpm::Memory*>     _namedStorage;
    std::map<std::string, Type>              _nameTypes;

    std::map<llpm::OutputPort*, llpm::Select*> _outputSelects;
    std::vector<Event*>                        _events;

    SpatialCModule(llpm::Design& design, std::string name) : 
        ContainerModule(design, name)
    { }

public:
    ~SpatialCModule() { }

    DEF_GET(namedInputs);
    DEF_GET(namedOutputs);
    DEF_GET(namedStorage);
    DEF_GET(nameTypes);

    Type getType(std::string typeName);

private:
    llpm::InputPort*  addInputPort(Type, std::string name);
    llpm::OutputPort* addOutputPort(Type, std::string name);
    void addStorage(Type, std::string name);
    void addEvent(Event*);
};

}

#endif // __SPATIALC_FRONTEND_MODULE_HPP__

