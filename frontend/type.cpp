#include "type.hpp"

#include <grammar/Absyn.H>
#include <frontend/package_set.hpp>
#include <llpm/design.hpp>
#include <frontend/exception.hpp>
#include <libraries/core/comm_intr.hpp>
#include <regex>

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
            Type ty = Type::resolve(_package, ((TyName*)stor->type_)->id_);
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
    return nullptr;
}

Type Type::resolve(Package* pkg, std::string typeName) {

    // Attempt to resolve simple types
    if (typeName == "void") {
        return Type(llvm::Type::getVoidTy(pkg->design().context()));
    } else if (typeName == "bool") {
        return Type(
            llvm::Type::getIntNTy(pkg->design().context(), 1));
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
            llvm::Type::getIntNTy(pkg->design().context(), width));
    }

    // Look up types defined in the package
    Type ty;
    if (pkg->resolveNamedType(typeName, ty))
        return ty;

    throw SemanticError("Could not resolve type: " + typeName);
}

Type Type::resolve(Package* ctxt, ::Type* astType) {
    auto tyName = dynamic_cast<TyName*>(astType);
    if (tyName != nullptr) {
        return resolve(ctxt, tyName->id_);
    }

    auto tyArray = dynamic_cast<TyArray*>(astType);
    if (tyArray != nullptr) {
        auto arr = new Array(
            resolve(ctxt, tyArray->type_),
            tyArray->integer_);
        return Type(arr);
    }

    assert(false && "I don't recognize this type definition!");
}

llvm::Type* Array::llvm() const {
    return llvm::ArrayType::get(_contained.llvm(), _length);
}

} // namespace spatialc
