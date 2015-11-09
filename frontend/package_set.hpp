#ifndef __SPATIALC_FRONTEND_PACKAGE_SET_HPP__
#define __SPATIALC_FRONTEND_PACKAGE_SET_HPP__

#include <string>
#include <vector>
#include <map>
#include <set>
#include <grammar/Absyn.H>
#include <util/search_path.hpp>
#include <frontend/type.hpp>
#include <frontend/context.hpp>

// LLPM fwd. defs
namespace llpm {
    class Design;
    class Module;
}

namespace spatialc {

class Package;
class SpatialCModule;
class SpatialCModuleTemplate;

class PackageSet {
    llpm::Design& _design;
    SearchPath  _paths;

    std::map<std::string, ::Package*> _packageASTs;
    std::map<std::string, Package*> _packages;

    void addPackageAST(std::string pkgName, ::Package* pkg);

public:
    PackageSet(llpm::Design& design,
               std::vector<std::string> inclDirs = {});

    ~PackageSet() {
    }

    DEF_GET_NP(design);

    void appendIncludeDir(std::string inclDir) {
        _paths.appendPath(inclDir);
    }

    ::Package* getPackageAST(std::string pkgName);
    ::DefModule* getModuleAST(std::string fqModuleName);

    Package* getPackage(std::string pkgName);
    llpm::Module* instantiateModule(std::string fqName);

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
    std::map<std::string, SpatialCModuleTemplate*> _moduleTemplates;
    std::map<std::string, std::set<SpatialCModule*>> _modules;

    std::set<Package*>             _imports;
    Context _ctxt;

    void lazyBuild(::Package* pkg);
    void translateStruct(::DefStruct* ast);

public:
    Package(std::string name, PackageSet* ps) :
        _name(name),
        _set(ps),
        _ctxt(nullptr, this)
    { }

    virtual ~Package() { }

    DEF_GET_NP(set);
    DEF_GET_NP(name);
    DEF_GET(ctxt);
    llpm::Design& design();

    bool findTypeLocal(std::string typeName, Type& ty);
    bool resolveNamedType(std::string typeName, Type& ty);

    ::DefModule*  getModuleAST(std::string moduleName);
    SpatialCModuleTemplate* getModule(std::string moduleName);
    llpm::Module* instantiateModule(std::string moduleName,
                                    std::map<std::string, Variable> args = {});
};

}

#endif // __SPATIALC_FRONTEND_PACKAGE_SET_HPP__
