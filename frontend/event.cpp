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
    controlWait->name("controlWait");
    controlWait->newControl(conns, cdToken);
    auto controlToken = new Constant(llvm::Type::getVoidTy(ctxt.llvmCtxt()));
    conns->connect(controlToken->dout(), controlWait->din());
    ctxt.pushControlSignal(controlWait->dout());
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
    for (auto v: ctxt.vars()) {
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
    } else {
        evName = "init";
    }

    Event* ev = new Event(parentCtxt->design, evName, mod);

    // Convert the event list to something usable
    Context ctxt(parentCtxt, ev, nullptr);
    auto initOnce = new Once(
                llvm::Type::getVoidTy(ev->design().context()));
    ctxt.pushControlSignal(initOnce->dout());

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
    processBlock(ifCtxt, stmt->block_);

    Context elseCtxt (&ctxt, clause, 0);
    Else* elseBlock = dynamic_cast<Else*>(stmt->elseblock_);
    if (elseBlock) {
        processBlock(elseCtxt, elseBlock->block_);
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

        throw CodeError("Don't yet know how to handle block attribute!",
                        block->line_number);
    }

    if (atomic) {
        if (ctxt.inAtomic()) {
            throw CodeError("Nested atomic regions not allowed",
                            block->line_number);
        }

        // Built a gated entry
        atomicSema = new Semaphore(ctxt.design);
        atomicSema->name("blockAtomic");
        conns()->connect(atomicSema->wait()->din(), ctxt.findControlSignal());
        ctxt.pushControlSignal(atomicSema->wait()->dout());
        ctxt.setAtomic();
    }

    if (atomic || xact) {
        auto readWait = new Wait(llvm::Type::getVoidTy(ctxt.llvmCtxt()));
        readWait->name("readWait");
        auto ctrlSig = ctxt.findControlSignal();
        if (ctrlSig != nullptr)
            readWait->newControl(conns(), ctrlSig);
        auto voidConst = Constant::getVoid(design());
        conns()->connect(voidConst->dout(), readWait->din());
        ctxt.setReadController(readWait);
    }

    if (xact) {
        if (ctxt.inXact()) {
            throw CodeError("Nested transactions (xact) not allowed",
                            block->line_number);
        }
        ctxt.setWriteController(ctxt.readController()->dout());
        ctxt.setXact();
    }

    // Process each statement in order, mutating the context as necessary
    for (auto s: *block->liststatement_) {
        processStatement(ctxt, s);
    }

    if (atomic) {
        auto nextAllowedWait = new Wait(atomicSema->wait()->dout()->type());
        nextAllowedWait->name("proceedWait");
        auto tokenConst = Constant::getVoid(_mod->design());
        conns()->connect(tokenConst->dout(), nextAllowedWait->din());
        conns()->connect(
            nextAllowedWait->dout(),
            atomicSema->signal());

        auto newestCS = ctxt.findControlSignal();
        if (newestCS != nullptr)
            nextAllowedWait->newControl(conns(), newestCS);
        nextAllowedWait->newControl(conns(), ctxt.readController()->dout());
        for (auto op: ctxt.writeAcks()) {
            nextAllowedWait->newControl(conns(), op);
        }
    }

    if (xact) {
        // Make next statements wait for our writes
        auto voidTy = llvm::Type::getVoidTy(ctxt.design.context());
        auto writeWait = new Wait(voidTy);
        writeWait->name("writeWait");
        auto tokenConst = Constant::getVoid(_mod->design());
        conns()->connect(tokenConst->dout(), writeWait->din());
        writeWait->newControl(conns(), ctxt.findWriteControl());
        for (auto write: ctxt.writeAcks()) {
            writeWait->newControl(conns(), write);
        }
        if (ctxt.parent() != nullptr && ctxt.parent()->ev() != nullptr) {
            ctxt.pushControlSignal(writeWait->dout());
        }

        // Note: I'm assuming ctxt is unused after this call and will be
        // destroyed. So I'm not cleaning it up!
    }
}

