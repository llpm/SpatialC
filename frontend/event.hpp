#ifndef __SPATIALC_FRONTEND_EVENT_HPP__
#define __SPATIALC_FRONTEND_EVENT_HPP__

#include <llpm/module.hpp>
#include <frontend/translate.hpp>
#include <frontend/type.hpp>
#include <frontend/module.hpp>

namespace spatialc {

struct Variable {
    Type ty;
    llpm::OutputPort* op;
    std::string name;

    Variable(Type ty, llpm::OutputPort* op, std::string name) :
        ty(ty),
        op(op),
        name(name)
    { }
};

struct Context {
    std::vector<Variable> vars;

    const std::vector<llvm::Type*> llvm() {
        std::vector<llvm::Type*> ret;
        for (const auto& v: vars) {
            ret.push_back(v.ty.llvm());
        }
        return std::move(ret);
    }

    Join* createJoinSplit(ConnectionDB* conns) {
        auto tyVec = llvm();
        auto j = new Join(tyVec);
        auto s = new Split(tyVec);
        conns->connect(j->dout(), s->din());

        for (size_t i=0; i<tyVec.size(); i++) {
            auto& v = vars[i];
            conns->connect(v.op, j->din(i));
            v.op = s->dout(i);
        }
        return j;
    }
};

class Event : public llpm::ContainerModule {
    SpatialCModule*                _mod;
    std::map<std::string, Port*>   _ioConnections;

    Event(llpm::Design&, std::string name, SpatialCModule* mod);

    Context buildInitial(ListEventParam* list);
    void scanForOutputs(::Block*);

public:
    static Event* create(llpm::Design&,
                         DefEvent* eventAst,
                         SpatialCModule* module);

    DEF_GET_NP(ioConnections);
};

} // namespace spatialc

#endif // __SPATIALC_FRONTEND_EVENT_HPP__
