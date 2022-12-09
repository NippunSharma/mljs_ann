#ifndef EMBIND_OPTIMIZERS_ADAM_REGISTER_HPP
#define EMBIND_OPTIMIZERS_ADAM_REGISTER_HPP

#include "access.hpp"

#define REGISTER_OPT_ADAM(name) \
        class_<ens::AdamType>(name) \
        .constructor<const double, const size_t, const double, const double, const double, const size_t, const double, const bool, const bool, const bool> () \
        ;

#endif // EMBIND_OPTIMIZERS_ADAM_REGISTER_HPP
