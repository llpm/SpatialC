#include "expression.hpp"
#include <frontend/exception.hpp>
#include <frontend/context.hpp>
#include <frontend/module.hpp>
#include <frontend/event.hpp>
#include <libraries/core/logic_intr.hpp>
#include <libraries/core/comm_intr.hpp>
#include <libraries/core/std_library.hpp>
#include <libraries/util/types.hpp>

#include <llvm/IR/Constants.h>
#include <cassert>

using namespace std;
using namespace llpm;

namespace spatialc {

ValTy Expression::eval(const Context& ctxt, ETrue*) {
    return (new llpm::Constant(
                llvm::Constant::getIntegerValue(
                    llvm::Type::getInt1Ty(ctxt.llvmCtxt()),
                    llvm::APInt(1, 1))))->dout();
}
ValTy Expression::eval(const Context& ctxt, EFalse*) {
    return (new llpm::Constant(
                llvm::Constant::getIntegerValue(
                    llvm::Type::getInt1Ty(ctxt.llvmCtxt()),
                    llvm::APInt(1, 1))))->dout();
}
ValTy Expression::eval(const Context& ctxt, EInt* exp) {
    Integer i = exp->integer_;
    return (new llpm::Constant(
                llvm::Constant::getIntegerValue(
                    llvm::Type::getIntNTy(ctxt.llvmCtxt(),
                                          sizeof(Integer) * 8),
                    llvm::APInt(sizeof(Integer) * 8, i))))->dout();
}
ValTy Expression::eval(const Context& ctxt, EDouble* exp) {
    Double d = exp->double_;
    return (new llpm::Constant(
                llvm::ConstantFP::get(
                    llvm::Type::getDoubleTy(ctxt.llvmCtxt()),
                    d)))->dout();
}

ValTy Expression::evalId(const Context& ctxt, std::string id) {
    auto v = ctxt.find(id);
    if (v != nullptr) {
        return ValTy(v->op, v->ty);
    }

    auto tyF = ctxt.mod()->nameTypes()->find(id);
    if (tyF == ctxt.mod()->nameTypes()->end()) {
        throw CodeError("Cannot resolve identifier '" + id + "'");
    }
    auto ty = tyF->second;

    if (ty.isArray()) {
        // Memory accesses get figured out one level up the stack
        return ValTy(nullptr, ty);
    }

    auto nsF = ctxt.mod()->namedStorage()->find(id);
    if (nsF != ctxt.mod()->namedStorage()->end()) {
        auto mem = nsF->second;
        if (!mem->read()->din()->type()->isVoidTy()) {
            throw CodeError("Cannot access complex memory '"
                            + id + "' by only name. This memory "
                            " type needs some sort of accessor.");
        }

        auto ev = ctxt.ev();
        auto inId = new Identity(mem->read()->respType());
        std::pair<OutputPort*, InputPort*> iface
            (ctxt.ev()->addOutputPort(ctxt.controlSignal),
             ctxt.ev()->addInputPort(inId->din()));

        ev->_memReadConnections[id].push_back(iface);
        if (ctxt.readController != nullptr)
            ctxt.readController->newControl(ctxt.ev()->conns(), inId->dout());
        return ValTy(inId->dout(), tyF->second);
    }

    throw CodeError("Could not resolve name " + id);

}
ValTy Expression::eval(const Context& ctxt, EId* exp) {
    return evalId(ctxt, exp->id_);
}

ValTy Expression::eval(const Context& ctxt, EArrAcc* exp) {
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

        auto nsF = ctxt.mod()->namedStorage()->find(id);
        if (nsF == ctxt.mod()->namedStorage()->end()) {
            throw CodeError("Could not locate storage", exp->line_number);
        }
        auto mem = nsF->second;
        auto memTypeF = ctxt.mod()->nameTypes()->find(id);
        assert(memTypeF != ctxt.mod()->nameTypes()->end());
        auto memType = memTypeF->second;

        idx = truncOrExtend(ctxt, idx, mem->read()->req()->type());

        auto tyF = ctxt.mod()->nameTypes()->find(id);
        assert(tyF != ctxt.mod()->nameTypes()->end() &&
                    "Cannot find type!");

        auto readWait = new Wait(idx->type());
        ctxt.ev()->connect(idx, readWait->din());
        readWait->newControl(ctxt.ev()->conns(), ctxt.controlSignal);
        idx = readWait->dout();

        auto ev = ctxt.ev();
        auto inId = new Identity(mem->read()->respType());
        std::pair<OutputPort*, InputPort*> iface
            (ctxt.ev()->addOutputPort(idx),
             ctxt.ev()->addInputPort(inId->din()));

        ev->_memReadConnections[id].push_back(iface);
        if (ctxt.readController != nullptr)
            ctxt.readController->newControl(ctxt.ev()->conns(), inId->dout());
        return ValTy(inId->dout(), tyF->second.asArray()->contained());
    } else if (val.ty.isVector()) {

        auto split = val.val->split(*ctxt.ev()->conns());
        auto mux = new Multiplexer(val.ty.asVector()->length(), 
                                   val.ty.asVector()->contained().llvm());
        auto muxIn = mux->din()->join(*ctxt.ev()->conns());
        idx = truncOrExtend(ctxt, idx, muxIn->din(0)->type());
        ctxt.ev()->conns()->connect(idx, muxIn->din(0));
        for (unsigned i=0; i<val.ty.asVector()->length(); i++) {
            ctxt.ev()->conns()->connect(split->dout(i), muxIn->din(i+1));
        }
        return ValTy(mux->dout(), val.ty.asVector()->contained());
    } else {
        throw CodeError("Cannot apply array access operator to this memory type",
                        exp->line_number);
    }
}

