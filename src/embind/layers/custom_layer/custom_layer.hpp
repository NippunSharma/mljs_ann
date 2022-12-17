#ifndef EMBIND_LAYERS_CUSTOM_LAYER_CUSTOM_LAYER_HPP
#define EMBIND_LAYERS_CUSTOM_LAYER_CUSTOM_LAYER_HPP

#include <mlpack.hpp>
#include <functional>
#include <iostream>

class CustomLayer : public mlpack::Layer<arma::mat> {
public:
  CustomLayer() {
    // Nothing to do.
  }

  virtual ~CustomLayer() {
    // Nothing to do.
  }

  void Forward(const arma::mat& input, arma::mat& output) {
    return external_Forward(input, output);
  }

  void Backward(const arma::mat& input, const arma::mat& gy, arma::mat& g) {
    return external_Backward(input, gy, g);
  }

  void Gradient(const arma::mat& input, const arma::mat& error, arma::mat& gradient) {
    return external_Gradient(input, error, gradient);
  }

  CustomLayer* Clone() const {
    CustomLayer* newLayer = new CustomLayer();
    newLayer->external_Forward = external_Forward;
    newLayer->external_Backward = external_Backward;
    newLayer->external_Gradient = external_Gradient;
    return newLayer;
  }

  std::function<void(const arma::mat&, arma::mat&)> external_Forward;
  std::function<void(const arma::mat&, const arma::mat&, arma::mat&)> external_Backward;
  std::function<void(const arma::mat&, const arma::mat&, arma::mat&)> external_Gradient;
};

#endif // EMBIND_LAYERS_CUSTOM_LAYER_CUSTOM_LAYER_HPP
