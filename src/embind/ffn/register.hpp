  #ifndef EMBIND_FFN_REGISTER_HPP
  #define EMBIND_FFN_REGISTER_HPP

  #include "access.hpp"

  #define REGISTER_FFN(OutputLayerType, InitializationRuleType, name) \
          class_<mlpack::FFN<OutputLayerType, InitializationRuleType>>(name) \
          .constructor<OutputLayerType, InitializationRuleType>() \
          .function("add_linear", &FFNAccess<OutputLayerType, InitializationRuleType>::Add<mlpack::Linear>) \
          .function("add_log_softmax", &FFNAccess<OutputLayerType, InitializationRuleType>::Add<mlpack::LogSoftMax>) \
          .function("add_relu", &FFNAccess<OutputLayerType, InitializationRuleType>::Add<mlpack::ReLU>) \
          .function("add_dropout", &FFNAccess<OutputLayerType, InitializationRuleType>::Add<mlpack::Dropout>) \
          .function("add_custom_layer", &FFNAccess<OutputLayerType, InitializationRuleType>::AddCustomLayer) \
          .function("train_adam", &FFNAccess<OutputLayerType, InitializationRuleType>::Train<ens::Adam>) \
          .function("predict", &FFNAccess<OutputLayerType, InitializationRuleType>::Predict) \
          ;

  #endif // EMBIND_FFN_REGISTER_HPP
