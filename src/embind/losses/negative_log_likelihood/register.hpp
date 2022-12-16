#ifndef EMBIND_LOSSES_NEGATIVE_LOG_LIKELIHOOD_REGISTER_HPP
#define EMBIND_LOSSES_NEGATIVE_LOG_LIKELIHOOD_REGISTER_HPP

#include "access.hpp"

#define REGISTER_LOSS_NLL(name) \
        class_<mlpack::NegativeLogLikelihood>(name) \
        .constructor<> () \
        ;

#endif // EMBIND_LOSSES_NEGATIVE_LOG_LIKELIHOOD_REGISTER_HPP
