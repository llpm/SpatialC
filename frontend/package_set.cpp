#include "package_set.hpp"

#include <cassert>
#include <frontend/exception.hpp>
#include "grammar/Parser.H"
#include "grammar/Printer.H"

using namespace std;

namespace spatialc {

void PackageSet::addPackage(std::string pkgName, Package* pkgAst) {
    printf("\n[Abstract Syntax]\n");
    ShowAbsyn *s = new ShowAbsyn();
    printf("%s\n\n", s->show(pkgAst));

    PDefs* pdefs = dynamic_cast<PDefs*>(pkgAst);
    assert(pdefs != nullptr);
    auto list = pdefs->listdef_;
    for (Def* def: *list) {
        auto defPackage = dynamic_cast<DefPackage*>(def);
        if (defPackage != nullptr) {
            string defPkgName = joinName(*defPackage->listpackagename_);
            if (defPkgName != pkgName) {
                throw SemanticError(
                    "Declared package (" + defPkgName +
                    ") does not match path (" + pkgName + ")");
            }
        }

        auto defModule = dynamic_cast<DefModule*>(def);
        if (defModule != nullptr) {
            _modules[pkgName + "." + defModule->id_] = defModule;
        }

        auto defStruct = dynamic_cast<DefStruct*>(def);
        if (defStruct != nullptr) {
            _structs[pkgName + "." + defStruct->id_] = defStruct;
        }
    }
    _packages[pkgName] = pkgAst;
}

Package* PackageSet::getPackage(std::string pkgName) {
    auto f = _packages.find(pkgName);
    if (f != _packages.end()) {
        return f->second;
    }

    string pkgFn = pkgName;
    for (size_t i=0; i<pkgFn.size(); i++) {
        if (pkgFn[i] == '.')
            pkgFn[i] = '/';
    }
    pkgFn = pkgFn + ".sc";
    FILE* pkgFile = _paths.open(pkgFn, "r");
    if (pkgFile == nullptr)
        return nullptr;

    Package* pkgAst = pPackage(pkgFile);
    fclose(pkgFile);
    if (pkgAst) {
      addPackage(pkgName, pkgAst);
      return pkgAst;
    } else {
        return nullptr;
    }
}

DefModule* PackageSet::getModule(std::string fqModuleName) {
    string pkgName, modName;
    splitName(fqModuleName, pkgName, modName);

    // Make sure the package has been read
    getPackage(pkgName);

    auto f = _modules.find(fqModuleName);
    if (f == _modules.end()) {
        return nullptr;
    }
    return f->second;
}

void PackageSet::splitName(string fqName,
                           string& package,
                           string& obj)
{
    auto lastDot = fqName.rfind(".");
    if (lastDot == string::npos) {
        package = "";
        obj = fqName;
        return;
    }
    package = fqName.substr(0, lastDot);
    obj = fqName.substr(lastDot+1);
    printf("%s: %s, %s\n", fqName.c_str(), package.c_str(), obj.c_str());
}

string PackageSet::joinName(vector<string> parts) {
    string ret;
    bool fst = true;
    for (auto p: parts) {
        if (fst) {
            ret += p;
            fst = false;
        } else {
            ret += "." + p;
        }
    }
    return ret;
}

string PackageSet::joinName(vector<PackageName*> parts) {
    string ret;
    bool fst = true;
    for (auto p: parts) {
        if (fst) {
            ret += ((PackageNameId*)p)->id_;
            fst = false;
        } else {
            ret += "." + ((PackageNameId*)p)->id_;
        }
    }
    return ret;
}

}
