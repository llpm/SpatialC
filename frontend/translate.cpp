#include "translate.hpp"
#include <frontend/module.hpp>
#include <frontend/event.hpp>
#include <frontend/exception.hpp>

using namespace std;

namespace spatialc {

llpm::Module* Translator::translate(Package* pkg, DefModule* modAst) {
    SpatialCModule* mod = new SpatialCModule(pkg, modAst->id_);

    for (ModDef* def: *modAst->listmoddef_) {
        auto storage = dynamic_cast<DefStorage*>(def);
        if (storage != nullptr) {
            string tyName = ((TyName*)storage->type_)->id_;
            string id = storage->id_;
            auto ty = mod->getType(tyName);

            mod->addStorage(ty, id);
            continue;
        }

        auto inp = dynamic_cast<DefInput*>(def);
        if (inp != nullptr) {
            string tyName = ((TyName*)inp->type_)->id_;
            string id = inp->id_;
            auto ty = mod->getType(tyName);

            mod->addInputPort(ty, id);
            continue;
        }

        auto outp = dynamic_cast<DefOutput*>(def);
        if (outp != nullptr) {
            string tyName = ((TyName*)outp->type_)->id_;
            string id = outp->id_;
            auto ty = mod->getType(tyName);

            mod->addOutputPort(ty, id);
            continue;
        }

        auto intp = dynamic_cast<DefInternal*>(def);
        if (intp != nullptr) {
            string tyName = ((TyName*)intp->type_)->id_;
            string id = intp->id_;
            auto ty = mod->getType(tyName);

            mod->addInternalPort(ty, id);
            continue;
        }

        auto event = dynamic_cast<DefEvent*>(def);
        if (event != nullptr) {
            auto ev = Event::create(_design, event, mod);
            mod->addEvent(ev);

            continue;
        }

        auto connection = dynamic_cast<DefConnect*>(def);
        if (connection != nullptr) {
            mod->addConnection(connection);

            continue;
        }

        assert(false && "Don't know how to deal with module-level def");
    }

    return mod;
}

}
