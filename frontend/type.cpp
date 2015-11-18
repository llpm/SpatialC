#include "type.hpp"

#include <grammar/Absyn.H>
#include <frontend/package_set.hpp>
#include <frontend/context.hpp>
#include <frontend/module.hpp>
#include <frontend/event.hpp>
#include <frontend/expression.hpp>
#include <llpm/design.hpp>
#include <analysis/constant.hpp>
#include <frontend/exception.hpp>
#include <libraries/core/comm_intr.hpp>
#include <regex>
#include <analysis/constant.hpp>

using namespace std;
using namespace llpm;

namespace spatialc {

Struct::Struct(Package* pkg, ::DefStruct* ast) :
    _package(pkg) {
    build(ast);
}

void Struct::build(::DefStruct* ast) {
    _name = ast->id_; 
    for (auto def: *ast->liststructdef_) {
        auto stor = dynamic_cast<::DefSubstor*>(def);
        if (stor != nullptr) {
            Type ty = Type::resolve(_package->ctxt(), ((TyName*)stor->type_)->id_);
            _subTypes.push_back(ty);
            _subNames[stor->id_] = _subTypes.size() - 1;
            continue;
        }

        auto func = dynamic_cast<::DefSubstor*>(def);
        if (func != nullptr) {
            throw CodeError("Struct functions not yet implemented!", def->line_number);
        }

        assert(false && "Unknown struct definition");
    }

    vector<llvm::Type*> llvmVec;
    for (auto ty: _subTypes) {
        llvmVec.push_back(ty.llvm());
    }
    _llvm = llvm::StructType::get(_package->design().context(), llvmVec, true);
}

llpm::OutputPort* Struct::accessor(llpm::ConnectionDB* conns,
                                   OutputPort* value,
                                   std::string name) const {
    assert(name.find(".") == string::npos && "This function does non-recursive access only");
    assert(value->type() == _llvm && "Port type does not match my type!");
    auto idxF = _subNames.find(name);
    if (idxF == _subNames.end())
        throw SemanticError("Could not resolve struct " + _name + " subtype " + name);
    unsigned idx = idxF->second;
    return value->split(*conns)->dout(idx);
}

regex intTypeNameR("u?int(\\d*)");

llvm::Type* Type::llvm() const {
    if (_simple)
        return _simple;
    if (_struct)
        return _struct->llvm();
    if (_array)
        return _array->llvm();
    if (_vector)
        return _vector->llvm();
    return nullptr;
}

int64_t Type::resolve(const Context* ctxt, ::IntOrName* ion) {
    auto intVal = dynamic_cast<::Int*>(ion);
    if (intVal != nullptr) {
        return intVal->integer_;
    }

    auto nameVal = dynamic_cast<::ConstName*>(ion);
    if (nameVal != nullptr) {
        auto var = ctxt->find(nameVal->id_);
        if (var == nullptr)
            throw CodeError("Could not resolve '" +
                            nameVal->id_ + "'", ion->line_number);
        ConnectionDB* conns = nullptr;
        if (ctxt->ev() != nullptr)
            conns = ctxt->ev()->conns();
        if (ctxt->mod() != nullptr)
            conns = ctxt->mod()->conns();

        auto c = var->constant;
        if (c == nullptr)
            c = llpm::EvalConstant(conns, var->op);

        if (c == nullptr) {
            throw CodeError("Could not resolve to compile-time value",
                            ion->line_number);
        }

        if (!c->getType()->isIntegerTy()) {
            throw CodeError("Must resolve to compile-time integer!",
                            ion->line_number);
        }

        return c->getUniqueInteger().getLimitedValue();
    }

    assert(false && "Don't yet know how to decode const value");
}

Type Type::resolve(const Context* ctxt, std::string typeName) {

    // Attempt to resolve simple types
    if (typeName == "void") {
        return Type(llvm::Type::getVoidTy(ctxt->llvmCtxt()));
    } else if (typeName == "bool") {
        return Type(
            llvm::Type::getIntNTy(ctxt->llvmCtxt(), 1));
    }

    // Resolve integer types with a regex
    smatch rResult;
    if (regex_search(typeName, rResult, intTypeNameR)) {
        int width = 32;
        auto widthStr = rResult[1].str();
        if (widthStr.size() > 0) {
            width = atol(widthStr.c_str());
        }

        return Type(
            llvm::Type::getIntNTy(ctxt->llvmCtxt(), width));
    }

    // check context for metaprogrammed type
    auto var = ctxt->find(typeName);
    if (var != nullptr) {
        if (var->op == nullptr && var->constant == nullptr)
            return var->ty;
    }

    // Look up types defined in the package
    Type ty;
    if (ctxt->pkg()->resolveNamedType(typeName, ty))
        return ty;

    throw SemanticError("Could not resolve type: " + typeName);
}

Type Type::resolve(const Context* ctxt, ::Type* astType) {
    auto tyName = dynamic_cast<TyName*>(astType);
    if (tyName != nullptr) {
        return resolve(ctxt, tyName->id_);
    }

    auto tyNameParam = dynamic_cast<TyNameParams*>(astType);
    if (tyNameParam != nullptr) {
        Type ty;
        if (!ctxt->pkg()->resolveNamedType(tyNameParam->id_, ty)) {
            throw CodeError("Could not resolve type name " +
                            tyNameParam->id_, tyNameParam->line_number);
        }

        if (ty.isModule()) {
            map<string, Variable> args;
            for (auto argA: *tyNameParam->listtemplatearg_) {
                auto arg = dynamic_cast<TemplateArg1*>(argA);
                assert(arg != nullptr);

                auto teConst = dynamic_cast<TEConstExp*>(arg->templateexp_);
                if (teConst != nullptr) {
                    auto exp = Expression::evalExpression(*ctxt, teConst->exp_);
                    auto c = llpm::EvalConstant(ctxt->conns(), exp.val);
                    if (c == nullptr) {
                        throw CodeError("Could not resolve argument to constant",
                                        arg->line_number);
                    }
                    Variable v(Type(c->getType()),
                               nullptr,
                               arg->id_,
                               c);
                    args.insert(make_pair(arg->id_, v));
                    continue;
                }

                auto teType = dynamic_cast<TEType*>(arg->templateexp_);
                if (teType != nullptr) {
                    auto ty = resolve(ctxt, teType->type_);
                    Variable v(ty, nullptr, arg->id_, nullptr);
                    args.insert(make_pair(arg->id_, v));
                    continue;
                }

                assert(false && "Cannot evaluate template argument");

            }
            return Type(ty.asModule()->args(args));
        }

        throw CodeError("I don't know how to apply type parameters to this type!",
                        tyNameParam->line_number);
    }

    auto tyArray = dynamic_cast<TyArray*>(astType);
    if (tyArray != nullptr) {
        auto arr = new Array(
            resolve(ctxt, tyArray->type_),
            resolve(ctxt, tyArray->intorname_));
        return Type(arr);
    }

    auto tyVector = dynamic_cast<TyVector*>(astType);
    if (tyVector != nullptr) {
        auto vec = new Vector(
            resolve(ctxt, tyVector->type_),
            resolve(ctxt, tyVector->intorname_));
        return Type(vec);
    }

    auto tyVoid = dynamic_cast<TyVoid*>(astType);
    if (tyVoid != nullptr) {
        return Type(llvm::Type::getVoidTy(ctxt->llvmCtxt()));
    }

    auto tyType = dynamic_cast<TyType*>(astType);
    if (tyType != nullptr) {
        return Type::type();
    }

    assert(false && "I don't recognize this type definition!");
}

llvm::Type* Array::llvm() const {
    return llvm::ArrayType::get(_contained.llvm(), _length);
}

llvm::Type* Vector::llvm() const {
    return llvm::VectorType::get(_contained.llvm(), _length);
}

} // namespace spatialc
