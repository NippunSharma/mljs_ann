#ifndef EMBIND_LAYERS_LINEAR_REGISTER_HPP
#define EMBIND_LAYERS_LINEAR_REGISTER_HPP

#include "access.hpp"

#define REGISTER_LAYER_LINEAR(MatType, name) \
        class_<mlpack::LinearType<MatType>>(name) \
        .constructor<const size_t> () \
        ;

#endif // EMBIND_LAYERS_LINEAR_REGISTER_HPP
