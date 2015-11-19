#ifndef __SPATIALC_FRONTEND_EVENT_HPP__
#define __SPATIALC_FRONTEND_EVENT_HPP__

#include <llpm/module.hpp>
#include <frontend/type.hpp>
#include <frontend/module.hpp>
#include <llpm/ports.hpp>

// Fwd Defs.
class PushStmt;

namespace spatialc {

using namespace llpm;

class Context;

class Event : public llpm::ContainerModule {
    friend struct Expression;

    SpatialCModule*                        _mod;
    std::map<std::string, std::set<Port*>> _ioConnections;
    std::map<std::string, OutputPort*>     _inpConnections;
    std::map<std::string, std::vector<std::pair<OutputPort*, InputPort*>>>
                                           _memWriteConnections;
    std::map<std::string, std::vector<std::pair<OutputPort*, InputPort*>>>
                                           _memReadConnections;

    Event(llpm::Design&, std::string name, SpatialCModule* mod);

    void addVariables(Context& ctxt);
    void buildInitial(Context&, ListEventParam* list);
    void processStatement(Context&, Statement*);
    void processBlock(Context&, ::Block*);
    void processStmt(Context&, VarStmt*);
    void processStmt(Context&, AssignStmt*);
    void processStmt(Context&, AssignArrStmt*);
    void processStmt(Context&, IfStmt*);
    void processStmt(Context&, BlockStmt*);
    void processStmt(Context&, PushStmt*);
    void processStmt(Context&, WaitUntilStmt*);
    void processStmt(Context&, ReturnStmt*);
    void processStmt(Context&, StaticForStmt*);

    InputPort* getSinkForSimple(std::string);
    InputPort* getSinkForPush(Context&, PushStmt*);
    ValTy evalExpression(const Context&, Exp*);

public:
    static Event* create(Context* ctxt,
                         DefEvent* eventAst,
                         SpatialCModule* module);

    static Event* create(Context* ctxt,
                         DefInit* eventAst,
                         SpatialCModule* module);

    DEF_GET_NP(inpConnections);
    DEF_GET_NP(ioConnections);
    DEF_GET_NP(memWriteConnections);
    DEF_GET_NP(memReadConnections);
    DEF_GET_NP(mod);
};

} // namespace spatialc

#endif // __SPATIALC_FRONTEND_EVENT_HPP__
