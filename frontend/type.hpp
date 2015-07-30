#ifndef __SPATIALC_FRONTEND_TYPE_HPP__
#define __SPATIALC_FRONTEND_TYPE_HPP__

#include <llvm/IR/Type.h>

namespace spatialc {

class Struct {
    llvm::Type* _llvm;

public:
    llvm::Type* llvm() {
        return _llvm;
    }
};

class Type {
    llvm::Type* _simple;
    Struct*     _struct;

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
    

    llvm::Type* llvm() {
        if (_simple)
            return _simple;
        return _struct->llvm();
    }
};

} // namespace spatialc

#endif // __SPATIALC_FRONTEND_TYPE_HPP__
