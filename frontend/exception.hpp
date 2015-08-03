#ifndef __SPATIALC_FRONTEND_EXCEPTION_HPP__
#define __SPATIALC_FRONTEND_EXCEPTION_HPP__

#include <llpm/exceptions.hpp>

namespace spatialc {

class SemanticError : public llpm::Exception {
public:
    SemanticError (std::string msg = "") :
        llpm::Exception("Semantic error: " + msg) { }
};

class CodeError : public llpm::Exception {
public:
    CodeError (std::string msg = "", int line_no=-1) :
        llpm::Exception(
            "Error: " + msg + " on line number: " +
            std::to_string(line_no))
    { }
};

}

#endif // __SPATIALC_FRONTEND_EXCEPTION_HPP__
