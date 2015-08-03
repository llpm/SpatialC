#ifndef __SPATIALC_FRONTEND_EVENT_HPP__
#define __SPATIALC_FRONTEND_EVENT_HPP__

#include <llpm/module.hpp>
#include <frontend/translate.hpp>
#include <frontend/type.hpp>
#include <frontend/module.hpp>

// Fwd Defs.
class PushStmt;

namespace spatialc {

// Fwd defs.
struct Context;

class Event : public llpm::ContainerModule {
    SpatialCModule*                     _mod;
    std::map<std::string, Port*>        _ioConnections;
    std::map<std::string, OutputPort*>  _inpConnections;
    std::map<PushStmt*, InputPort*>     _outpConnections;

    Event(llpm::Design&, std::string name, SpatialCModule* mod);

    void addVariables(Context& ctxt);
    void buildInitial(Context&, ListEventParam* list);
    void processStatement(Context&, Statement*);
    void processStmt(Context&, VarStmt*);
    void processStmt(Context&, AssignStmt*);
    void processStmt(Context&, IfStmt*);
    void processStmt(Context&, BlockStmt*);
    void processStmt(Context&, PushStmt*);
    void processStmt(Context&, ReturnStmt*);
    void scanForOutputs(::Block*);

    OutputPort* evalExpression(const Context&, Exp*);

public:
    static Event* create(llpm::Design&,
                         DefEvent* eventAst,
                         SpatialCModule* module);

    DEF_GET_NP(inpConnections);
    DEF_GET_NP(outpConnections);
    DEF_GET_NP(ioConnections);
    DEF_GET_NP(mod);
};

} // namespace spatialc

#endif // __SPATIALC_FRONTEND_EVENT_HPP__