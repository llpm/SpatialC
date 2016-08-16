#pragma once

#include <frontend/type.hpp>
#include <grammar/Absyn.H>

namespace spatialc {

class Context;

struct Expression {
    static ValTy evalExpression(const Context& ctxt, Exp* exp);

    static ValTy eval(const Context&, EVoid*);
    static ValTy eval(const Context&, ETrue*);
    static ValTy eval(const Context&, EFalse*);
    static ValTy eval(const Context&, EInt* exp);
    static ValTy eval(const Context&, EHex* exp);
    static ValTy eval(const Context&, EDouble* exp);
    static ValTy evalId(const Context&, std::string id);
    static ValTy eval(const Context&, EId* exp);
    static ValTy eval(const Context&, EArrAcc* exp);
    static ValTy eval(const Context&, EStructLiteral* exp);
    static ValTy eval(const Context&, EVectorLiteral* expLit);
    static ValTy eval(const Context&, EDot* exp);
    static ValTy eval(const Context&, EPlus* exp);
    static ValTy eval(const Context&, EMinus* exp);

    static ValTy eval(const Context&, EXOR* exp);
    static ValTy eval(const Context&, EShR* exp);
    static ValTy eval(const Context&, EShL* exp);
    static ValTy eval(const Context&, ERotR* exp);
    static ValTy eval(const Context&, ERotL* exp);

    static ValTy eval(const Context&, EDiv* exp);
    static ValTy eval(const Context&, ETimes* exp);
    static ValTy eval(const Context&, ELt* exp);
    static ValTy eval(const Context&, EGt* exp);
    static ValTy eval(const Context&, ELtEq* exp);
    static ValTy eval(const Context&, EGtEq* exp);
    static ValTy eval(const Context&, EEq* exp);
    static ValTy eval(const Context&, ENEq* exp);
    static ValTy eval(const Context&, EAnd* exp);
    static ValTy eval(const Context&, EOr* exp);
    static ValTy eval(const Context&, EAndB* exp);
    static ValTy eval(const Context&, EOrB* exp);
    static ValTy eval(const Context&, ENeg* exp);

    static llpm::OutputPort* truncOrExtend(
        const Context&, llpm::OutputPort* op, llvm::Type* ty);
    static ValTy truncOrExtend(
        const Context&, ValTy op, Type ty);

    static int64_t resolveToInt(const Context&, Exp* exp);
};

} // namespace spatialc


