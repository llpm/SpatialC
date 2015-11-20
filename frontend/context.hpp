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

private:
    Context* _parent;
    Package* _pkg;
    SpatialCModule* _mod;
    Event* _ev;
    llpm::OutputPort* _controlSignal;
    std::map<llpm::ConnectionDB*, llpm::OutputPort*> _totalBinaryClauseCache;

    llpm::OutputPort* _clause;
    uint32_t    _idx;
    std::vector<Variable> _vars;
    llpm::Wait*       _readController;
    llpm::OutputPort* _writeControl;
    bool _xact;
    bool _atomic;
    std::set<llpm::OutputPort*> _writeAcks;

public:
    Context(Context* parent, Package* pkg);
    Context(Context* parent,
            llpm::OutputPort* clause = nullptr,
            uint32_t idx = 0);
    Context(Context* parent, Event* ev, llpm::OutputPort* cntrl);
    Context(Context* parent, SpatialCModule* mod);

    DEF_GET_NP(parent);
    DEF_GET_NP(writeAcks);
    DEF_GET_NP(vars);
    DEF_GET_NP(readController);

    llvm::LLVMContext& llvmCtxt() const {
        return design.context();
    }

    void setReadController(llpm::Wait* rc) {
        _readController = rc;
    }

    void setWriteController(llpm::OutputPort* writeControl) {
        _writeControl = writeControl;
    }

    void setXact() {
        _xact = true;
    }

    void setAtomic() {
        _atomic = true;
    }

    Package* pkg() const {
        if (this->_pkg != nullptr)
            return this->_pkg;
        if (this->_parent != nullptr)
            return this->_parent->pkg();
        return nullptr;
    }

    SpatialCModule* mod() const {
        if (this->_mod != nullptr)
            return this->_mod;
        if (this->_parent != nullptr)
            return this->_parent->mod();
        return nullptr;
    }

    Event* ev() const {
        if (this->_ev != nullptr)
            return this->_ev;
        if (this->_parent != nullptr)
            return this->_parent->ev();
        return nullptr;
    }

    bool inXact() const {
        if (_xact)
            return true;
        if (_parent != nullptr)
            return _parent->inXact();
        return false;
    }

    bool inAtomic() const {
        if (_atomic)
            return true;
        if (_parent != nullptr)
            return _parent->inAtomic();
        return false;
    }

    llpm::ConnectionDB* conns() const;
    llpm::OutputPort* findWriteControl() const;

    void pushReadDone(llpm::OutputPort* read) const;
    void pushWriteDone(llpm::OutputPort* op);

    void pushControlSignal(llpm::OutputPort* cs);
    llpm::OutputPort* findControlSignal() const;

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

    llpm::OutputPort* addControlSigWait(llpm::OutputPort*) const;
};

} // namespace spatialc

#endif // __SPATIALC_FRONTEND_CONTEXT_HPP__
