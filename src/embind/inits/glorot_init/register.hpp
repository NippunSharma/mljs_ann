#ifndef EMBIND_INITS_GLOROT_INIT_REGISTER_HPP
#define EMBIND_INITS_GLOROT_INIT_REGISTER_HPP

#include "access.hpp"

#define REGISTER_INIT_GLOROT_INIT(name) \
        class_<mlpack::GlorotInitialization>(name) \
        .constructor<> () \
        ;

#endif // EMBIND_INITS_GLOROT_INIT_REGISTER_HPP
