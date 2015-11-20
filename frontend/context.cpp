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
    _parent(parent),
    _pkg(pkg),
    _mod(nullptr),
    _ev(nullptr),
    _controlSignal(nullptr),
    _clause(nullptr),
    _readController(nullptr),
    _writeControl(nullptr),
    _xact(false),
    _atomic(false)
{ }


Context::Context(Context* parent, llpm::OutputPort* clause, uint32_t idx) :
    design(parent->design),
    _parent(parent),
    _pkg(nullptr),
    _mod(nullptr),
    _ev(nullptr),
    _controlSignal(nullptr),
    _clause(clause),
    _idx(idx),
    _readController(nullptr),
    _writeControl(nullptr),
    _xact(false),
    _atomic(false)
{ }


Context::Context(Context* parent, Event* ev, llpm::OutputPort* cntrl) :
    design(parent->design),
    _parent(parent),
    _pkg(nullptr),
    _mod(nullptr),
    _ev(ev),
    _controlSignal(nullptr),
    _clause(nullptr),
    _readController(nullptr),
    _writeControl(nullptr),
    _xact(false),
    _atomic(false)
{
    pushControlSignal(cntrl);
}

Context::Context(Context* parent, SpatialCModule* mod) :
    design(parent->design),
    _parent(parent),
    _pkg(nullptr),
    _mod(mod),
    _ev(nullptr),
    _controlSignal(nullptr),
    _clause(nullptr),
    _readController(nullptr),
    _writeControl(nullptr),
    _xact(false),
    _atomic(false)
{ }

llpm::ConnectionDB* Context::conns() const {
    auto e = ev();
    if (e != nullptr)
        return e->conns();
    auto m = mod();
    if (m != nullptr)
        return m->conns();
    return nullptr;
}

llpm::OutputPort* Context::findWriteControl() const {
    if (_writeControl != nullptr)
        return _writeControl;
    if (_parent != nullptr)
        return _parent->findWriteControl();
    return nullptr;
}

void Context::pushReadDone(llpm::OutputPort* read) const {
    if (_readController != nullptr) {
        _readController->newControl(conns(), read);
    }
    if (_parent != nullptr) {
        _parent->pushReadDone(read);
    }
}

void Context::pushWriteDone(llpm::OutputPort* op) {
    if (inAtomic() || inXact()) {
        _writeAcks.insert(op);
    } 
    if (_parent != nullptr) {
        _parent->pushWriteDone(op);
    }
}

bool Context::update(const Variable& v) {
    bool found = false;
    for (auto& ev: _vars) {
        if (ev.name == v.name) {
            ev = v;
            found = true;
        }
    }
    if (found)
        return true;
    if (_parent != nullptr && _clause == nullptr)
        return _parent->update(v);
    return false;
}

void Context::push(const Variable& v) {
    auto found = update(v);
    if (!found) {
        _vars.push_back(v);
    }
}

Variable* Context::find(string id) {
    for (auto& ev: _vars) {
        if (ev.name == id) {
            return &ev;
        }
    }
    if (_parent != nullptr) {
        return _parent->find(id);
    }
    return nullptr;
}

const Variable* Context::find(string id) const {
    for (auto& ev: _vars) {
        if (ev.name == id) {
            return &ev;
        }
    }
    if (_parent != nullptr) {
        return _parent->find(id);
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
            clause = c->_clause;
        } else {
            assert(clause == c->_clause &&
                   "All children must have same clause!");
        }
        idxs.insert(c->_idx);
    }
    assert(children.size() == idxs.size() &&
           "All children must have unique idxs");

    // Find variables to get updated
    std::map<Variable, std::set<unsigned>> updateVars;
    for (auto& child: children) {
        for (auto& cvar: child->_vars) {
            auto var = find(cvar.name);
            if (var != nullptr) {
                updateVars[*var].insert(child->_idx);
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
            if (idxs.count(child->_idx) > 0) {
                auto cvar = child->find(var.name);
                assert(cvar != nullptr);
                conns->connect(sm->getInput(*conns, child->_idx), cvar->op);
            }
        }

        var.op = sm->dout();
        update(var);
    }
}

void Context::pushControlSignal(llpm::OutputPort* cs) {
    auto prevCS = findControlSignal();
    if (prevCS != nullptr) {
        auto prevCSWait = new Wait(cs->type());
        prevCSWait->name("prevCSWait");
        conns()->connect(cs, prevCSWait->din());
        prevCSWait->newControl(conns(), prevCS);
        _controlSignal = prevCSWait->dout();
    } else {
        _controlSignal = cs;
    }
    _totalBinaryClauseCache.clear();
}

llpm::OutputPort* Context::findControlSignal() const {
    if (_controlSignal != nullptr) {
        return _controlSignal;
    } else if (_parent != nullptr) {
        return _parent->findControlSignal();
    } else {
        return nullptr;
    }
}

// Build a clause which outputs true/false, true when this context's clause
// and all parent's clauses are true
llpm::OutputPort* Context::buildTotalBinaryClause(llpm::ConnectionDB* conns) {
    auto cacheF = _totalBinaryClauseCache.find(conns);
    if (cacheF != _totalBinaryClauseCache.end()) {
        // Use a cached copy if available
        return cacheF->second;
    }

    // Get our parent's TBC so that we can respect it
    OutputPort* parentbc = nullptr;
    if (_parent != nullptr)
        parentbc = _parent->buildTotalBinaryClause(conns);

    // Build a clause comparison
    OutputPort* clauseEq = nullptr;
    if (_clause != nullptr) {
        auto localEq = new IntCompare(_clause->type(), _clause->type(),
                                      IntCompare::EQ, false);
        auto idxConst =
            new Constant(llvm::ConstantInt::get(_clause->type(), _idx, false));
        conns->connect(localEq->din()->join(*conns)->din(0), _clause);
        conns->connect(localEq->din()->join(*conns)->din(1), idxConst->dout());
        clauseEq = localEq->dout();
    }

    // Build a TBC which respects the local & parent clauses 
    OutputPort* tbc = nullptr;

    if (parentbc == nullptr) {
        if (clauseEq == nullptr) {
            //We are top level and unconditional.
            //  Build 'true' waiting for control sig
            auto trueConst = new Constant(llvm::ConstantInt::getTrue(llvmCtxt()));
            tbc = trueConst->dout();
        } else {
            tbc = clauseEq;
        }
    } else {
        if (clauseEq == nullptr) {
            tbc = parentbc;
        } else {
            auto andLogic = new Bitwise(2, parentbc->type(), Bitwise::AND);

            conns->connect(andLogic->din()->join(*conns)->din(0), parentbc);
            conns->connect(andLogic->din()->join(*conns)->din(1), clauseEq);

            tbc = andLogic->dout();
        }
    }

    tbc = addControlSigWait(tbc);
    _totalBinaryClauseCache.insert(make_pair(conns, tbc));
    return tbc;
}

llpm::OutputPort* Context::addControlSigWait(llpm::OutputPort* value) const {
    auto cs = findControlSignal();
    if (cs == nullptr)
        return value;

    auto wait = new Wait(value->type());
    wait->name("controlSigWait");
    conns()->connect(value, wait->din());
    wait->newControl(conns(), cs); 
    return wait->dout();
}

const std::vector<llvm::Type*> Context::llvm() const {
    std::vector<llvm::Type*> ret;
    for (const auto& v: _vars) {
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
        auto& v = _vars[i];
        conns->connect(v.op, j->din(i));
        v.op = s->dout(i);
    }
    return j;
}

}