void Event::processStmt(Context& ctxt, PushStmt* stmt) {
    auto conns = ctxt.conns();
    auto outName = stmt->id_;
    auto val = evalExpression(ctxt, stmt->exp_).val;

    // If in transaction, wait for reads to complete
    if (ctxt.inXact()) {
        auto readWait = new Wait(val->type());
        readWait->name("readWait");
        readWait->newControl(conns, ctxt.findWriteControl());
        conns->connect(val, readWait->din());
        val = readWait->dout();
    }

    auto rtr = new Router(2, val->type());
    rtr->name("pushMaskingRouter");
    connect(val, rtr->din()->join(*conns, 1));

    // Build a value to tell us if this push should actually occur or not
    auto binClause = ctxt.buildTotalBinaryClause(conns);
    connect(binClause,  // And connect it to the idx input
            rtr->din()->join(*conns, 0));

    val = rtr->dout(1); // If the value pops out the '1' port, send it off

    // This is useful
    auto voidConst = Constant::getVoid(design())->dout();

    // A value popping out the '0' port means don't send.
    // Construct a void dummy write ack token when this occurs
    auto maskedWriteAckWait = new Wait(voidConst->type());
    maskedWriteAckWait->name("maskedWriteAckWait");
    ctxt.conns()->connect(voidConst, maskedWriteAckWait->din());
    maskedWriteAckWait->newControl(ctxt.conns(), rtr->dout(0));

    auto outp = getSinkForPush(ctxt, stmt);
    if (outp != nullptr) {
        // If this is a simple push, just push it
        val = Expression::truncOrExtend(ctxt, val, outp->type());
        connect(val, outp);
        return;
    }

    auto memF = ctxt.mod()->namedStorage()->find(outName);
    if (memF != ctxt.mod()->namedStorage()->end()) {
        // This is a write request.
        auto mem = memF->second;
        llvm::Type* memType = mem->write()->din()->type();

        auto pushArr = dynamic_cast<PushArray*>(stmt->pushsubdest_);
        OutputPort* arrIdx = nullptr;
        if (pushArr != nullptr) {
            // If the write is to a memory of something indexed, get the
            // sub-destination index.
            arrIdx = evalExpression(ctxt, pushArr->exp_).val;
            if (!arrIdx->type()->isIntegerTy()) {
                throw CodeError("Array index must resolve to int", stmt->line_number);
            }
            assert(memType->isStructTy() && "Wrong memory type constructed!");
            auto idxType = memType->getStructElementType(1);
            arrIdx = Expression::truncOrExtend(ctxt, arrIdx, idxType);
            memType = memType->getStructElementType(0);
        }

        // Truncate the expression appropriately
        val = Expression::truncOrExtend(ctxt, val, memType);
        if (arrIdx != nullptr) {
            // Join idx with value if idx is required
            auto j = new Join({val->type(), arrIdx->type()});
            connect(arrIdx, j->din(1));
            connect(val, j->din(0));
            val = j->dout();
        }

        // OK, now the write req type should match our value type!
        if (mem->write()->din()->type() != val->type()) {
            throw CodeError("Type for memory does not match expression!",
                            stmt->line_number);
        }

        // Add information about our request and response ports
        auto ev = ctxt.ev();
        auto inId = new Identity(mem->write()->respType());
        std::pair<OutputPort*, InputPort*> iface
            (ctxt.ev()->addOutputPort(val),
             ctxt.ev()->addInputPort(inId->din()));
        ev->_memWriteConnections[outName].push_back(iface);

        // The write ack needs to occur even if the write was masked out by
        // clause (if statement)! In this case, a maskedWriteAck is generated
        // above and needs to be selected here.
        auto writeAckSel = new IdxSelect(2, voidConst->type());
        writeAckSel->name("writeAckSel");
        ctxt.conns()->connect(inId->dout(), writeAckSel->din(1));
        ctxt.conns()->connect(maskedWriteAckWait->dout(), writeAckSel->din(0));
        ctxt.conns()->connect(binClause, writeAckSel->idx());
        ctxt.pushWriteDone(writeAckSel->dout());
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
    auto controlSig = ctxt.findControlSignal();
    assert(controlSig != nullptr);
    conns()->connect(controlSig,
                     exprEvalControlSel->din(0));
    auto modCtxt = ctxt.findModuleCtxt();
    assert(modCtxt != nullptr);

    // Run the wait in a new context owned by this event, but without any of
    // the current parents.
    Context waitCtxt(modCtxt, this, exprEvalControlSel->dout());

    // FIXME: This is broken if the expression uses anything from the context
    // which does not have to be requested! (i.e. messages or variables)
    auto exp = evalExpression(waitCtxt, stmt->exp_);

    auto evalRouter = new Router(2, voidTy);
    evalRouter->name("waitUntilLoop");
    auto voidConst = Constant::getVoid(design());
    auto routerIdxIn = evalRouter->din()->join(*conns())->din(0);
    exp = Expression::truncOrExtend(waitCtxt, exp, Type(routerIdxIn->type()));
    conns()->connect(exp.val, routerIdxIn);
    conns()->connect(voidConst->dout(),
                     evalRouter->din()->join(*conns())->din(1));
    conns()->connect(evalRouter->dout(0), // False ("try again") feedback
                     exprEvalControlSel->din(1));
    ctxt.pushControlSignal(evalRouter->dout(1)); // Wait until exp true
}

void Event::processStmt(Context& ctxt, ReturnStmt* stmt) {
    throw CodeError("Return statement not allowed in event!",
                    stmt->line_number);
}



ValTy Event::evalExpression(const Context& ctxt, Exp* exp) {
    return Expression::evalExpression(ctxt, exp);
}

} // namespace spatialc
