#ifndef __SPATIALC_FRONTEND_TRANSLATE_HPP__
#define __SPATIALC_FRONTEND_TRANSLATE_HPP__

#include <llpm/design.hpp>
#include <llpm/module.hpp>
#include <frontend/package_set.hpp>
#include <frontend/module.hpp>

#include <frontend/type.hpp>

namespace spatialc {

// Fwd defs.
class SpatialCModule;

using namespace llpm;

class Translator {
    Design& _design;
    PackageSet& _packages;

public:
    Translator(Design& design, PackageSet& ps) :
        _design(design),
        _packages(ps) {
    }

    llpm::Module* translate(DefModule* mod);
};

}

#endif // __SPATIALC_FRONTEND_TRANSLATE_HPP__
