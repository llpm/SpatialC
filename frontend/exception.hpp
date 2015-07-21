#ifndef __SPATIALC_FRONTEND_EXCEPTION_HPP__
#define __SPATIALC_FRONTEND_EXCEPTION_HPP__

#include <llpm/exceptions.hpp>

namespace spatialc {

class SemanticError : public llpm::Exception {
public:
    SemanticError (std::string msg = "") :
        llpm::Exception("Semantic error: " + msg) { }
};

}

#endif // __SPATIALC_FRONTEND_EXCEPTION_HPP__
