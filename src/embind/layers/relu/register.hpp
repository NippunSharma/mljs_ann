#ifndef EMBIND_LAYERS_RELU_REGISTER_HPP
#define EMBIND_LAYERS_RELU_REGISTER_HPP

#include "access.hpp"

#define REGISTER_LAYER_RELU(name) \
        class_<mlpack::ReLU>(name) \
        .constructor<> () \
        ;

#endif // EMBIND_LAYERS_RELU_REGISTER_HPP
