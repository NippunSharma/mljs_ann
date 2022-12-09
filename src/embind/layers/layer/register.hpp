#ifndef EMBIND_LAYERS_LAYER_REGISTER_HPP
#define EMBIND_LAYERS_LAYER_REGISTER_HPP

#include "access.hpp"

#define REGISTER_LAYER(MatType, name) \
        class_<mlpack::Layer<MatType>>(name) \
        .constructor<> () \
        ;

#endif // EMBIND_LAYERS_LAYER_REGISTER_HPP
