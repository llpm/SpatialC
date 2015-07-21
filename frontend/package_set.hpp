#ifndef __SPATIALC_FRONTEND_PACKAGE_SET_HPP__
#define __SPATIALC_FRONTEND_PACKAGE_SET_HPP__

#include <string>
#include <vector>
#include <map>
#include <grammar/Absyn.H>
#include <util/search_path.hpp>

namespace spatialc {

class PackageSet {
    SearchPath _paths;

    std::map<std::string, Package*> _packages;
    std::map<std::string, DefModule*> _modules;
    std::map<std::string, DefStruct*> _structs;

    void addPackage(std::string pkgName, Package* pkg);

public:
    PackageSet(std::vector<std::string> inclDirs = {}) :
        _paths(inclDirs) {
    }

    ~PackageSet() {
    }

    void appendIncludeDir(std::string inclDir) {
        _paths.appendPath(inclDir);
    }

    Package* getPackage(std::string pkgName);
    DefModule* getModule(std::string moduleName);

    static void splitName(std::string fqName,
                          std::string& package,
                          std::string& obj);
    static std::string joinName(std::vector<std::string>);
    static std::string joinName(std::vector<PackageName*>);
};

}

#endif // __SPATIALC_FRONTEND_PACKAGE_SET_HPP__
