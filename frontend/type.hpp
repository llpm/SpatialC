#ifndef __SPATIALC_FRONTEND_TYPE_HPP__
#define __SPATIALC_FRONTEND_TYPE_HPP__

#include <string>
#include <map>
#include <util/macros.hpp>
#include <llvm/IR/Type.h>
#include <llpm/ports.hpp>

// AST fwd defs
class DefStruct;
class Type;

// LLPM fwd defs
namespace llpm {
    class ConnectionDB;
    class Module;
}

namespace spatialc {

// spatialc fwd. defs.
class Package;
class Struct;
class Array;

class Type {
    llvm::Type*   _simple;
    Struct*       _struct;
    Array*        _array;
    llpm::Module* _module;

public:
    Type(llvm::Type* simple) :
        _simple(simple),
        _struct(nullptr),
        _array(nullptr),
        _module(nullptr)
    { }

    Type(Struct* strct) :
        _simple(nullptr),
        _struct(strct),
        _array(nullptr),
        _module(nullptr)
    { }

    Type(Array* arr) :
        _simple(nullptr),
        _struct(nullptr),
        _array(arr),
        _module(nullptr)
    { }

    Type(llpm::Module* mod) :
        _simple(nullptr),
        _struct(nullptr),
        _array(nullptr),
        _module(mod)
    { }

    // Invalid type constructor
    Type() :
        _simple(nullptr),
        _struct(nullptr),
        _array(nullptr),
        _module(nullptr)
    { }

    ~Type() { }
    
    /**
     * Resolve a type given a package context
     */
    static Type resolve(Package* ctxt, std::string ident);
    static Type resolve(Package* ctxt, ::Type* astType);

    llvm::Type* llvm() const;

    bool isSimple() const {
        return _simple != nullptr;
    }

    bool isArray() const {
        return _array != nullptr;
    }

    bool isStruct() const {
        return _struct != nullptr;
    }

    bool isModule() const {
        return _module != nullptr;
    }

    Struct* asStruct() {
        return _struct;
    }

    Array* asArray() {
        return _array;
    }

    llpm::Module* asModule() {
        return _module;
    }

    bool operator==(const Type& t) {
        return _simple == t._simple &&
               _struct == t._struct;
    }

    bool operator!=(const Type& t) {
        return !(*this == t);
    }
};

struct ValTy {
    llpm::OutputPort* val;
    Type ty;

    ValTy(llpm::OutputPort* val, Type ty) :
        val(val),
        ty(ty)
    { }

    ValTy(llpm::OutputPort* val) :
        val(val),
        ty(val->type())
    { }

    ValTy() { }
};

class Struct {
    Package* _package;
    std::string       _name;
    std::vector<Type> _subTypes;
    std::map<std::string, unsigned> _subNames;
    llvm::Type*       _llvm;

    void build(::DefStruct*);

public:
    Struct(llvm::Type* llvm) :
        _llvm(llvm)
    { }

    Struct(Package* pkg, DefStruct* ast);

    DEF_GET_NP(llvm); 

    llpm::OutputPort* accessor(llpm::ConnectionDB*,
                               llpm::OutputPort*,
                               std::string) const;
};

class Array {
    Type    _contained;
    long    _length;
public:
    Array(Type cont, long length) :
        _contained(cont),
        _length(length)
    { }

    DEF_GET_NP(contained);
    DEF_GET_NP(length);

    llvm::Type* llvm() const;
};



} // namespace spatialc

#endif // __SPATIALC_FRONTEND_TYPE_HPP__
