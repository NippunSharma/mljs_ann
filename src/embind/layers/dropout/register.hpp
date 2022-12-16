#ifndef EMBIND_LAYERS_DROPOUT_REGISTER_HPP
#define EMBIND_LAYERS_DROPOUT_REGISTER_HPP

#include "access.hpp"

#define REGISTER_LAYER_DROPOUT(name) \
        class_<mlpack::Dropout>(name) \
        .constructor<const double> () \
        ;

#endif // EMBIND_LAYERS_DROPOUT_REGISTER_HPP
