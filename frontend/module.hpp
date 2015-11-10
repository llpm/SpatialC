#ifndef __SPATIALC_FRONTEND_MODULE_HPP__
#define __SPATIALC_FRONTEND_MODULE_HPP__

#include <llpm/module.hpp>
#include <frontend/type.hpp>
#include <frontend/package_set.hpp>
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
class Package;

class SpatialCModule : public llpm::ContainerModule {
    friend class SpatialCModuleTemplate;
    friend class Event;

    Package* _package;

    std::map<std::string, llpm::InputPort*>  _namedInputs;
    std::map<std::string, llpm::OutputPort*> _namedOutputs;
    std::map<std::string, llpm::Identity*>   _namedInternal;
    std::map<std::string, llpm::Memory*>     _namedStorage;
    std::map<std::string, Type>              _nameTypes;

    std::map<std::string, llpm::Module*>              _submodules;
    std::map<std::string, std::vector<llpm::Module*>> _submoduleArrays;

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
    DEF_GET(submoduleArrays);

    Type getType(const Context*, std::string typeName);
    Type getType(const Context*, ::Type* astType);

private:
    llpm::InputPort*  addInputPort(Type, std::string name);
    llpm::OutputPort* addOutputPort(Type, std::string name);
    llpm::Identity*   addInternalPort(Type, std::string name);
    void addSubmodule(std::string name, llpm::Module*);
    void addStorage(Type, std::string name);
    void addEvent(Event*);
    void addConnection(Context& ctxt, ::DefConnect*);
    llpm::Port* resolve(Context& ctxt, std::string, bool isOutput);
    llpm::Port* resolve(Context& ctxt, ::ChannelSpecifier*, bool isOutput);
    std::string nameChannelSpecifier(Context& ctxt, ::ChannelSpecifier*);

    bool handleDeclDef(Context& ctxt, ModDef*);
    bool handleModDef(Context& ctxt, ModDef*);
};

class SpatialCModuleTemplate {
    Package* _pkg;
    DefModule* _modAst;
    std::map<std::string, Type> _params;
    std::map<std::string, Variable> _args;

    void parseParams();


public:
    SpatialCModuleTemplate(Package* pkg, DefModule* modAst) :
        _pkg(pkg),
        _modAst(modAst)
    {
        parseParams();
    }

    SpatialCModuleTemplate(SpatialCModuleTemplate* parent,
                           std::map<std::string, Variable> metaParams) :
        _pkg(parent->_pkg),
        _modAst(parent->_modAst),
        _params(parent->_params),
        _args(metaParams)
    { }

    DEF_GET_NP(params);

    SpatialCModuleTemplate* args(std::map<std::string, Variable> templArgs);
    SpatialCModule* instantiate();
};

}

#endif // __SPATIALC_FRONTEND_MODULE_HPP__

