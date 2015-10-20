#include "event.hpp"
#include <frontend/exception.hpp>
#include <libraries/core/logic_intr.hpp>
#include <libraries/core/comm_intr.hpp>
#include <libraries/core/std_library.hpp>
#include <libraries/ext/mux_route.hpp>

#include <llvm/IR/Constants.h>
#include <cassert>

using namespace std;

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

    bool operator<(const Variable& v) const {
        return this->name < v.name;
    }

    bool operator==(const Variable& v) const {
        return this->name == v.name;
    }
};

struct Context {
    Context* parent;
    SpatialCModule* mod;
    Event* ev;
    OutputPort* controlSignal;
    OutputPort* clause;
    uint32_t    idx;
    OutputPort* totalBinaryClause;
    std::vector<Variable> vars;

    Context(Context& parent, OutputPort* clause, uint32_t idx) :
        parent(&parent),
        mod(parent.mod),
        ev(parent.ev),
        controlSignal(parent.controlSignal),
        clause(clause),
        idx(idx),
        totalBinaryClause(nullptr)
    { }


    Context(Event* ev, OutputPort* cntrl) :
        parent(nullptr),
        mod(ev->mod()),
        ev(ev),
        controlSignal(cntrl),
        clause(nullptr),
        totalBinaryClause(nullptr)
    { }

    llvm::LLVMContext& llvmCtxt() const {
        return mod->design().context();
    }

