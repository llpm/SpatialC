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
class IntOrName;

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
class Vector;
class SpatialCModuleTemplate;

class Context;

class Type {
    llvm::Type*   _simple;
    Struct*       _struct;
    Array*        _array;
    Vector*       _vector;
    SpatialCModuleTemplate* _module;

public:
    Type(llvm::Type* simple) :
        _simple(simple),
        _struct(nullptr),
        _array(nullptr),
        _vector(nullptr),
        _module(nullptr)
    { }

    Type(Struct* strct) :
        _simple(nullptr),
        _struct(strct),
        _array(nullptr),
        _vector(nullptr),
        _module(nullptr)
    { }

    Type(Array* arr) :
        _simple(nullptr),
        _struct(nullptr),
        _array(arr),
        _vector(nullptr),
        _module(nullptr)
    { }

    Type(Vector* vec) :
        _simple(nullptr),
        _struct(nullptr),
        _array(nullptr),
        _vector(vec),
        _module(nullptr)
    { }

    Type(SpatialCModuleTemplate* mod) :
        _simple(nullptr),
        _struct(nullptr),
        _array(nullptr),
        _vector(nullptr),
        _module(mod)
    { }

    // Invalid type constructor
    Type() :
        _simple(nullptr),
        _struct(nullptr),
        _array(nullptr),
        _vector(nullptr),
        _module(nullptr)
    { }

    ~Type() { }
    
    /**
     * Resolve a type given a package context
     */
    static int64_t resolve(const Context* ctxt, ::IntOrName*); 
    static Type resolve(const Context* ctxt, std::string ident);
    static Type resolve(const Context* ctxt, ::Type* astType);

    llvm::Type* llvm() const;

    bool isValid() const {
        unsigned count = 0;
        if (isSimple()) count++;
        if (isArray())  count++;
        if (isVector()) count++;
        if (isStruct()) count++;
        if (isModule()) count++;
        return count == 1;
    }

    bool isSimple() const {
        return _simple != nullptr;
    }

    bool isArray() const {
        return _array != nullptr;
    }

    bool isVector() const {
        return _vector != nullptr;
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

    Vector* asVector() {
        return _vector;
    }

    SpatialCModuleTemplate* asModule() {
        return _module;
    }

    bool operator==(const Type& t) const {
        return _simple == t._simple &&
               _struct == t._struct;
    }

    bool operator!=(const Type& t) const {
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
    DEF_GET_NP(subNames);
    DEF_ARRAY_GET(subTypes);
    DEF_GET_NP(name);

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

class Vector {
    Type    _contained;
    long    _length;
public:
    Vector(Type cont, long length) :
        _contained(cont),
        _length(length)
    { }

    DEF_GET_NP(contained);
    DEF_GET_NP(length);

    llvm::Type* llvm() const;
};



} // namespace spatialc

#endif // __SPATIALC_FRONTEND_TYPE_HPP__
