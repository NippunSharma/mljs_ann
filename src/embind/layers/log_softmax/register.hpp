#ifndef EMBIND_LAYERS_LOG_SOFTMAX_REGISTER_HPP
#define EMBIND_LAYERS_LOG_SOFTMAX_REGISTER_HPP

#include "access.hpp"

#define REGISTER_LAYER_LOG_SOFTMAX(name) \
        class_<mlpack::LogSoftMax>(name) \
        .constructor<> () \
        ;

#endif // EMBIND_LAYERS_LOG_SOFTMAX_REGISTER_HPP
