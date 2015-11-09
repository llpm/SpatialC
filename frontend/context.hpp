#ifndef __SPATIALC_FRONTEND_CONTEXT_HPP__
#define __SPATIALC_FRONTEND_CONTEXT_HPP__

#include <llpm/ports.hpp>
#include <llpm/design.hpp>
#include <frontend/type.hpp>
#include <libraries/core/comm_intr.hpp>

#include <set>
#include <vector>
#include <cstdint>

namespace spatialc {

class Package;
class SpatialCModule;
class Event;

struct Variable {
    Type ty;
    llpm::OutputPort* op;
    std::string name;
    llvm::Constant* constant;

    Variable(Type ty,
             llpm::OutputPort* op,
             std::string name,
             llvm::Constant* constant = nullptr) :
        ty(ty),
        op(op),
        name(name),
        constant(constant)
    { }

    bool operator<(const Variable& v) const {
        return this->name < v.name;
    }

    bool operator==(const Variable& v) const {
        return this->name == v.name;
    }
};

class Context {
public:
    llpm::Design& design;
    Context* parent;
    Package* _pkg;
    SpatialCModule* _mod;
    Event* _ev;
    llpm::OutputPort* controlSignal;
    llpm::OutputPort* clause;
    uint32_t    idx;
    llpm::OutputPort* totalBinaryClause;
    std::vector<Variable> vars;
    llpm::Wait*       readController;
    llpm::OutputPort* writeControl;
    bool xact;
    bool atomic;
    bool recordWriteAcks;
    std::set<llpm::OutputPort*> writeAcks;

    Context(Context* parent, Package* pkg);
    Context(Context* parent, llpm::OutputPort* clause = nullptr, uint32_t idx = 0);
    Context(Context* parent, Event* ev, llpm::OutputPort* cntrl);
    Context(Context* parent, SpatialCModule* mod);

    llvm::LLVMContext& llvmCtxt() const {
        return design.context();
    }

    Package* pkg() const {
        if (this->_pkg != nullptr)
            return this->_pkg;
        if (this->parent != nullptr)
            return this->parent->pkg();
        return nullptr;
    }

    SpatialCModule* mod() const {
        if (this->_mod != nullptr)
            return this->_mod;
        if (this->parent != nullptr)
            return this->parent->mod();
        return nullptr;
    }

    Event* ev() const {
        if (this->_ev != nullptr)
            return this->_ev;
        if (this->parent != nullptr)
            return this->parent->ev();
        return nullptr;
    }

    bool inXact() const {
        if (xact)
            return true;
        if (parent != nullptr)
            return parent->inXact();
        return false;
    }

    bool inAtomic() const {
        if (atomic)
            return true;
        if (parent != nullptr)
            return parent->inXact();
        return false;
    }

    llpm::ConnectionDB* conns() const;
    llpm::OutputPort* findWriteControl() const;

    void pushWriteDone(llpm::OutputPort* op);

    bool update(const Variable& v);
    void push(const Variable& v);

    Variable* find(std::string id);
    const Variable* find(std::string id) const;

    void updateFromChildren(std::vector<Context*> children);

    // Build a clause which outputs true/false, true when this context's clause
    // and all parent's clauses are true
    llpm::OutputPort* buildTotalBinaryClause(llpm::ConnectionDB* conns);

    const std::vector<llvm::Type*> llvm() const;

    llpm::Join* createJoinSplit(llpm::ConnectionDB* conns);
};

} // namespace spatialc

#endif // __SPATIALC_FRONTEND_CONTEXT_HPP__
