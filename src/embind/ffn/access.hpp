#ifndef EMBIND_FFN_ACCESS_HPP
#define EMBIND_FFN_ACCESS_HPP

#include <emscripten/val.h>
using namespace emscripten;

#include <mlpack.hpp>

template<typename OutputLayerType,
         typename InitializationRuleType>
struct FFNAccess {
  template<typename LayerType>
  static bool Add(mlpack::FFN<OutputLayerType, InitializationRuleType>& self, LayerType& layer) {
    self.Add(&layer);
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
