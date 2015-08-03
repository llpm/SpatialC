#ifndef __SPATIALC_FRONTEND_TYPE_HPP__
#define __SPATIALC_FRONTEND_TYPE_HPP__

#include <util/macros.hpp>
#include <llvm/IR/Type.h>

namespace spatialc {

class Struct {
    llvm::Type* _llvm;

public:
    Struct(llvm::Type* llvm) :
        _llvm(llvm)
    { }

    DEF_GET_NP(llvm); 
};

class Array {
    llvm::Type* _llvm;
    long        _length;
public:
    Array(llvm::Type* llvm, long length) :
        _llvm(llvm),
        _length(length)
    { }

    DEF_GET_NP(llvm);
    DEF_GET_NP(length);
};

class Type {
    llvm::Type* _simple;
    Struct*     _struct;
    Array*      _array;

public:
    Type(llvm::Type* simple) :
        _simple(simple),
        _struct(nullptr)
    { }

    Type(Struct* strct) :
        _simple(nullptr),
        _struct(strct)
    { }

    ~Type() { }
    

    llvm::Type* llvm() const {
        if (_simple)
            return _simple;
        if (_struct)
            return _struct->llvm();
        return nullptr;
    }

    bool isSimple() const {
        return _simple != nullptr;
    }

    bool isArray() const {
        return _array != nullptr;
    }

    bool isStruct() const {
        return _struct != nullptr;
    }

    bool operator==(const Type& t) {
        return _simple == t._simple &&
               _struct == t._struct;
    }

    bool operator!=(const Type& t) {
        return !(*this == t);
    }
};

} // namespace spatialc

#endif // __SPATIALC_FRONTEND_TYPE_HPP__
