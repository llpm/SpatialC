#include "event.hpp"
#include <frontend/exception.hpp>
#include <frontend/context.hpp>
#include <libraries/core/logic_intr.hpp>
#include <libraries/core/comm_intr.hpp>
#include <libraries/core/std_library.hpp>
#include <libraries/ext/mux_route.hpp>
#include <libraries/util/types.hpp>

#include <llvm/IR/Constants.h>
#include <cassert>

using namespace std;

namespace spatialc {

Event::Event(llpm::Design& design, std::string name, SpatialCModule* mod) :
    llpm::ContainerModule(design, name),
    _mod(mod) {
}

static std::string getEvName(EventOrList* orEv) {
    auto simple = dynamic_cast<SimpleOrList*>(orEv);
    if (simple != nullptr)
        return simple->id_;

    auto sub = dynamic_cast<SubmodOrList*>(orEv);
    if (sub != nullptr)
        return sub->id_1 + "." + sub->id_2;

    assert(false);
}

static std::string getEvName(EventOrCond* cond) {
    auto simple = dynamic_cast<SimpleEvOr*>(cond);
    if (simple != nullptr)
        return simple->id_;

    auto sub = dynamic_cast<SubmodEvOr*>(cond);
    if (sub != nullptr)
        return sub->id_1 + "." + sub->id_2;

    return "";
}

void Event::buildInitial(Context& ctxt, ListEventParam* list) {
    for (auto evParamI: *list) {
        auto evParam = dynamic_cast<EventParam1*>(evParamI);
        assert(evParam != nullptr);

        string paramName = evParam->id_;
        vector<string> inpNames;
        
        auto simpleName = getEvName(evParam->eventorcond_);
        if (simpleName != "") {
            // No or condition -- just a simple input
            inpNames.push_back(simpleName);
        }

        auto orList = dynamic_cast<ListEvOr*>(evParam->eventorcond_);
        if (orList != nullptr) {
            for (EventOrList* orEv: *orList->listeventorlist_) {
                inpNames.push_back(getEvName(orEv));
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
            *stmtList = *((::Block1*)blockStmt->block_)->liststatement_;
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

            if (mod()->submodules()->count(outName) > 0) {
                auto pushSubreg = dynamic_cast<PushSubreg*>(pushStmt->pushsubdest_);
                if (pushSubreg == nullptr) {
                    throw CodeError(
                        "When pushing to submodule, a channel in the "
                        "submodule must be specified",
                        stmt->line_number);
                }
                outName += "." + pushSubreg->id_;
            }

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
    ev->processBlock(ctxt, eventAst->block_);

    return ev;
}

void Event::processStatement(Context& ctxt, Statement* stmt) {
    #define TYPE_PROCESS(TY) { \
        auto tyStmt = dynamic_cast<TY*>(stmt); \
        if (tyStmt!= nullptr) return processStmt(ctxt, tyStmt); \
    }

    TYPE_PROCESS(VarStmt);
    TYPE_PROCESS(AssignStmt);
    TYPE_PROCESS(AssignArrStmt);
    TYPE_PROCESS(IfStmt);
    TYPE_PROCESS(BlockStmt);
    TYPE_PROCESS(PushStmt);
    TYPE_PROCESS(ReturnStmt);

    assert(false && "Did not know how to process statement!");
}

void Event::processStmt(Context& ctxt, VarStmt* stmt) {
    if (ctxt.find(stmt->id_) != nullptr) {
        throw CodeError("Cannot redefine " + stmt->id_,
                        stmt->line_number);
    }
    Type ty = _mod->getType(stmt->type_);
    OutputPort* op;

    auto assignment = dynamic_cast<VarAssign*>(stmt->varassignment_);
    if (assignment != nullptr) {
        op = evalExpression(ctxt, assignment->exp_).val;
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
    nvar.op = evalExpression(ctxt, stmt->exp_).val;
    nvar.op = truncOrExtend(nvar.op, old->op->type());
    ctxt.push(nvar);
}

void Event::processStmt(Context& ctxt, AssignArrStmt* stmt) {
    Variable* old = ctxt.find(stmt->id_);
    if (old == nullptr) {
        throw CodeError(
            "Could not find variable '" + stmt->id_ + "'",
            stmt->line_number);
    }
    if (!old->ty.isVector()) {
        throw CodeError(
            "Can only reassign elements of vectors", stmt->line_number);
    }
    auto val = evalExpression(ctxt, stmt->exp_2);
    auto idx = evalExpression(ctxt, stmt->exp_1);

    if (!idx.ty.llvm()->isIntegerTy()) {
        throw CodeError(
            "Expression in access brackets must evaluate to an integer",
            stmt->line_number);
    }

    auto replacement = new ReplaceElement(old->op->type());
    auto idxPort = replacement->din()->join(*ctxt.ev->conns())->din(2);
    auto valPort = replacement->din()->join(*ctxt.ev->conns())->din(1);
    auto origValPort = replacement->din()->join(*ctxt.ev->conns())->din(0);

    idx = truncOrExtend(idx.val, idxPort->type());
    val = truncOrExtend(val.val, valPort->type());

    ctxt.ev->conns()->connect(idx.val, idxPort);
    ctxt.ev->conns()->connect(val.val, valPort);
    ctxt.ev->conns()->connect(old->op, origValPort);

    Variable newVar = *old;
    newVar.op = replacement->dout();
    assert(newVar.ty.llvm() == replacement->dout()->type());
    ctxt.push(newVar);
}

void Event::processStmt(Context& ctxt, IfStmt* stmt) {
    OutputPort* clause = evalExpression(ctxt, stmt->exp_).val;
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
    Context blockCtxt(ctxt);
    processBlock(blockCtxt, stmt->block_);
}

void Event::processBlock(Context& ctxt, ::Block* blockSorta) {
    auto block = dynamic_cast<Block1*>(blockSorta);
    assert(block != nullptr);

    auto xact = false;
    auto atomic = false;
    Select* atomicWaitControlSelect = nullptr;

    for (auto attr: *block->listblockattr_) {
        auto xactBA = dynamic_cast<BlockAttr_xact*>(attr);
        if (xactBA != nullptr) {
            xact = true;
            continue;
        }

        auto atomicBA = dynamic_cast<BlockAttr_atomic*>(attr);
        if (atomicBA != nullptr) {
            atomic = true;
            continue;
        }

        throw CodeError("Don't yet know how to handle block attribute!", block->line_number);
    }

    if (atomic) {
        if (ctxt.inAtomic()) {
            throw CodeError("Nested atomic regions not allowed", block->line_number);
        }

        // Built a gated entry
        auto wait = new Wait(ctxt.controlSignal->type());
        conns()->connect(wait->din(), ctxt.controlSignal);
        ctxt.controlSignal = wait->dout();
        ctxt.totalBinaryClause = nullptr;
        auto once = Once::getVoid(mod()->design());
        atomicWaitControlSelect = new Select(0, once->dout()->type());
        wait->newControl(conns(), atomicWaitControlSelect->dout());
        conns()->connect(once->dout(), atomicWaitControlSelect->createInput());
        ctxt.atomic = true;
    }

    if (atomic || xact) {
        auto readWait = new Wait(llvm::Type::getVoidTy(ctxt.llvmCtxt()));
        auto voidConst = Constant::getVoid(design());
        conns()->connect(voidConst->dout(), readWait->din());
        ctxt.readController = readWait;
        ctxt.recordWriteAcks = true;
    }

    if (xact) {
        if (ctxt.inXact()) {
            throw CodeError("Nested transactions (xact) not allowed", block->line_number);
        }
        ctxt.writeControl = ctxt.readController->dout();
        ctxt.xact = true;
    }

    // Process each statement in order, mutating the context as necessary
    for (auto s: *block->liststatement_) {
        processStatement(ctxt, s);
    }

    if (atomic) {
        auto nextAllowedWait = new Wait(atomicWaitControlSelect->dout()->type());
        conns()->connect(
            nextAllowedWait->dout(),
            atomicWaitControlSelect->createInput());
        auto tokenConst = Constant::getVoid(_mod->design());
        conns()->connect(tokenConst->dout(), nextAllowedWait->din());

        nextAllowedWait->newControl(conns(), ctxt.readController->dout());
        for (auto op: ctxt.writeAcks) {
            nextAllowedWait->newControl(conns(), op);
        }
    }

    if (xact) {
        // Make next statements wait for our writes
        auto writeWait = new Wait(ctxt.controlSignal->type());
        conns()->connect(ctxt.controlSignal, writeWait->din());
        writeWait->newControl(conns(), ctxt.writeControl);
        for (auto write: ctxt.writeAcks) {
            writeWait->newControl(conns(), write);
        }
        if (ctxt.parent != nullptr) {
            ctxt.parent->controlSignal = writeWait->dout();
            ctxt.parent->totalBinaryClause = nullptr;
        }

        // Note: I'm assuming ctxt is unused after this call and will be
        // destroyed. So I'm not cleaning it up!
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

ValTy Event::truncOrExtend(ValTy val, Type ty) {
    auto newOp = truncOrExtend(val.val, ty.llvm());
    if (newOp == val.val)
        return val;
    return ValTy(newOp, ty);
}

void Event::processStmt(Context& ctxt, PushStmt* stmt) {
    auto outName = stmt->id_;
    auto val = evalExpression(ctxt, stmt->exp_).val;
    auto rtr = new Router(2, val->type());
    connect(val, rtr->din()->join(*conns(), 1));
    connect(ctxt.buildTotalBinaryClause(conns()),
            rtr->din()->join(*conns(), 0));
    auto ns = new NullSink(rtr->dout(0)->type());
    connect(rtr->dout(0), ns->din());
    val = rtr->dout(1);

    // If in transaction, wait for reads to complete
    if (ctxt.inXact()) {
        auto readWait = new Wait(val->type());
        readWait->newControl(conns(), ctxt.findWriteControl());
        conns()->connect(val, readWait->din());
        val = readWait->dout();
    }

    auto outpF = _outpConnections.find(stmt);
    if (outpF != _outpConnections.end()) {
        auto outp = _outpConnections[stmt];
        val = truncOrExtend(val, outp->type());

        connect(val, outp);
        return;
    }

    auto memF = ctxt.mod->namedStorage()->find(outName);
    if (memF != ctxt.mod->namedStorage()->end()) {
        auto mem = memF->second;
        llvm::Type* memType = mem->write()->din()->type();

        auto pushArr = dynamic_cast<PushArray*>(stmt->pushsubdest_);
        OutputPort* arrIdx = nullptr;
        if (pushArr != nullptr) {
            arrIdx = evalExpression(ctxt, pushArr->exp_).val;
            if (!arrIdx->type()->isIntegerTy()) {
                throw CodeError("Array index must resolve to int", stmt->line_number);
            }
            assert(memType->isStructTy() && "Wrong memory type constructed!");
            auto idxType = memType->getStructElementType(1);
            arrIdx = truncOrExtend(arrIdx, idxType);
            memType = memType->getStructElementType(0);
        }

        val = truncOrExtend(val, memType);
        if (arrIdx != nullptr) {
            auto j = new Join({val->type(), arrIdx->type()});
            connect(arrIdx, j->din(1));
            connect(val, j->din(0));
            val = j->dout();
        }

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
        auto sink = new NullSink(iface.second->type());
        conns()->connect(inId->dout(), sink->din());
        ctxt.pushWriteDone(inId->dout());
        return;
    }

    throw CodeError("Could not find output!", stmt->line_number);
}

void Event::processStmt(Context& ctxt, ReturnStmt* stmt) {
    throw CodeError("Return statement not allowed in event!",
                    stmt->line_number);
}

struct Expression {
    static ValTy evalExpression(const Context& ctxt, Exp* exp);

    static ValTy eval(const Context& ctxt, ETrue*) {
        return (new llpm::Constant(
                    llvm::Constant::getIntegerValue(
                        llvm::Type::getInt1Ty(ctxt.llvmCtxt()),
                        llvm::APInt(1, 1))))->dout();
    }
    static ValTy eval(const Context& ctxt, EFalse*) {
        return (new llpm::Constant(
                    llvm::Constant::getIntegerValue(
                        llvm::Type::getInt1Ty(ctxt.llvmCtxt()),
                        llvm::APInt(1, 1))))->dout();
    }
    static ValTy eval(const Context& ctxt, EInt* exp) {
        Integer i = exp->integer_;
        return (new llpm::Constant(
                    llvm::Constant::getIntegerValue(
                        llvm::Type::getIntNTy(ctxt.llvmCtxt(),
                                              sizeof(Integer) * 8),
                        llvm::APInt(sizeof(Integer) * 8, i))))->dout();
    }
    static ValTy eval(const Context& ctxt, EDouble* exp) {
        Double d = exp->double_;
        return (new llpm::Constant(
                    llvm::ConstantFP::get(
                        llvm::Type::getDoubleTy(ctxt.llvmCtxt()),
                        d)))->dout();
    }

    static ValTy evalId(const Context& ctxt, std::string id) {
        auto v = ctxt.find(id);
        if (v != nullptr) {
            return ValTy(v->op, v->ty);
        }

        auto tyF = ctxt.mod->nameTypes()->find(id);
        if (tyF == ctxt.mod->nameTypes()->end()) {
            throw CodeError("Cannot resolve identifier '" + id + "'");
        }
        auto ty = tyF->second;

        if (ty.isArray()) {
            // Memory accesses get figured out one level up the stack
            return ValTy(nullptr, ty);
        }

        auto nsF = ctxt.mod->namedStorage()->find(id);
        if (nsF != ctxt.mod->namedStorage()->end()) {
            auto mem = nsF->second;
            if (!mem->read()->din()->type()->isVoidTy()) {
                throw CodeError("Cannot access complex memory '"
                                + id + "' by only name. This memory "
                                " type needs some sort of accessor.");
            }

            auto ev = ctxt.ev;
            auto inId = new Identity(mem->read()->respType());
            std::pair<OutputPort*, InputPort*> iface
                (ctxt.ev->addOutputPort(ctxt.controlSignal),
                 ctxt.ev->addInputPort(inId->din()));

            ev->_memReadConnections[id].push_back(iface);
            if (ctxt.readController != nullptr)
                ctxt.readController->newControl(ctxt.ev->conns(), inId->dout());
            return ValTy(inId->dout(), tyF->second);
        }

        throw CodeError("Could not resolve name " + id);

    }
    static ValTy eval(const Context& ctxt, EId* exp) {
        return evalId(ctxt, exp->id_);
    }

    static ValTy eval(const Context& ctxt, EArrAcc* exp) {
        auto val = evalExpression(ctxt, exp->exp_1);

        auto idx = evalExpression(ctxt, exp->exp_2).val;
        if (!idx->type()->isIntegerTy()) {
            throw CodeError("Array index must evaluate to int", exp->line_number);
        }

        if (val.ty.isArray()) {
            string id;
            auto eid = dynamic_cast<EId*>(exp->exp_1);
            if (eid == nullptr)
                throw CodeError("For accessing into memory array, storage name"
                                " must appear directly before []", exp->line_number);
            id = eid->id_;

            auto nsF = ctxt.mod->namedStorage()->find(id);
            if (nsF == ctxt.mod->namedStorage()->end()) {
                throw CodeError("Could not locate storage", exp->line_number);
            }
            auto mem = nsF->second;
            auto memTypeF = ctxt.mod->nameTypes()->find(id);
            assert(memTypeF != ctxt.mod->nameTypes()->end());
            auto memType = memTypeF->second;

            idx = ctxt.ev->truncOrExtend(idx, mem->read()->req()->type());

            auto tyF = ctxt.mod->nameTypes()->find(id);
            assert(tyF != ctxt.mod->nameTypes()->end() &&
                        "Cannot find type!");

            auto readWait = new Wait(idx->type());
            ctxt.ev->connect(idx, readWait->din());
            readWait->newControl(ctxt.ev->conns(), ctxt.controlSignal);
            idx = readWait->dout();

            auto ev = ctxt.ev;
            auto inId = new Identity(mem->read()->respType());
            std::pair<OutputPort*, InputPort*> iface
                (ctxt.ev->addOutputPort(idx),
                 ctxt.ev->addInputPort(inId->din()));

            ev->_memReadConnections[id].push_back(iface);
            if (ctxt.readController != nullptr)
                ctxt.readController->newControl(ctxt.ev->conns(), inId->dout());
            return ValTy(inId->dout(), tyF->second.asArray()->contained());
        } else if (val.ty.isVector()) {

            auto split = val.val->split(*ctxt.ev->conns());
            auto mux = new Multiplexer(val.ty.asVector()->length(), 
                                       val.ty.asVector()->contained().llvm());
            auto muxIn = mux->din()->join(*ctxt.ev->conns());
            idx = ctxt.ev->truncOrExtend(idx, muxIn->din(0)->type());
            ctxt.ev->conns()->connect(idx, muxIn->din(0));
            for (unsigned i=0; i<val.ty.asVector()->length(); i++) {
                ctxt.ev->conns()->connect(split->dout(i), muxIn->din(i+1));
            }
            return ValTy(mux->dout(), val.ty.asVector()->contained());
        } else {
            throw CodeError("Cannot apply array access operator to this memory type",
                            exp->line_number);
        }
    }

    static ValTy eval(const Context& ctxt, EStructLiteral* exp) {
        auto ty = ctxt.mod->getType(exp->id_);
        if (!ty.isStruct()) {
            throw CodeError("Type specified for struct constructor is not a struct!",
                            exp->line_number);
        }

        auto strTy = ty.asStruct();
        vector<OutputPort*> fields(strTy->subNames().size());
        for (auto sl: *exp->liststructliteralfield_) {
            auto fieldName = ((StructLiteralField1*)sl)->id_;
            auto fieldNumF = strTy->subNames().find(fieldName);
            if (fieldNumF == strTy->subNames().end()) {
                throw CodeError("Could not find struct field '" + fieldName + "'",
                                exp->line_number);
            }
            auto fieldNum = fieldNumF->second;
            auto exp = evalExpression(ctxt, ((StructLiteralField1*)sl)->exp_);
            exp = ctxt.ev->truncOrExtend(exp, strTy->subTypes(fieldNum));
            assert(fieldNum < fields.size());
            fields[fieldNum] = exp.val;
            if (strTy->subTypes(fieldNum) != exp.ty) {
                throw CodeError("Expression does not match field type", sl->line_number);
            }
        }

        // Fill in any unspecified fields with constants containing unknowns
        for (unsigned i=0; i<fields.size(); i++) {
            if (fields[i] == nullptr) {
                auto c = new Constant(strTy->subTypes(i).llvm());
                fields[i] = c->dout();
            }
        }

        auto j = new Join(ty.llvm());
        for (unsigned i=0; i<fields.size(); i++) {
            ctxt.ev->conns()->connect(fields[i], j->din(i));
        }
        return ValTy(j->dout(), ty);
    }
    static ValTy eval(const Context& ctxt, EVectorLiteral* expLit) {
        vector<ValTy> vals;
        Type largest;
        for (auto exp: *expLit->listexp_) {
            auto val = evalExpression(ctxt, exp);
            if (!largest.isValid() ||
                    val.ty.llvm()->getPrimitiveSizeInBits() >
                    largest.llvm()->getPrimitiveSizeInBits())
                largest = val.ty;
            vals.push_back(val);
        }

        auto vecTy = new Vector(largest, vals.size());
        auto join = new Join(vecTy->llvm());
        assert(join->dout()->type() == vecTy->llvm());
        for (unsigned i=0; i<vals.size(); i++) {
            vals[i] = ctxt.ev->truncOrExtend(vals[i], largest.llvm());
            ctxt.ev->connect(vals[i].val, join->din(i));
        }
        return ValTy(join->dout(), Type(vecTy));
    }

    static ValTy eval(const Context& ctxt, EDot* exp) {
        auto val = evalExpression(ctxt, exp->exp_);
        if (!val.ty.isStruct()) {
            throw CodeError("Can only use dot (.) accessor on structs", exp->line_number);
        }

        return val.ty.asStruct()->accessor(ctxt.ev->conns(), val.val, exp->id_);
    }

    template<typename IntOp>
    struct CreateOp {
        void operator()(Exp* exp, ValTy a, ValTy b,
                             InputPort*& ain, ValTy& aout) {
            if (a.val->type()->isIntegerTy() &&
                b.val->type()->isIntegerTy()) {
                auto add = new IntOp(a.val->type(), b.val->type());
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
        void operator()(Exp* exp, ValTy a, ValTy b,
                        InputPort*& ain, ValTy& aout) {
            if (a.val->type()->isIntegerTy() &&
                b.val->type()->isIntegerTy()) {
                auto add = new IntOp({a.val->type(), b.val->type()});
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
    static ValTy evalBinOp(const Context& ctxt,
                                 Exp* exp,
                                 Exp* exp1, Exp* exp2) {
        auto a = evalExpression(ctxt, exp1);
        auto b = evalExpression(ctxt, exp2);
        InputPort* ain;
        ValTy aout;
        Create c;
        c(exp, a, b, ain, aout); 
        ctxt.ev->connect(a.val, ain->join(*ctxt.ev->conns(), 0));
        ctxt.ev->connect(b.val, ain->join(*ctxt.ev->conns(), 1));
        return aout;
    }

    static ValTy eval(const Context& ctxt, EPlus* exp) {
        return evalBinOp<CreateOpVec<IntAddition>>(
            ctxt, exp, exp->exp_1, exp->exp_2);
    }

    static ValTy eval(const Context& ctxt, EMinus* exp) {
        return evalBinOp<CreateOp<IntSubtraction>>(
            ctxt, exp, exp->exp_1, exp->exp_2);
    }

    struct CreateDivide {
        void operator()(Exp* exp, ValTy a, ValTy b,
                             InputPort*& ain, ValTy& aout) {
            if (a.val->type()->isIntegerTy() &&
                b.val->type()->isIntegerTy()) {
                // TODO: Figure out a way to determine if 'b' is signed!
                auto add = new IntDivide(a.val->type(), b.val->type(),
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
    static ValTy eval(const Context& ctxt, EDiv* exp) {
        return evalBinOp<CreateDivide>(
            ctxt, exp, exp->exp_1, exp->exp_2);
    }
    static ValTy eval(const Context& ctxt, ETimes* exp) {
        return evalBinOp<CreateOpVec<IntMultiply>>(
            ctxt, exp, exp->exp_1, exp->exp_2);
    }

    template<IntCompare::Cmp CmpType>
    struct CreateCompare {
        void operator()(Exp* exp, ValTy a, ValTy b,
                        InputPort*& ain, ValTy& aout) {
            if (a.val->type()->isIntegerTy() &&
                b.val->type()->isIntegerTy()) {
                // TODO: Figure out if this is a signed comparison!
                auto add = new IntCompare(a.val->type(), b.val->type(),
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

    static ValTy eval(const Context& ctxt, ELt* exp) {
        return evalBinOp<CreateCompare<llpm::IntCompare::GT>>(
            ctxt, exp, exp->exp_2, exp->exp_1);
    }
    static ValTy eval(const Context& ctxt, EGt* exp) {
        return evalBinOp<CreateCompare<llpm::IntCompare::GT>>(
            ctxt, exp, exp->exp_1, exp->exp_2);
    }
    static ValTy eval(const Context& ctxt, ELtEq* exp) {
        return evalBinOp<CreateCompare<llpm::IntCompare::GTE>>(
            ctxt, exp, exp->exp_2, exp->exp_1);
    }
    static ValTy eval(const Context& ctxt, EGtEq* exp) {
        return evalBinOp<CreateCompare<llpm::IntCompare::GTE>>(
            ctxt, exp, exp->exp_1, exp->exp_2);
    }
    static ValTy eval(const Context& ctxt, EEq* exp) {
        return evalBinOp<CreateCompare<llpm::IntCompare::EQ>>(
            ctxt, exp, exp->exp_1, exp->exp_2);
    }
    static ValTy eval(const Context& ctxt, ENEq* exp) {
        return evalBinOp<CreateCompare<llpm::IntCompare::NEQ>>(
            ctxt, exp, exp->exp_1, exp->exp_2);
    }

    template<Bitwise::Op OpType>
    struct CreateBitwise {
        void operator()(Exp* exp, ValTy a, ValTy b,
                        InputPort*& ain, ValTy& aout) {
            if (a.val->type()->isIntegerTy() &&
                b.val->type()->isIntegerTy()) {
                // TODO: Figure out if this is a signed comparison!
                auto add = new Bitwise(2, a.val->type(), OpType);
                ain = add->din();
                aout = add->dout();
            } else {
                throw CodeError(
                    "Cannot resolve add operator",
                    exp->line_number);
            }
        }
    };

    static ValTy eval(const Context& ctxt, EAnd* exp) {
        return evalBinOp<CreateBitwise<Bitwise::AND>>(
            ctxt, exp, exp->exp_1, exp->exp_2);
    }
    static ValTy eval(const Context& ctxt, EOr* exp) {
        return evalBinOp<CreateBitwise<Bitwise::OR>>(
            ctxt, exp, exp->exp_1, exp->exp_2);
    }
};

ValTy Expression::evalExpression(const Context& ctxt, Exp* exp) {
    #define TYPE_EXP_PROCESS(TY) { \
        auto tyExp = dynamic_cast<TY*>(exp); \
        if (tyExp != nullptr) return Expression::eval(ctxt, tyExp); \
    }

    TYPE_EXP_PROCESS(ETrue);
    TYPE_EXP_PROCESS(EFalse);
    TYPE_EXP_PROCESS(EInt);
    TYPE_EXP_PROCESS(EDouble);
    TYPE_EXP_PROCESS(EId);

    TYPE_EXP_PROCESS(EArrAcc);
    TYPE_EXP_PROCESS(EDot);

    TYPE_EXP_PROCESS(EStructLiteral);
    TYPE_EXP_PROCESS(EVectorLiteral);

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

ValTy Event::evalExpression(const Context& ctxt, Exp* exp) {
    return Expression::evalExpression(ctxt, exp);
}

} // namespace spatialc
