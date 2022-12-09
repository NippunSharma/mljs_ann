#ifndef EMBIND_FFN_REGISTER_HPP
#define EMBIND_FFN_REGISTER_HPP

#include "access.hpp"

#define REGISTER_FFN(OutputLayerType, InitializationRuleType, MatType, name) \
        class_<mlpack::FFN<OutputLayerType, InitializationRuleType, MatType>>(name) \
        .constructor<OutputLayerType, InitializationRuleType>() \
        .function("add_linear", &FFNAccess<OutputLayerType, InitializationRuleType, MatType>::Add<mlpack::LinearType<MatType>>) \
        .function("train_adam", &FFNAccess<OutputLayerType, InitializationRuleType, MatType>::Train<ens::Adam>) \
        .function("predict", &FFNAccess<OutputLayerType, InitializationRuleType, MatType>::Predict) \
        ;

#endif // EMBIND_FFN_REGISTER_HPP
