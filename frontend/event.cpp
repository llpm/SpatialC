#include "event.hpp"
#include <frontend/exception.hpp>
#include <frontend/context.hpp>
#include <frontend/expression.hpp>
#include <libraries/core/logic_intr.hpp>
#include <libraries/core/comm_intr.hpp>
#include <libraries/core/std_library.hpp>
#include <libraries/ext/mux_route.hpp>
#include <libraries/util/types.hpp>
#include <libraries/synchronization/semaphore.hpp>

#include <analysis/constant.hpp>

#include <llvm/IR/Constants.h>
#include <cassert>

using namespace std;

namespace spatialc {

Event::Event(llpm::Design& design, std::string name, SpatialCModule* mod) :
    llpm::ContainerModule(design, name),
    _mod(mod) {
}

void Event::buildInitial(Context& ctxt, ListEventParam* list) {
    unsigned ctr = 0;
    for (auto evParamI: *list) {
        EventOrCond* orCond = nullptr;
        string paramName = "";

        auto evParamWN = dynamic_cast<EventParamWithName*>(evParamI);
        if (evParamWN != nullptr) {
            orCond = evParamWN->eventorcond_;
            paramName = evParamWN->id_;
        }
        auto evParamNN = dynamic_cast<EventParamNoName*>(evParamI);
        if (evParamNN != nullptr) {
            orCond = evParamNN->eventorcond_;
            paramName = str(boost::format("**inaccessible%1%") % ctr);
        }
        assert(orCond != nullptr);

        vector<string> inpNames;
        
        auto simplecs = dynamic_cast<CSEventCond*>(orCond);
        if (simplecs != nullptr) {
            // No or condition -- just a simple input
            auto port = _mod->nameChannelSpecifier(ctxt, simplecs->channelspecifier_);
            inpNames.push_back(port);
        }

        auto orList = dynamic_cast<ListEvOr*>(orCond);
        if (orList != nullptr) {
            for (EventOrList* orEv: *orList->listeventorlist_) {
                auto cs = ((EventOrListChannelSpecifier*)orEv)->channelspecifier_;
                auto port = _mod->nameChannelSpecifier(ctxt, cs);
                inpNames.push_back(port);
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
        ctr++;
    }

    auto conns = ctxt.conns();
    // Create join for starting control/data token
    auto cdToken = ctxt.createJoinSplit(conns)->dout();

    // Create pure control token
    auto controlWait = new Wait(llvm::Type::getVoidTy(ctxt.llvmCtxt()));
    controlWait->newControl(conns, cdToken);
    auto controlToken = new Constant(llvm::Type::getVoidTy(ctxt.llvmCtxt()));
    conns->connect(controlToken->dout(), controlWait->din());
    ctxt.controlSignal = controlWait->dout();
}

llpm::InputPort* Event::getSinkForSimple(std::string outName) {
    // Look for storage by this name
    auto fs = _mod->namedStorage()->find(outName);
    if (fs != _mod->namedStorage()->end()) {
        // Do output stuff separately
        return nullptr;
    }

    // Look for output channel by this name
    auto fc = _mod->namedOutputs()->find(outName);
    if (fc != _mod->namedOutputs()->end()) {
        auto op = createOutputPort(fc->second->type());
        auto sink = getSink(op);
        _ioConnections[outName].insert(op);

        return sink;
    }

    // Look for internal channel by this name
    auto fi = _mod->namedInternal()->find(outName);
    if (fi != _mod->namedInternal()->end()) {
        auto op = createOutputPort(fi->second->din()->type());
        auto sink = getSink(op);
        _ioConnections[outName].insert(op);

        return sink;
    }

    throw SemanticError(
        "Cannot find output channel or storage for'"
        + outName + "'!");
}

llpm::InputPort* Event::getSinkForPush(Context& ctxt, PushStmt* pushStmt) {
    if (mod()->submoduleArrays()->count(pushStmt->id_)) {
        const auto smArray = mod()->submoduleArrays()->find(pushStmt->id_)->second;

        auto pushSubreg = dynamic_cast<PushSubreg*>(pushStmt->pushsubdest_);
        if (pushSubreg != nullptr) {
            // Push to _all_ of the modules in the array
            string subreg = pushSubreg->id_;
            vector<InputPort*> allports;
            llvm::Type* ty;
            for (unsigned i=0; i<smArray.size(); i++) {
                auto outp = getSinkForSimple(str(
                        boost::format("%1%[%2%].%3%")
                            % pushStmt->id_
                            % i
                            % subreg));
                allports.push_back(outp);
                if (i == 0)
                    ty = allports.front()->type();
                else
                    if (allports.back()->type() != ty)
                        throw CodeError("When pushing to entire array, input "
                                        "type must match in entire array!",
                                        pushStmt->line_number);
            }

            auto id = new Identity(ty);
            for (auto ip: allports) {
                ctxt.conns()->connect(id->dout(), ip);
            }
            return id->din();
        }

        auto pushArrayDot = dynamic_cast<PushArrayDot*>(pushStmt->pushsubdest_);
        if (pushArrayDot != nullptr) {
            // Push to one of the modules in the array
            string subreg = pushArrayDot->id_;

            auto exp = evalExpression(ctxt, pushArrayDot->exp_);
            if (!exp.val->type()->isIntegerTy()) {
                throw CodeError("Index expression must evaluate to int!", 
                                pushArrayDot->exp_->line_number);
            }
            auto c = llpm::EvalConstant(ctxt.conns(), exp.val);
            if (c != nullptr) {
                // Only one of the outputs gets written to ever,
                //  statically determined
                auto idx = c->getUniqueInteger().getLimitedValue();
                if (idx >= smArray.size()) {
                    throw CodeError(
                        str(boost::format("Constant index %1% resolved "
                                          "greater than array (%2%)")
                            % idx
                            % smArray.size()),
                        pushArrayDot->exp_->line_number);
                }
                auto outp = getSinkForSimple(str(
                        boost::format("%1%[%2%].%3%")
                            % pushStmt->id_
                            % idx
                            % subreg));
                assert(outp != nullptr);
                return outp;
            } else if (smArray.size() == 1) {
                // The array is size 1 anyway, so defacto static select
                 auto outp = getSinkForSimple(str(
                        boost::format("%1%[%2%].%3%")
                            % pushStmt->id_
                            % 0
                            % subreg));
                assert(outp != nullptr);
                return outp;
            } else {
                // Output is dynamically selected. Need a router
                vector<InputPort*> allports;
                llvm::Type* ty;
                for (unsigned i=0; i<smArray.size(); i++) {
                    auto outp = getSinkForSimple(str(
                            boost::format("%1%[%2%].%3%")
                                % pushStmt->id_
                                % i
                                % subreg));
                    allports.push_back(outp);
                    if (i == 0)
                        ty = allports.front()->type();
                    else
                        if (allports.back()->type() != ty)
                            throw CodeError("When pushing to array members, input "
                                            "type must match in entire array!",
                                            pushStmt->line_number);
                }

                auto router = new Router(allports.size(), ty);
                for (unsigned i=0; i<allports.size(); i++) {
                    ctxt.conns()->connect(router->dout(i), allports[i]);
                }
                auto rtrIdx = router->din()->join(*ctxt.conns())->din(0);
                exp = Expression::truncOrExtend(ctxt, exp, rtrIdx->type());
                ctxt.conns()->connect(exp.val, rtrIdx);
                return router->din()->join(*ctxt.conns())->din(1);
            }
        }

        throw CodeError("Can only push to a particular port of a submodule "
                        " or submodule array", pushStmt->line_number);

    } else if (mod()->submodules()->count(pushStmt->id_) > 0) {
        // This statement pushing to a submodule
        auto pushSubreg = dynamic_cast<PushSubreg*>(pushStmt->pushsubdest_);
        if (pushSubreg == nullptr) {
            throw CodeError(
                "When pushing to submodule, a channel in the "
                "submodule must be specified",
                pushStmt->line_number);
        }
        
        return getSinkForSimple(pushStmt->id_ + "." + pushSubreg->id_);
    } else {
        return getSinkForSimple(pushStmt->id_);
    }
}

Event* Event::create(Context* parentCtxt,
                     DefEvent* eventAst,
                     SpatialCModule* mod) {
    // Get event name
    string evName = "";
    auto evNameObj = dynamic_cast<EvName*>(eventAst->eventname_);
    if (evNameObj != nullptr) {
        evName = evNameObj->id_;
    }

    Event* ev = new Event(parentCtxt->design, evName, mod);

    // Convert the event list to something usable
    Context ctxt(parentCtxt, ev, nullptr);
    ev->buildInitial(ctxt, eventAst->listeventparam_);
    for (auto v: ctxt.vars) {
        auto ns = new NullSink(v.op->type());
        ev->connect(v.op, ns->din());
    }

    // Find all the outputs this event uses
    ev->processBlock(ctxt, eventAst->block_);

    return ev;
}

Event* Event::create(Context* parentCtxt,
                     DefInit* eventAst,
                     SpatialCModule* mod) {
    // Get event name
    string evName = "";
    auto evNameObj = dynamic_cast<EvName*>(eventAst->eventname_);
    if (evNameObj != nullptr) {
        evName = evNameObj->id_;
    }

    Event* ev = new Event(parentCtxt->design, evName, mod);

    // Convert the event list to something usable
    Context ctxt(parentCtxt, ev, nullptr);
    auto initOnce = new Once(
                llvm::Type::getVoidTy(ev->design().context()));
    ctxt.controlSignal = initOnce->dout();

    // Find all the outputs this event uses
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
    TYPE_PROCESS(StaticForStmt);
    TYPE_PROCESS(WaitUntilStmt);

    assert(false && "Did not know how to process statement!");
}

void Event::processStmt(Context& ctxt, VarStmt* stmt) {
    if (ctxt.find(stmt->id_) != nullptr) {
        throw CodeError("Cannot redefine " + stmt->id_,
                        stmt->line_number);
    }
    Type ty;
    ValTy val;
    OutputPort* op;

    auto tySpec = dynamic_cast<TypeSpec*>(stmt->optionaltype_);
    if (tySpec != nullptr) {
        ty = _mod->getType(&ctxt, tySpec->type_);
    }

    auto assignment = dynamic_cast<VarAssign*>(stmt->varassignment_);
    if (assignment != nullptr) {
        val = evalExpression(ctxt, assignment->exp_);
        op = val.val;
        if (!ty.isValid())
            ty = val.ty;
    } else {
        if (!ty.isValid()) {
            throw CodeError("Variable assignment must have either "
                            "expression or type specifier");
        }
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
    nvar.op = Expression::truncOrExtend(ctxt, nvar.op, old->op->type());
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
    auto idxPort = replacement->din()->join(*ctxt.ev()->conns())->din(2);
    auto valPort = replacement->din()->join(*ctxt.ev()->conns())->din(1);
    auto origValPort = replacement->din()->join(*ctxt.ev()->conns())->din(0);

    idx = Expression::truncOrExtend(ctxt, idx.val, idxPort->type());
    val = Expression::truncOrExtend(ctxt, val.val, valPort->type());

    ctxt.ev()->conns()->connect(idx.val, idxPort);
    ctxt.ev()->conns()->connect(val.val, valPort);
    ctxt.ev()->conns()->connect(old->op, origValPort);

    Variable newVar = *old;
    newVar.op = replacement->dout();
    assert(newVar.ty.llvm() == replacement->dout()->type());
    ctxt.push(newVar);
}

void Event::processStmt(Context& ctxt, IfStmt* stmt) {
    OutputPort* clause = evalExpression(ctxt, stmt->exp_).val;
    assert(clause != nullptr);

    // Process if block
    Context ifCtxt(&ctxt, clause, 1);
    for (auto bstmt: *((Block1*)stmt->block_)->liststatement_) {
        processStatement(ifCtxt, bstmt);
    }

    Context elseCtxt (&ctxt, clause, 0);
    Else* elseBlock = dynamic_cast<Else*>(stmt->elseblock_);
    if (elseBlock) {
        for (auto bstmt: *((Block1*)elseBlock->block_)->liststatement_) {
            processStatement(elseCtxt, bstmt);
        }
    }

    ctxt.updateFromChildren({&ifCtxt, &elseCtxt});
}

void Event::processStmt(Context& ctxt, StaticForStmt* stmt) {
    Context forCtxt(&ctxt);
    int64_t from = Expression::resolveToInt(ctxt, stmt->exp_1);
    int64_t to   = Expression::resolveToInt(ctxt, stmt->exp_2);
    auto intTy = llvm::Type::getInt64Ty(ctxt.llvmCtxt());
    for (int i=from; i<to; i++) {
        auto llvmConst = llvm::ConstantInt::get(intTy, i, true);
        Variable v(Type(intTy),
                   nullptr,
                   stmt->id_,
                   llvmConst);
        forCtxt.push(v);
        processBlock(forCtxt, stmt->block_);
    }
}

void Event::processStmt(Context& ctxt, BlockStmt* stmt) {
    Context blockCtxt(&ctxt);
    processBlock(blockCtxt, stmt->block_);
}

void Event::processBlock(Context& ctxt, ::Block* blockSorta) {
    auto block = dynamic_cast<Block1*>(blockSorta);
    assert(block != nullptr);

    auto xact = false;
    auto atomic = false;
    Semaphore* atomicSema = nullptr;

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
        atomicSema = new Semaphore(ctxt.design);
        conns()->connect(atomicSema->wait()->din(), ctxt.controlSignal);
        ctxt.controlSignal = atomicSema->wait()->dout();
        ctxt.clearTBCCache();
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
        auto nextAllowedWait = new Wait(atomicSema->wait()->dout()->type());
        conns()->connect(
            nextAllowedWait->dout(),
            atomicSema->signal());
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
        if (ctxt.parent != nullptr && ctxt.parent->ev() != nullptr) {
            ctxt.parent->controlSignal = writeWait->dout();
            ctxt.parent->clearTBCCache();
        }

        // Note: I'm assuming ctxt is unused after this call and will be
        // destroyed. So I'm not cleaning it up!
    }
}

void Event::processStmt(Context& ctxt, PushStmt* stmt) {
    auto conns = ctxt.conns();
    auto outName = stmt->id_;
    auto val = evalExpression(ctxt, stmt->exp_).val;
    auto rtr = new Router(2, val->type());
    connect(val, rtr->din()->join(*conns, 1));
    connect(ctxt.buildTotalBinaryClause(conns),
            rtr->din()->join(*conns, 0));
    auto ns = new NullSink(rtr->dout(0)->type());
    connect(rtr->dout(0), ns->din());
    val = rtr->dout(1);

    // If in transaction, wait for reads to complete
    if (ctxt.inXact()) {
        auto readWait = new Wait(val->type());
        readWait->newControl(conns, ctxt.findWriteControl());
        conns->connect(val, readWait->din());
        val = readWait->dout();
    }

    auto outp = getSinkForPush(ctxt, stmt);
    if (outp != nullptr) {
        val = Expression::truncOrExtend(ctxt, val, outp->type());
        connect(val, outp);
        return;
    }

    auto memF = ctxt.mod()->namedStorage()->find(outName);
    if (memF != ctxt.mod()->namedStorage()->end()) {
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
            arrIdx = Expression::truncOrExtend(ctxt, arrIdx, idxType);
            memType = memType->getStructElementType(0);
        }

        val = Expression::truncOrExtend(ctxt, val, memType);
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

        auto ev = ctxt.ev();
        auto inId = new Identity(mem->write()->respType());
        std::pair<OutputPort*, InputPort*> iface
            (ctxt.ev()->addOutputPort(val),
             ctxt.ev()->addInputPort(inId->din()));

        ev->_memWriteConnections[outName].push_back(iface);
        auto sink = new NullSink(iface.second->type());
        conns->connect(inId->dout(), sink->din());
        ctxt.pushWriteDone(inId->dout());
        return;
    }

    throw CodeError("Could not find output!", stmt->line_number);
}

void Event::processStmt(Context& ctxt, WaitUntilStmt* stmt) {
    if (!ctxt.inAtomic()) {
        throw CodeError("wait_until only valid in atomic blocks!",
                        stmt->line_number);
    }

    auto voidTy = llvm::Type::getVoidTy(design().context());
    auto exprEvalControlSel = new Select(2, voidTy);
    assert(ctxt.controlSignal != nullptr);
    conns()->connect(ctxt.controlSignal,
                     exprEvalControlSel->din(0));
    Context waitCtxt(&ctxt, this, exprEvalControlSel->dout());
    auto exp = evalExpression(waitCtxt, stmt->exp_);

    auto evalRouter = new Router(2, voidTy);
    auto voidConst = Constant::getVoid(design());
    auto routerIdxIn = evalRouter->din()->join(*conns())->din(0);
    exp = Expression::truncOrExtend(waitCtxt, exp, Type(routerIdxIn->type()));
    conns()->connect(exp.val, routerIdxIn);
    conns()->connect(voidConst->dout(),
                     evalRouter->din()->join(*conns())->din(1));
    conns()->connect(evalRouter->dout(0), // False ("try again") feedback
                     exprEvalControlSel->din(1));
    ctxt.controlSignal = evalRouter->dout(1); // Wait until exp true
    ctxt.clearTBCCache();
}

void Event::processStmt(Context& ctxt, ReturnStmt* stmt) {
    throw CodeError("Return statement not allowed in event!",
                    stmt->line_number);
}



ValTy Event::evalExpression(const Context& ctxt, Exp* exp) {
    return Expression::evalExpression(ctxt, exp);
}

} // namespace spatialc
