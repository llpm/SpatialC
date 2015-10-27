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
            string id = storage->id_;
            auto ty = mod->getType(storage->type_);

            mod->addStorage(ty, id);
            continue;
        }

        auto inp = dynamic_cast<DefInput*>(def);
        if (inp != nullptr) {
            string id = inp->id_;
            auto ty = mod->getType(inp->type_);
            if (ty.isArray())
                throw CodeError("Ports cannot be arrays", def->line_number);

            mod->addInputPort(ty, id);
            continue;
        }

        auto outp = dynamic_cast<DefOutput*>(def);
        if (outp != nullptr) {
            string id = outp->id_;
            auto ty = mod->getType(outp->type_);
            if (ty.isArray())
                throw CodeError("Ports cannot be arrays", def->line_number);

            mod->addOutputPort(ty, id);
            continue;
        }

        auto intp = dynamic_cast<DefInternal*>(def);
        if (intp != nullptr) {
            string id = intp->id_;
            auto ty = mod->getType(intp->type_);
            if (ty.isArray())
                throw CodeError("Ports cannot be arrays", def->line_number);

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
