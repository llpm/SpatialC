#ifndef __SPATIALC_FRONTEND_PACKAGE_SET_HPP__
#define __SPATIALC_FRONTEND_PACKAGE_SET_HPP__

#include <string>
#include <vector>
#include <map>
#include <set>
#include <grammar/Absyn.H>
#include <util/search_path.hpp>
#include <frontend/type.hpp>

// LLPM fwd. defs
namespace llpm {
    class Design;
    class Module;
}

namespace spatialc {

class Package;
class Module;
class Translator;

class PackageSet {
    Translator* _trans;
    SearchPath  _paths;

    std::map<std::string, ::Package*> _packageASTs;


    std::map<std::string, Package*> _packages;

    void addPackageAST(std::string pkgName, ::Package* pkg);

public:
    PackageSet(llpm::Design& design,
               std::vector<std::string> inclDirs = {});

    ~PackageSet() {
    }

    DEF_GET_NP(trans);

    void appendIncludeDir(std::string inclDir) {
        _paths.appendPath(inclDir);
    }

    ::Package* getPackageAST(std::string pkgName);
    ::DefModule* getModuleAST(std::string fqModuleName);

    Package* getPackage(std::string pkgName);
    llpm::Module* getModule(std::string fqName);

    static void splitName(std::string fqName,
                          std::string& package,
                          std::string& obj);
    static std::string joinName(std::vector<std::string>);
    static std::string joinName(std::vector<PackageName*>);
};


class Package {
    friend class PackageSet;

    std::string _name;
    PackageSet* _set;

    std::map<std::string, ::DefModule*> _moduleASTs;
    std::map<std::string, ::DefStruct*> _structASTs;

    std::map<std::string, Struct*> _structs;
    std::map<std::string, llpm::Module*> _modules;

    std::set<Package*>             _imports;

    void lazyBuild(::Package* pkg);
    void translateStruct(::DefStruct* ast);

public:
    Package(std::string name, PackageSet* ps) :
        _name(name),
        _set(ps)
    { }

    virtual ~Package() { }

    DEF_GET_NP(set);
    DEF_GET_NP(name);
    llpm::Design& design();

    bool findTypeLocal(std::string typeName, Type& ty);
    bool resolveNamedType(std::string typeName, Type& ty);

    ::DefModule*  getModuleAST(std::string moduleName);
    llpm::Module* getModule(std::string moduleName);
};

}

#endif // __SPATIALC_FRONTEND_PACKAGE_SET_HPP__
