#ifndef EMBIND_FFN_ACCESS_HPP
#define EMBIND_FFN_ACCESS_HPP

#include <emscripten/val.h>
using namespace emscripten;

#include <mlpack.hpp>

template<typename OutputLayerType,
         typename InitializationRuleType,
         typename MatType>
struct FFNAccess {
  template<typename LayerType>
  static bool Add(mlpack::FFN<OutputLayerType, InitializationRuleType, MatType>& self, LayerType& layer) {
    self.Add(&layer);
    return true;
  }

  template<typename OptimizerType>
  typename MatType::elem_type Train(mlpack::FFN<OutputLayerType, InitializationRuleType, MatType>& self, 
      MatType predictors, MatType responses, OptimizerType& optimizer) {
    return self.template Train<OptimizerType>(predictors, responses, optimizer);
  }

  MatType Predict(mlpack::FFN<OutputLayerType, InitializationRuleType, MatType>& self,
      MatType predictors, const size_t batchSize = 128) {
    MatType results;
    self.Predict(predictors, results, batchSize);
    return results;
  }
};

#endif // EMBIND_FFN_ACCESS_HPP
