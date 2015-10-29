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
    friend struct Expression;

    SpatialCModule*                        _mod;
    std::map<std::string, std::set<Port*>> _ioConnections;
    std::map<std::string, OutputPort*>     _inpConnections;
    std::map<std::string, std::vector<std::pair<OutputPort*, InputPort*>>>
                                           _memWriteConnections;
    std::map<std::string, std::vector<std::pair<OutputPort*, InputPort*>>>
                                           _memReadConnections;
    std::map<PushStmt*, InputPort*>        _outpConnections;

    Event(llpm::Design&, std::string name, SpatialCModule* mod);

    void addVariables(Context& ctxt);
    void buildInitial(Context&, ListEventParam* list);
    void processStatement(Context&, Statement*);
    OutputPort* truncOrExtend(OutputPort* op, llvm::Type* ty);
    ValTy truncOrExtend(ValTy op, Type ty);
    void processBlock(Context&, ::Block*);
    void processStmt(Context&, VarStmt*);
    void processStmt(Context&, AssignStmt*);
    void processStmt(Context&, AssignArrStmt*);
    void processStmt(Context&, IfStmt*);
    void processStmt(Context&, BlockStmt*);
    void processStmt(Context&, PushStmt*);
    void processStmt(Context&, ReturnStmt*);
    void scanForOutputs(::Block*);

    ValTy evalExpression(const Context&, Exp*);

public:
    static Event* create(llpm::Design&,
                         DefEvent* eventAst,
                         SpatialCModule* module);

    DEF_GET_NP(inpConnections);
    DEF_GET_NP(outpConnections);
    DEF_GET_NP(ioConnections);
    DEF_GET_NP(memWriteConnections);
    DEF_GET_NP(memReadConnections);
    DEF_GET_NP(mod);
};

} // namespace spatialc

#endif // __SPATIALC_FRONTEND_EVENT_HPP__
