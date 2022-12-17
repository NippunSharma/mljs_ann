#include "globalconfig.hpp"

#include <emscripten/bind.h>
using namespace emscripten;

#include "losses/binary_cross_entropy/register.hpp"
#include "losses/mean_squared_error/register.hpp"
#include "losses/negative_log_likelihood/register.hpp"

#include "inits/const_init/register.hpp"
#include "inits/glorot_init/register.hpp"

#include "layers/layer/register.hpp"
#include "layers/linear/register.hpp"
#include "layers/log_softmax/register.hpp"
#include "layers/relu/register.hpp"
#include "layers/dropout/register.hpp"
#include "layers/custom_layer/register.hpp"

#include "optimizers/adam/register.hpp"

#include "ffn/register.hpp"

#include <functional>

EMSCRIPTEN_BINDINGS(mljs_ann) {

  class_<std::function<arma::mat(const arma::mat&, arma::mat&)>>("forward_func_type")
    .constructor<> ();

  class_<std::function<arma::mat(const arma::mat&, const arma::mat&, arma::mat&)>>("backward_func_type")
    .constructor<> ();

  REGISTER_LOSS_BCE("loss_bce")
  REGISTER_LOSS_MSE("loss_mse")
  REGISTER_LOSS_NLL("loss_nll")

  REGISTER_INIT_CONST_INIT("init_const_init")
  REGISTER_INIT_GLOROT_INIT("init_glorot_init")

  REGISTER_LAYER_LINEAR("layer_linear")
  REGISTER_LAYER_LOG_SOFTMAX("layer_log_softmax")
  REGISTER_LAYER_RELU("layer_relu")
  REGISTER_LAYER_DROPOUT("layer_dropout")
  REGISTER_LAYER_CUSTOM_LAYER("layer_custom_layer")

  REGISTER_OPT_ADAM("opt_adam")

  REGISTER_FFN(mlpack::BCELoss, mlpack::ConstInitialization, "ffn_bce_const_init")
  REGISTER_FFN(mlpack::MeanSquaredError, mlpack::ConstInitialization, "ffn_mse_const_init")
  REGISTER_FFN(mlpack::NegativeLogLikelihood, mlpack::ConstInitialization, "ffn_nll_const_init")

  REGISTER_FFN(mlpack::BCELoss, mlpack::GlorotInitialization, "ffn_bce_glorot_init")
  REGISTER_FFN(mlpack::MeanSquaredError, mlpack::GlorotInitialization, "ffn_mse_glorot_init")
  REGISTER_FFN(mlpack::NegativeLogLikelihood, mlpack::GlorotInitialization, "ffn_nll_glorot_init")
}
