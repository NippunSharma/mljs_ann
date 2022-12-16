#ifndef EMBIND_LAYERS_LINEAR_REGISTER_HPP
#define EMBIND_LAYERS_LINEAR_REGISTER_HPP

#include "access.hpp"

#define REGISTER_LAYER_LINEAR(name) \
        class_<mlpack::Linear>(name) \
        .constructor<const size_t> () \
        ;

#endif // EMBIND_LAYERS_LINEAR_REGISTER_HPP
