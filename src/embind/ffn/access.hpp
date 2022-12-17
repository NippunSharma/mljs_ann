#ifndef EMBIND_FFN_ACCESS_HPP
#define EMBIND_FFN_ACCESS_HPP

#include <emscripten/val.h>
using namespace emscripten;

#include <mlpack.hpp>
#include "../layers/custom_layer/custom_layer.hpp"

template<typename OutputLayerType,
         typename InitializationRuleType>
struct FFNAccess {
  template<typename LayerType>
  static bool Add(mlpack::FFN<OutputLayerType, InitializationRuleType>& self, LayerType& layer) {
    self.Add(&layer);
    return true;
  }

  static bool AddCustomLayer(mlpack::FFN<OutputLayerType, InitializationRuleType>& self,
      const val& forward_func, const val& backward_func, const val& gradient_func) {
    CustomLayer* layer = new CustomLayer();

    layer->external_Forward = [forward_func](const arma::mat& input, arma::mat& output)
      { output = forward_func(input, output).as<arma::mat>(); };
    layer->external_Backward = [backward_func](const arma::mat& input, const arma::mat& gy, arma::mat& g)
      { g = backward_func(input, gy, g).as<arma::mat>(); };
    layer->external_Gradient = [gradient_func](const arma::mat& input, const arma::mat& error, arma::mat& gradient)
      { gradient = gradient_func(input, error, gradient).as<arma::mat>(); };

    self.Add(layer);
    return true;
  }

  template<typename OptimizerType>
  static double Train(mlpack::FFN<OutputLayerType, InitializationRuleType>& self,
      arma::Mat<double> predictors, arma::Mat<double> responses, OptimizerType optimizer) {
    return self.template Train<OptimizerType>(predictors, responses, optimizer);
  }

  static arma::Mat<double> Predict(mlpack::FFN<OutputLayerType, InitializationRuleType>& self,
      arma::Mat<double> predictors, const size_t batchSize = 128) {
    arma::Mat<double> results;
    self.Predict(predictors, results, batchSize);
    return results;
  }
};

#endif // EMBIND_FFN_ACCESS_HPP