ValTy Expression::eval(const Context& ctxt, EStructLiteral* exp) {
    auto ty = ctxt.mod()->getType(&ctxt, exp->id_);
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
        exp = truncOrExtend(ctxt, exp, strTy->subTypes(fieldNum));
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
        ctxt.ev()->conns()->connect(fields[i], j->din(i));
    }
    return ValTy(j->dout(), ty);
}
ValTy Expression::eval(const Context& ctxt, EVectorLiteral* expLit) {
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
        vals[i] = truncOrExtend(ctxt, vals[i], largest.llvm());
        ctxt.ev()->connect(vals[i].val, join->din(i));
    }
    return ValTy(join->dout(), Type(vecTy));
}

ValTy Expression::eval(const Context& ctxt, EDot* exp) {
    auto val = evalExpression(ctxt, exp->exp_);
    if (!val.ty.isStruct()) {
        throw CodeError("Can only use dot (.) accessor on structs", exp->line_number);
    }

    return val.ty.asStruct()->accessor(ctxt.ev()->conns(), val.val, exp->id_);
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
ValTy evalBinOp(const Context& ctxt,
                             Exp* exp,
                             Exp* exp1, Exp* exp2) {
    auto a = Expression::evalExpression(ctxt, exp1);
    auto b = Expression::evalExpression(ctxt, exp2);
    InputPort* ain;
    ValTy aout;
    Create c;
    c(exp, a, b, ain, aout); 
    ctxt.ev()->connect(a.val, ain->join(*ctxt.ev()->conns(), 0));
    ctxt.ev()->connect(b.val, ain->join(*ctxt.ev()->conns(), 1));
    return aout;
}

ValTy Expression::eval(const Context& ctxt, EPlus* exp) {
    return evalBinOp<CreateOpVec<IntAddition>>(
        ctxt, exp, exp->exp_1, exp->exp_2);
}

ValTy Expression::eval(const Context& ctxt, EMinus* exp) {
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
ValTy Expression::eval(const Context& ctxt, EDiv* exp) {
    return evalBinOp<CreateDivide>(
        ctxt, exp, exp->exp_1, exp->exp_2);
}
ValTy Expression::eval(const Context& ctxt, ETimes* exp) {
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

ValTy Expression::eval(const Context& ctxt, ELt* exp) {
    return evalBinOp<CreateCompare<llpm::IntCompare::GT>>(
        ctxt, exp, exp->exp_2, exp->exp_1);
}
ValTy Expression::eval(const Context& ctxt, EGt* exp) {
    return evalBinOp<CreateCompare<llpm::IntCompare::GT>>(
        ctxt, exp, exp->exp_1, exp->exp_2);
}
ValTy Expression::eval(const Context& ctxt, ELtEq* exp) {
    return evalBinOp<CreateCompare<llpm::IntCompare::GTE>>(
        ctxt, exp, exp->exp_2, exp->exp_1);
}
ValTy Expression::eval(const Context& ctxt, EGtEq* exp) {
    return evalBinOp<CreateCompare<llpm::IntCompare::GTE>>(
        ctxt, exp, exp->exp_1, exp->exp_2);
}
ValTy Expression::eval(const Context& ctxt, EEq* exp) {
    return evalBinOp<CreateCompare<llpm::IntCompare::EQ>>(
        ctxt, exp, exp->exp_1, exp->exp_2);
}
ValTy Expression::eval(const Context& ctxt, ENEq* exp) {
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

ValTy Expression::eval(const Context& ctxt, EAnd* exp) {
    return evalBinOp<CreateBitwise<Bitwise::AND>>(
        ctxt, exp, exp->exp_1, exp->exp_2);
}
ValTy Expression::eval(const Context& ctxt, EOr* exp) {
    return evalBinOp<CreateBitwise<Bitwise::OR>>(
        ctxt, exp, exp->exp_1, exp->exp_2);
}

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

/**
 * Automatically truncate or extend ints to make ports match. This is done in
 * pushes and assignments automatically and without warning.
 */
OutputPort* Expression::truncOrExtend(
        const Context& ctxt, OutputPort* op, llvm::Type* ty) {
    if (ty->isIntegerTy() && op->type()->isIntegerTy() &&
            ty->getIntegerBitWidth() != op->type()->getIntegerBitWidth()) {
        int diff = ty->getIntegerBitWidth() - op->type()->getIntegerBitWidth();
        Function* func = nullptr;
        if (diff > 0) {
            func = new IntExtend((unsigned)diff, false, op->type());
        } else {
            func = new IntTruncate((unsigned)(diff * -1), op->type());
        }
        ctxt.conns()->connect(op, func->din());
        return func->dout();
    } else {
        return op;
    }
}

ValTy Expression::truncOrExtend(
        const Context& ctxt, ValTy val, Type ty) {
    auto newOp = truncOrExtend(ctxt, val.val, ty.llvm());
    if (newOp == val.val)
        return val;
    return ValTy(newOp, ty);
}
} // namespace spatialc 
