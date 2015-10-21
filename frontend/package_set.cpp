#include "package_set.hpp"

#include <cassert>
#include <frontend/type.hpp>
#include <frontend/exception.hpp>
#include <frontend/translate.hpp>
#include "grammar/Parser.H"
#include "grammar/Printer.H"

using namespace std;

namespace spatialc {

PackageSet::PackageSet(llpm::Design& design, vector<string> inclDirs):
    _trans(new Translator(design, *this)),
    _paths(inclDirs)
{ }

void PackageSet::addPackageAST(std::string pkgName, ::Package* pkgAst) {
    _packageASTs[pkgName] = pkgAst;
    auto pkg = new Package(pkgName, this);
    pkg->lazyBuild(pkgAst);
    _packages[pkgName] = pkg;
}

::Package* PackageSet::getPackageAST(std::string pkgName) {
    auto f = _packageASTs.find(pkgName);
    if (f != _packageASTs.end()) {
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

    ::Package* pkgAst = pPackage(pkgFile);
    fclose(pkgFile);
    if (pkgAst) {
      addPackageAST(pkgName, pkgAst);
      return pkgAst;
    } else {
        return nullptr;
    }
}

::DefModule* PackageSet::getModuleAST(std::string fqModuleName) {
    string pkgName, modName;
    splitName(fqModuleName, pkgName, modName);

    // Make sure the package has been read
    auto pkg = getPackage(pkgName);
    if (pkg == nullptr)
        return nullptr;
    return pkg->getModuleAST(modName);
}

Package* PackageSet::getPackage(std::string pkgName) {
    ::Package* pkgast = getPackageAST(pkgName);
    if (pkgast == nullptr) {
        return nullptr;
    }
    assert(_packages.count(pkgName) > 0);
    return _packages.find(pkgName)->second;
}

llpm::Module* PackageSet::getModule(std::string fqName) {
    string pkgName, obj;
    splitName(fqName, pkgName, obj);
    Package* pkg = getPackage(pkgName);
    if (pkg == nullptr)
        return nullptr;
    return pkg->getModule(obj);
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

void Package::translateStruct(::DefStruct* ast) {
    auto s = new Struct(ast);
    _structs[ast->id_] = s;
}

void Package::lazyBuild(::Package* pkgAst) {
    printf("\n[Abstract Syntax]\n");
    ShowAbsyn *s = new ShowAbsyn();
    printf("%s\n\n", s->show(pkgAst));

    PDefs* pdefs = dynamic_cast<PDefs*>(pkgAst);
    assert(pdefs != nullptr);
    auto list = pdefs->listdef_;
    for (Def* def: *list) {
        auto defPackage = dynamic_cast<DefPackage*>(def);
        if (defPackage != nullptr) {
            string defPkgName = PackageSet::joinName(*defPackage->listpackagename_);
            if (defPkgName != _name) {
                throw SemanticError(
                    "Declared package (" + defPkgName +
                    ") does not match path (" + _name + ")");
            }
        }

        auto defModule = dynamic_cast<DefModule*>(def);
        if (defModule != nullptr) {
            _moduleASTs[defModule->id_] = defModule;
        }

        auto defStruct = dynamic_cast<DefStruct*>(def);
        if (defStruct != nullptr) {
            _structASTs[defStruct->id_] = defStruct;
            translateStruct(defStruct);
        }
    }
}


::DefModule* Package::getModuleAST(std::string moduleName) {
    auto f = _moduleASTs.find(moduleName);
    if (f == _moduleASTs.end())
        return nullptr;
    return f->second;
}

llpm::Module* Package::getModule(std::string moduleName) {
    auto f = _modules.find(moduleName);
    if (f != _modules.end())
        return f->second;
    auto ast = getModuleAST(moduleName);
    if (ast == nullptr)
        return nullptr;
    auto mod = _set->trans()->translate(this, ast);
    _modules[moduleName] = mod;
    return mod;
}

}
