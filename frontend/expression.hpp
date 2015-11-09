#ifndef __SPATIALC_FRONTEND_EXPRESSION_HPP__
#define __SPATIALC_FRONTEND_EXPRESSION_HPP__

#include <frontend/type.hpp>
#include <grammar/Absyn.H>

namespace spatialc {

class Context;

struct Expression {
    static ValTy evalExpression(const Context& ctxt, Exp* exp);

    static ValTy eval(const Context& ctxt, ETrue*);
    static ValTy eval(const Context& ctxt, EFalse*);
    static ValTy eval(const Context& ctxt, EInt* exp);
    static ValTy eval(const Context& ctxt, EDouble* exp);
    static ValTy evalId(const Context& ctxt, std::string id);
    static ValTy eval(const Context& ctxt, EId* exp);
    static ValTy eval(const Context& ctxt, EArrAcc* exp);
    static ValTy eval(const Context& ctxt, EStructLiteral* exp);
    static ValTy eval(const Context& ctxt, EVectorLiteral* expLit);
    static ValTy eval(const Context& ctxt, EDot* exp);
    static ValTy eval(const Context& ctxt, EPlus* exp);
    static ValTy eval(const Context& ctxt, EMinus* exp);
    static ValTy eval(const Context& ctxt, EDiv* exp);
    static ValTy eval(const Context& ctxt, ETimes* exp);
    static ValTy eval(const Context& ctxt, ELt* exp);
    static ValTy eval(const Context& ctxt, EGt* exp);
    static ValTy eval(const Context& ctxt, ELtEq* exp);
    static ValTy eval(const Context& ctxt, EGtEq* exp);
    static ValTy eval(const Context& ctxt, EEq* exp);
    static ValTy eval(const Context& ctxt, ENEq* exp);
    static ValTy eval(const Context& ctxt, EAnd* exp);
    static ValTy eval(const Context& ctxt, EOr* exp);
};

} // namespace spatialc

#endif // __SPATIALC_FRONTEND_EXPRESSION_HPP__

