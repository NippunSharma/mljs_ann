#ifndef EMBIND_LOSSES_BINARY_CROSS_ENTROPY_REGISTER_HPP
#define EMBIND_LOSSES_BINARY_CROSS_ENTROPY_REGISTER_HPP

#include "access.hpp"

#define REGISTER_LOSS_BCE(name) \
        class_<mlpack::BCELoss>(name) \
        .constructor<const double, const bool>() \
        ;

#endif // EMBIND_LOSSES_BINARY_CROSS_ENTROPY_REGISTER_HPP
