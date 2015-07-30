#ifndef __SPATIALC_FRONTEND_MODULE_HPP__
#define __SPATIALC_FRONTEND_MODULE_HPP__

#include <llpm/module.hpp>
#include <frontend/translate.hpp>
#include <frontend/type.hpp>

namespace spatialc {

class SpatialCModule : public llpm::ContainerModule {
    friend class Translator;

    std::map<std::string, llpm::InputPort*>  _namedInputs;
    std::map<std::string, llpm::OutputPort*> _namedOutputs;
    std::map<std::string, llpm::Block*>      _namedStorage;
    std::map<std::string, Type>       _nameTypes;

    SpatialCModule(llpm::Design& design, std::string name) : 
        ContainerModule(design, name)
    { }

public:
    ~SpatialCModule() { }

private:
    llpm::InputPort*  addInputPort(Type, std::string name);
    llpm::OutputPort* addOutputPort(Type, std::string name);
    void addStorage(Type, std::string name);
};

}

#endif // __SPATIALC_FRONTEND_MODULE_HPP__

