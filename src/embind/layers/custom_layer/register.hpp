#ifndef EMBIND_LAYERS_CUSTOM_LAYER_REGISTER_HPP
#define EMBIND_LAYERS_CUSTOM_LAYER_REGISTER_HPP

#include "access.hpp"

#define REGISTER_LAYER_CUSTOM_LAYER(name) \
        class_<CustomLayer>(name) \
        .constructor<> () \
        ;

#endif // EMBIND_LAYERS_CUSTOM_LAYER_REGISTER_HPP
