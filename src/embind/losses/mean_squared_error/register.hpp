#ifndef EMBIND_LOSSES_MEAN_SQUARED_ERROR_REGISTER_HPP
#define EMBIND_LOSSES_MEAN_SQUARED_ERROR_REGISTER_HPP

#include "access.hpp"

#define REGISTER_LOSS_MSE(name) \
        class_<mlpack::MeanSquaredError>(name) \
        .constructor<const bool> () \
        ;

#endif // EMBIND_LOSSES_MEAN_SQUARED_ERROR_REGISTER_HPP
