#include "context.hpp"

#include <frontend/module.hpp>
#include <frontend/event.hpp>
#include <frontend/exception.hpp>

#include <libraries/core/logic_intr.hpp>
#include <libraries/core/comm_intr.hpp>
#include <libraries/core/std_library.hpp>
#include <libraries/ext/mux_route.hpp>
#include <libraries/util/types.hpp>

#include <llvm/IR/Constants.h>
#include <cassert>



using namespace std;
using namespace llpm;

namespace spatialc {

Context::Context(Context* parent, Package* pkg) :
    design(pkg->design()),
    parent(parent),
    _pkg(pkg),
    _mod(nullptr),
    _ev(nullptr),
    controlSignal(nullptr),
    clause(nullptr),
    totalBinaryClause(nullptr),
    readController(nullptr),
    writeControl(nullptr),
    xact(false),
    atomic(false),
    recordWriteAcks(false)
{ }


Context::Context(Context* parent, llpm::OutputPort* clause, uint32_t idx) :
    design(parent->design),
    parent(parent),
    _pkg(nullptr),
    _mod(nullptr),
    _ev(nullptr),
    controlSignal(parent->controlSignal),
    clause(clause),
    idx(idx),
    totalBinaryClause(nullptr),
    readController(nullptr),
    writeControl(nullptr),
    xact(false),
    atomic(false),
    recordWriteAcks(false)
{ }


Context::Context(Context* parent, Event* ev, llpm::OutputPort* cntrl) :
    design(parent->design),
    parent(parent),
    _pkg(nullptr),
    _mod(nullptr),
    _ev(ev),
    controlSignal(cntrl),
    clause(nullptr),
    totalBinaryClause(nullptr),
    readController(nullptr),
    writeControl(nullptr),
    xact(false),
    atomic(false),
    recordWriteAcks(false)
{ }

Context::Context(Context* parent, SpatialCModule* mod) :
    design(parent->design),
    parent(parent),
    _pkg(nullptr),
    _mod(mod),
    _ev(nullptr),
    controlSignal(nullptr),
    clause(nullptr),
    totalBinaryClause(nullptr),
    readController(nullptr),
    writeControl(nullptr),
    xact(false),
    atomic(false),
    recordWriteAcks(false)
{ }


llpm::OutputPort* Context::findWriteControl() const {
    if (writeControl != nullptr)
        return writeControl;
    if (parent != nullptr)
        return parent->findWriteControl();
    return nullptr;
}

void Context::pushWriteDone(llpm::OutputPort* op) {
    if (recordWriteAcks) {
        writeAcks.insert(op);
    } else if (parent != nullptr) {
        parent->pushWriteDone(op);
    }
}

bool Context::update(const Variable& v) {
    bool found = false;
    for (auto& ev: vars) {
        if (ev.name == v.name) {
            ev = v;
            found = true;
        }
    }
    if (found)
        return true;
    if (parent != nullptr && clause == nullptr)
        return parent->update(v);
    return false;
}

void Context::push(const Variable& v) {
    auto found = update(v);
    if (!found) {
        vars.push_back(v);
    }
}

Variable* Context::find(string id) {
    for (auto& ev: vars) {
        if (ev.name == id) {
            return &ev;
        }
    }
    if (parent != nullptr) {
        return parent->find(id);
    }
    return nullptr;
}

const Variable* Context::find(string id) const {
    for (auto& ev: vars) {
        if (ev.name == id) {
            return &ev;
        }
    }
    if (parent != nullptr) {
        return parent->find(id);
    }
    return nullptr;
}

void Context::updateFromChildren(std::vector<Context*> children) {
    if (children.size() == 0)
        return;

    std::set<unsigned> idxs;
    llpm::OutputPort* clause = nullptr;
    for (auto c: children) {
        if (clause == nullptr) {
            clause = c->clause;
        } else {
            assert(clause == c->clause && "All children must have same clause!");
        }
        idxs.insert(c->idx);
    }
    assert(children.size() == idxs.size() && "All children must have unique idxs");

    // Find variables to get updated
    std::map<Variable, std::set<unsigned>> updateVars;
    for (auto& child: children) {
        for (auto& cvar: child->vars) {
            auto var = find(cvar.name);
            if (var != nullptr) {
                updateVars[*var].insert(child->idx);
            }
        }
    }

    // For each variable being updated, create a sparse multiplexer
    for (const auto& viPair: updateVars) {
        std::set<unsigned> idxs = viPair.second;
        Variable var = viPair.first;
        auto def = var.op;

        SparseMultiplexer* sm =
            new SparseMultiplexer(
                clause->type(),
                def->type(),
                idxs);

        ConnectionDB* conns = ev()->conns();
        conns->connect(sm->getSelector(*conns), clause);
        conns->connect(sm->getDefault(*conns), def);
        for (auto child: children) {
            if (idxs.count(child->idx) > 0) {
                auto cvar = child->find(var.name);
                assert(cvar != nullptr);
                conns->connect(sm->getInput(*conns, child->idx), cvar->op);
            }
        }

        var.op = sm->dout();
        update(var);
    }
}

// Build a clause which outputs true/false, true when this context's clause
// and all parent's clauses are true
llpm::OutputPort* Context::buildTotalBinaryClause(llpm::ConnectionDB* conns) {
    if (totalBinaryClause != nullptr) {
        // Use a cached copy if available
        return totalBinaryClause;
    }

    if (parent == nullptr && clause == nullptr) {
        //We are top level and unconditional. Build 'true' waiting for control sig
        auto trueConst = new Constant(llvm::ConstantInt::getTrue(llvmCtxt()));
        auto wait = new Wait(trueConst->dout()->type());
        conns->connect(trueConst->dout(), wait->din());
        wait->newControl(conns, controlSignal);
        totalBinaryClause = wait->dout();
        return totalBinaryClause;
    }

    if (parent == nullptr && clause != nullptr) {
        return clause;
    }

    assert(parent != nullptr);
    auto parentbc = parent->buildTotalBinaryClause(conns);
    if (clause == nullptr) {
        return parentbc;
    }

    auto andLogic = new Bitwise(2, parentbc->type(), Bitwise::AND);
    auto localEq = new IntCompare(clause->type(), clause->type(),
                                  IntCompare::EQ, false);
    auto idxConst =
        new Constant(llvm::ConstantInt::get(clause->type(), idx, false));
    conns->connect(localEq->din()->join(*conns)->din(0), clause);
    conns->connect(localEq->din()->join(*conns)->din(1), idxConst->dout());

    conns->connect(andLogic->din()->join(*conns)->din(0), parentbc);
    conns->connect(andLogic->din()->join(*conns)->din(1), localEq->dout());

    totalBinaryClause = andLogic->dout();
    return totalBinaryClause;
}

const std::vector<llvm::Type*> Context::llvm() const {
    std::vector<llvm::Type*> ret;
    for (const auto& v: vars) {
        ret.push_back(v.ty.llvm());
    }
    return std::move(ret);
}

Join* Context::createJoinSplit(ConnectionDB* conns) {
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

}