    bool update(const Variable& v) {
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

    void push(const Variable& v) {
        auto found = update(v);
        if (!found) {
            vars.push_back(v);
            printf("push %s not found, appending\n", v.name.c_str());
        } else {
            printf("push %s not found, appending\n", v.name.c_str());
        }
    }

    Variable* find(string id) {
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

    const Variable* find(string id) const {
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

    void updateFromChildren(std::vector<Context*> children) {
        if (children.size() == 0)
            return;

        std::set<unsigned> idxs;
        OutputPort* clause = nullptr;
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
                    printf("UFC found cvar: %s\n", cvar.name.c_str());
                } else {
                    printf("UFC not found cvar: %s\n", cvar.name.c_str());
                }
            }
        }

        // For each variable being updated, create a sparse multiplexer
        for (const auto& viPair: updateVars) {
            std::set<unsigned> idxs = viPair.second;
            Variable var = viPair.first;
            auto def = var.op;

            printf("UFC Var: %s\n", var.name.c_str());

            SparseMultiplexer* sm =
                new SparseMultiplexer(
                    clause->type(),
                    def->type(),
                    idxs);

            ConnectionDB* conns = ev->conns();
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
    OutputPort* buildTotalBinaryClause(ConnectionDB* conns) {
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

    const std::vector<llvm::Type*> llvm() const {
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

Event::Event(llpm::Design& design, std::string name, SpatialCModule* mod) :
    llpm::ContainerModule(design, name),
    _mod(mod) {
}

void Event::buildInitial(Context& ctxt, ListEventParam* list) {
    for (auto evParamI: *list) {
        auto evParam = dynamic_cast<EventParam1*>(evParamI);
        assert(evParam != nullptr);

        string paramName = evParam->id_;
        vector<string> inpNames;
        
        auto simpleEvOr = dynamic_cast<SimpleEvOr*>(evParam->eventorcond_);
        if (simpleEvOr != nullptr) {
            // No or condition -- just a simple input
            inpNames.push_back(simpleEvOr->id_);
        }

        auto orList = dynamic_cast<ListEvOr*>(evParam->eventorcond_);
        if (orList != nullptr) {
            for (EventOrList* orEv: *orList->listeventorlist_) {
                inpNames.push_back(((EventOrListId*)orEv)->id_);
            }
        }

        assert(inpNames.size() > 0);

        vector<Type> types;
        for (auto inpName: inpNames) {
            auto tyF = _mod->nameTypes()->find(inpName);
            if (tyF == _mod->nameTypes()->end()) {
                throw SemanticError(
                    "Could not locate input '" + inpName + "'!");
            }

            if (types.size() > 0) {
                if (*types.begin() != tyF->second) {
                    throw SemanticError(
                        "Input types in OR list don't match!");
                }
            }

            types.push_back(tyF->second);
        }

        assert(types.size() == inpNames.size());
        auto inpSel = new Select(types.size(), types.front().llvm());
        for (size_t i=0; i<inpNames.size(); i++) {
            auto ip = addInputPort(inpSel->din(i), inpNames[i]);
            _ioConnections[inpNames[i]].insert(ip);
            _inpConnections[inpNames[i]] = getDriver(ip);
        }
        Variable var(types.front(), inpSel->dout(), paramName);
        ctxt.push(var);
    }

    // Create join for starting control/data token
    auto cdToken = ctxt.createJoinSplit(conns())->dout();

    // Create pure control token
    auto controlWait = new Wait(llvm::Type::getVoidTy(ctxt.llvmCtxt()));
    controlWait->newControl(conns(), cdToken);
    auto controlToken = new Constant(llvm::Type::getVoidTy(ctxt.llvmCtxt()));
    conns()->connect(controlToken->dout(), controlWait->din());
    ctxt.controlSignal = controlWait->dout();
}

void Event::scanForOutputs(::Block* blockD) {
    auto block = dynamic_cast<Block1*>(blockD);
    assert(block != nullptr);

    for (auto stmt: *block->liststatement_) {
        auto blockStmt = dynamic_cast<BlockStmt*>(stmt);
        if (blockStmt != nullptr) {
            auto stmtList = new ListStatement();
            *stmtList = *blockStmt->liststatement_;
            ::Block1 b(nullptr, stmtList);
            scanForOutputs(&b);
            continue;
        }

        auto ifStmt = dynamic_cast<IfStmt*>(stmt);
        if (ifStmt != nullptr) {
            scanForOutputs(ifStmt->block_);
            auto elseBlock = dynamic_cast<Else*>(ifStmt->elseblock_);
            if (elseBlock != nullptr) {
                scanForOutputs(elseBlock->block_);
            }
            continue;
        }

        auto pushStmt = dynamic_cast<PushStmt*>(stmt);
        if (pushStmt != nullptr) {
            string outName = pushStmt->id_;

            // Look for storage by this name
            auto fs = _mod->namedStorage()->find(outName);
            if (fs != _mod->namedStorage()->end()) {
                // Do output stuff later on
                continue;
            }

            // Look for output channel by this name
            auto fc = _mod->namedOutputs()->find(outName);
            if (fc != _mod->namedOutputs()->end()) {
                auto op = createOutputPort(fc->second->type());
                _outpConnections[pushStmt] = getSink(op);
                _ioConnections[outName].insert(op);

                continue;
            }

            // Look for internal channel by this name
            auto fi = _mod->namedInternal()->find(outName);
            if (fi != _mod->namedInternal()->end()) {
                auto op = createOutputPort(fi->second->din()->type());
                _outpConnections[pushStmt] = getSink(op);
                _ioConnections[outName].insert(op);

                continue;
            }

            throw SemanticError(
                "Cannot find output channel or storage for'"
                + outName + "'!");
        }
    }
}

Event* Event::create(llpm::Design& design,
                     DefEvent* eventAst,
                     SpatialCModule* mod) {
    // Get event name
    string evName = "";
    auto evNameObj = dynamic_cast<EvName*>(eventAst->eventname_);
    if (evNameObj != nullptr) {
        evName = evNameObj->id_;
    }

    Event* ev = new Event(design, evName, mod);

    // Convert the event list to something usable
    Context ctxt(ev, nullptr);
    ev->buildInitial(ctxt, eventAst->listeventparam_);
    for (auto v: ctxt.vars) {
        auto ns = new NullSink(v.op->type());
        ev->connect(v.op, ns->din());
    }

    // Find all the outputs this event uses
    ev->scanForOutputs(eventAst->block_);

    // Process each statement in order, mutating the context as necessary
    for (auto stmt: *((Block1*)eventAst->block_)->liststatement_) {
        ev->processStatement(ctxt, stmt);
    }

    return ev;
}

void Event::processStatement(Context& ctxt, Statement* stmt) {
    #define TYPE_PROCESS(TY) { \
        auto tyStmt = dynamic_cast<TY*>(stmt); \
        if (tyStmt!= nullptr) return processStmt(ctxt, tyStmt); \
    }

    TYPE_PROCESS(VarStmt);
    TYPE_PROCESS(AssignStmt);
    TYPE_PROCESS(IfStmt);
    TYPE_PROCESS(BlockStmt);
    TYPE_PROCESS(PushStmt);
    TYPE_PROCESS(ReturnStmt);
}

void Event::processStmt(Context& ctxt, VarStmt* stmt) {
    if (ctxt.find(stmt->id_) != nullptr) {
        throw CodeError("Cannot redefine " + stmt->id_,
                        stmt->line_number);
    }
    Type ty = _mod->getType(((TyName*)stmt->type_)->id_);
    OutputPort* op;

    auto assignment = dynamic_cast<VarAssign*>(stmt->varassignment_);
    if (assignment != nullptr) {
        op = evalExpression(ctxt, assignment->exp_);
    } else {
        auto c = new llpm::Constant(ty.llvm());
        op = c->dout();
    }
    Variable var(ty, op, stmt->id_);
    ctxt.push(var);
}

void Event::processStmt(Context& ctxt, AssignStmt* stmt) {
    Variable* old = ctxt.find(stmt->id_);
    if (old == nullptr) {
        throw CodeError(
            "Could not find variable '" + stmt->id_ + "'",
            stmt->line_number);
    }
    Variable nvar = *old;
    nvar.op = evalExpression(ctxt, stmt->exp_);
    nvar.op = truncOrExtend(nvar.op, old->op->type());
    ctxt.push(nvar);
}

void Event::processStmt(Context& ctxt, IfStmt* stmt) {
    OutputPort* clause = evalExpression(ctxt, stmt->exp_);
    assert(clause != nullptr);

    // Process if block
    Context ifCtxt(ctxt, clause, 1);
    for (auto bstmt: *((Block1*)stmt->block_)->liststatement_) {
        processStatement(ifCtxt, bstmt);
    }

    Context elseCtxt (ctxt, clause, 0);
    Else* elseBlock = dynamic_cast<Else*>(stmt->elseblock_);
    if (elseBlock) {
        for (auto bstmt: *((Block1*)elseBlock->block_)->liststatement_) {
            processStatement(elseCtxt, bstmt);
        }
    }

    ctxt.updateFromChildren({&ifCtxt, &elseCtxt});
}

void Event::processStmt(Context& ctxt, BlockStmt* stmt) {
    // Process each statement in order, mutating the context as necessary
    Context blockCtxt(ctxt);
    for (auto s: *stmt->liststatement_) {
        processStatement(blockCtxt, s);
    }
}

/**
 * Automatically truncate or extend ints to make ports match. This is done in
 * pushes and assignments automatically and without warning.
 */
OutputPort* Event::truncOrExtend(OutputPort* op, llvm::Type* ty) {
    if (ty->isIntegerTy() && op->type()->isIntegerTy() &&
            ty->getIntegerBitWidth() != op->type()->getIntegerBitWidth()) {
        int diff = ty->getIntegerBitWidth() - op->type()->getIntegerBitWidth();
        Function* func = nullptr;
        if (diff > 0) {
            func = new IntExtend((unsigned)diff, false, op->type());
        } else {
            func = new IntTruncate((unsigned)(diff * -1), op->type());
        }
        conns()->connect(op, func->din());
        return func->dout();
    } else {
        return op;
    }
}

void Event::processStmt(Context& ctxt, PushStmt* stmt) {
    auto outName = stmt->id_;
    auto val = evalExpression(ctxt, stmt->exp_);

    auto outpF = _outpConnections.find(stmt);
    if (outpF != _outpConnections.end()) {
        auto outp = _outpConnections[stmt];
        val = truncOrExtend(val, outp->type());
        auto rtr = new Router(2, val->type());
        connect(val, rtr->din()->join(*conns(), 1));
        connect(ctxt.buildTotalBinaryClause(conns()),
                rtr->din()->join(*conns(), 0));
        connect(rtr->dout(1), outp);
        auto ns = new NullSink(rtr->dout(0)->type());
        connect(rtr->dout(0), ns->din());
        return;
    }

    auto memF = ctxt.mod->namedStorage()->find(outName);
    if (memF != ctxt.mod->namedStorage()->end()) {
        auto mem = memF->second;
        val = truncOrExtend(val, mem->write()->din()->type());
        if (mem->write()->din()->type() != val->type()) {
            throw CodeError("Type for memory does not match expression!",
                            stmt->line_number);
        }

        auto ev = ctxt.ev;
        auto inId = new Identity(mem->write()->respType());
        std::pair<OutputPort*, InputPort*> iface
            (ctxt.ev->addOutputPort(val),
             ctxt.ev->addInputPort(inId->din()));

        ev->_memWriteConnections[outName].push_back(iface);
        // TODO: Should we do something reasonable with the response?
        auto sink = new NullSink(iface.second->type());
        conns()->connect(ev->getDriver(iface.second), sink->din());
        return;
    }

    throw CodeError("Could not find output!", stmt->line_number);
}

void Event::processStmt(Context& ctxt, ReturnStmt* stmt) {
    throw CodeError("Return statement not allowed in event!",
                    stmt->line_number);
}

struct Expression {
    static OutputPort* evalExpression(const Context& ctxt, Exp* exp);

    static OutputPort* eval(const Context& ctxt, ETrue*) {
        return (new llpm::Constant(
                    llvm::Constant::getIntegerValue(
                        llvm::Type::getInt1Ty(ctxt.llvmCtxt()),
                        llvm::APInt(1, 1))))->dout();
    }
    static OutputPort* eval(const Context& ctxt, EFalse*) {
        return (new llpm::Constant(
                    llvm::Constant::getIntegerValue(
                        llvm::Type::getInt1Ty(ctxt.llvmCtxt()),
                        llvm::APInt(1, 1))))->dout();
    }
    static OutputPort* eval(const Context& ctxt, EInt* exp) {
        Integer i = exp->integer_;
        return (new llpm::Constant(
                    llvm::Constant::getIntegerValue(
                        llvm::Type::getIntNTy(ctxt.llvmCtxt(),
                                              sizeof(Integer) * 8),
                        llvm::APInt(sizeof(Integer) * 8, i))))->dout();
    }
    static OutputPort* eval(const Context& ctxt, EDouble* exp) {
        Double d = exp->double_;
        return (new llpm::Constant(
                    llvm::ConstantFP::get(
                        llvm::Type::getDoubleTy(ctxt.llvmCtxt()),
                        d)))->dout();
    }

    static OutputPort* eval(const Context& ctxt, EId* exp) {
        auto v = ctxt.find(exp->id_);
        if (v != nullptr) {
            return v->op;
        }

        auto nsF = ctxt.mod->namedStorage()->find(exp->id_);
        if (nsF != ctxt.mod->namedStorage()->end()) {
            auto mem = nsF->second;
            if (!mem->read()->din()->type()->isVoidTy()) {
                throw CodeError("Cannot access complex memory '"
                                + exp->id_ + "' by only name. This memory "
                                " type needs some sort of accessor.");
            }

            auto ev = ctxt.ev;
            auto inId = new Identity(mem->read()->respType());
            std::pair<OutputPort*, InputPort*> iface
                (ctxt.ev->addOutputPort(ctxt.controlSignal),
                 ctxt.ev->addInputPort(inId->din()));

            ev->_memReadConnections[exp->id_].push_back(iface);
            return inId->dout();
        }

        throw CodeError("Could not resolve name " + exp->id_,
                            exp->line_number);

    }

    template<typename IntOp>
    struct CreateOp {
        void operator()(Exp* exp, OutputPort* a, OutputPort* b,
                             InputPort*& ain, OutputPort*& aout) {
            if (a->type()->isIntegerTy() &&
                b->type()->isIntegerTy()) {
                auto add = new IntOp(a->type(), b->type());
                ain = add->din();
                aout = add->dout();
            } else {
                throw CodeError(
                    "Cannot resolve add operator",
                    exp->line_number);
            }
        }
    };

    template<typename IntOp>
    struct CreateOpVec {
        void operator()(Exp* exp, OutputPort* a, OutputPort* b,
                        InputPort*& ain, OutputPort*& aout) {
            if (a->type()->isIntegerTy() &&
                b->type()->isIntegerTy()) {
                auto add = new IntOp({a->type(), b->type()});
                ain = add->din();
                aout = add->dout();
            } else {
                throw CodeError(
                    "Cannot resolve add operator",
                    exp->line_number);
            }
        }
    };

    template<typename Create>
    static OutputPort* evalBinOp(const Context& ctxt,
                                 Exp* exp,
                                 Exp* exp1, Exp* exp2) {
        auto a = evalExpression(ctxt, exp1);
        auto b = evalExpression(ctxt, exp2);
        InputPort* ain;
        OutputPort* aout;
        Create c;
        c(exp, a, b, ain, aout); 
        ctxt.ev->connect(a, ain->join(*ctxt.ev->conns(), 0));
        ctxt.ev->connect(b, ain->join(*ctxt.ev->conns(), 1));
        return aout;
    }

    static OutputPort* eval(const Context& ctxt, EPlus* exp) {
        return evalBinOp<CreateOpVec<IntAddition>>(
            ctxt, exp, exp->exp_1, exp->exp_2);
    }

    static OutputPort* eval(const Context& ctxt, EMinus* exp) {
        return evalBinOp<CreateOp<IntSubtraction>>(
            ctxt, exp, exp->exp_1, exp->exp_2);
    }

    struct CreateDivide {
        void operator()(Exp* exp, OutputPort* a, OutputPort* b,
                             InputPort*& ain, OutputPort*& aout) {
            if (a->type()->isIntegerTy() &&
                b->type()->isIntegerTy()) {
                // TODO: Figure out a way to determine if 'b' is signed!
                auto add = new IntDivide(a->type(), b->type(),
                                         false);
                ain = add->din();
                aout = add->dout();
            } else {
                throw CodeError(
                    "Cannot resolve add operator",
                    exp->line_number);
            }
        }
    };
    static OutputPort* eval(const Context& ctxt, EDiv* exp) {
        return evalBinOp<CreateDivide>(
            ctxt, exp, exp->exp_1, exp->exp_2);
    }
    static OutputPort* eval(const Context& ctxt, ETimes* exp) {
        return evalBinOp<CreateOpVec<IntMultiply>>(
            ctxt, exp, exp->exp_1, exp->exp_2);
    }

    template<IntCompare::Cmp CmpType>
    struct CreateCompare {
        void operator()(Exp* exp, OutputPort* a, OutputPort* b,
                        InputPort*& ain, OutputPort*& aout) {
            if (a->type()->isIntegerTy() &&
                b->type()->isIntegerTy()) {
                // TODO: Figure out if this is a signed comparison!
                auto add = new IntCompare(a->type(), b->type(),
                                          CmpType, false);
                ain = add->din();
                aout = add->dout();
            } else {
                throw CodeError(
                    "Cannot resolve add operator",
                    exp->line_number);
            }
        }
    };

    static OutputPort* eval(const Context& ctxt, ELt* exp) {
        return evalBinOp<CreateCompare<llpm::IntCompare::GT>>(
            ctxt, exp, exp->exp_2, exp->exp_1);
    }
    static OutputPort* eval(const Context& ctxt, EGt* exp) {
        return evalBinOp<CreateCompare<llpm::IntCompare::GT>>(
            ctxt, exp, exp->exp_1, exp->exp_2);
    }
    static OutputPort* eval(const Context& ctxt, ELtEq* exp) {
        return evalBinOp<CreateCompare<llpm::IntCompare::GTE>>(
            ctxt, exp, exp->exp_2, exp->exp_1);
    }
    static OutputPort* eval(const Context& ctxt, EGtEq* exp) {
        return evalBinOp<CreateCompare<llpm::IntCompare::GTE>>(
            ctxt, exp, exp->exp_1, exp->exp_2);
    }
    static OutputPort* eval(const Context& ctxt, EEq* exp) {
        return evalBinOp<CreateCompare<llpm::IntCompare::EQ>>(
            ctxt, exp, exp->exp_1, exp->exp_2);
    }
    static OutputPort* eval(const Context& ctxt, ENEq* exp) {
        return evalBinOp<CreateCompare<llpm::IntCompare::NEQ>>(
            ctxt, exp, exp->exp_1, exp->exp_2);
    }

    template<Bitwise::Op OpType>
    struct CreateBitwise {
        void operator()(Exp* exp, OutputPort* a, OutputPort* b,
                        InputPort*& ain, OutputPort*& aout) {
            if (a->type()->isIntegerTy() &&
                b->type()->isIntegerTy()) {
                // TODO: Figure out if this is a signed comparison!
                auto add = new Bitwise(2, a->type(), OpType);
                ain = add->din();
                aout = add->dout();
            } else {
                throw CodeError(
                    "Cannot resolve add operator",
                    exp->line_number);
            }
        }
    };

    static OutputPort* eval(const Context& ctxt, EAnd* exp) {
        return evalBinOp<CreateBitwise<Bitwise::AND>>(
            ctxt, exp, exp->exp_1, exp->exp_2);
    }
    static OutputPort* eval(const Context& ctxt, EOr* exp) {
        return evalBinOp<CreateBitwise<Bitwise::OR>>(
            ctxt, exp, exp->exp_1, exp->exp_2);
    }
};

OutputPort* Expression::evalExpression(const Context& ctxt, Exp* exp) {
    #define TYPE_EXP_PROCESS(TY) { \
        auto tyExp = dynamic_cast<TY*>(exp); \
        if (tyExp != nullptr) return Expression::eval(ctxt, tyExp); \
    }

    TYPE_EXP_PROCESS(ETrue);
    TYPE_EXP_PROCESS(EFalse);
    TYPE_EXP_PROCESS(EInt);
    TYPE_EXP_PROCESS(EDouble);
    TYPE_EXP_PROCESS(EId);

    TYPE_EXP_PROCESS(EPlus);
    TYPE_EXP_PROCESS(EMinus);
    TYPE_EXP_PROCESS(ETimes);
    TYPE_EXP_PROCESS(EDiv);
    TYPE_EXP_PROCESS(ELt);
    TYPE_EXP_PROCESS(EGt);
    TYPE_EXP_PROCESS(ELtEq);
    TYPE_EXP_PROCESS(EGtEq);
    TYPE_EXP_PROCESS(EEq);
    TYPE_EXP_PROCESS(ENEq);
    TYPE_EXP_PROCESS(EAnd);
    TYPE_EXP_PROCESS(EOr);


    throw CodeError("Could not translate expression",
                    exp->line_number);
}

OutputPort* Event::evalExpression(const Context& ctxt, Exp* exp) {
    return Expression::evalExpression(ctxt, exp);
}

} // namespace spatialc
