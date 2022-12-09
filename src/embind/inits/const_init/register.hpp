#ifndef EMBIND_INITS_CONST_INIT_REGISTER_HPP
#define EMBIND_INITS_CONST_INIT_REGISTER_HPP

#include "access.hpp"

#define REGISTER_INIT_CONST_INIT(name) \
        class_<mlpack::ConstInitialization>(name) \
        .constructor<const double>() \
        ;

#endif // EMBIND_INITS_CONST_INIT_REGISTER_HPP
