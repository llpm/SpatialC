#include "translate.hpp"
#include <frontend/module.hpp>
#include <frontend/event.hpp>
#include <frontend/exception.hpp>

#include <regex>

using namespace std;

namespace spatialc {

llpm::Module* Translator::translate(DefModule* modAst) {
    SpatialCModule* mod = new SpatialCModule(_design, modAst->id_);

    for (ModDef* def: *modAst->listmoddef_) {
        auto storage = dynamic_cast<DefStorage*>(def);
        if (storage != nullptr) {
            string tyName = ((TyName*)storage->type_)->id_;
            string id = storage->id_;
            auto ty = getType(tyName, mod);

            mod->addStorage(ty, id);
            continue;
        }

        auto inp = dynamic_cast<DefInput*>(def);
        if (inp != nullptr) {
            string tyName = ((TyName*)inp->type_)->id_;
            string id = inp->id_;
            auto ty = getType(tyName, mod);

            mod->addInputPort(ty, id);
            continue;
        }

        auto outp = dynamic_cast<DefOutput*>(def);
        if (outp != nullptr) {
            string tyName = ((TyName*)outp->type_)->id_;
            string id = outp->id_;
            auto ty = getType(tyName, mod);

            mod->addOutputPort(ty, id);
            continue;
        }

        auto event = dynamic_cast<DefEvent*>(def);
        if (event != nullptr) {
            auto ev = Event::create(_design, event, mod);
            mod->addEvent(ev);

            continue;
        }

        assert(false && "Don't know how to deal with module-level def");
    }

    return mod;
}

regex intTypeNameR("u?int(\\d*)");

Type Translator::getType(string typeName, SpatialCModule* ctxt) {
    smatch rResult;
    if (regex_search(typeName, rResult, intTypeNameR)) {
        int width = 32;
        auto widthStr = rResult[1].str();
        if (widthStr.size() > 0) {
            width = atol(widthStr.c_str());
        }

        return Type(
            llvm::Type::getIntNTy(ctxt->design().context(), width));
    }

    throw SemanticError("Could not resolve type: " + typeName);
}

}
