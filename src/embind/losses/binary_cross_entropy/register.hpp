#ifndef EMBIND_LOSSES_BINARY_CROSS_ENTROPY_REGISTER_HPP
#define EMBIND_LOSSES_BINARY_CROSS_ENTROPY_REGISTER_HPP

#include "access.hpp"

#define REGISTER_LOSS_BCE(T, name) \
        class_<mlpack::BCELossType<T>>(name) \
        .constructor<const double, const bool>() \
        ;

#endif // EMBIND_LOSSES_BINARY_CROSS_ENTROPY_REGISTER_HPP
