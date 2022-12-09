#include "globalconfig.hpp"

#include <mlpack.hpp>

#include <emscripten/bind.h>
using namespace emscripten;

#include "losses/binary_cross_entropy/register.hpp"
#include "inits/const_init/register.hpp"
#include "layers/layer/register.hpp"
#include "layers/linear/register.hpp"
#include "ffn/register.hpp"

EMSCRIPTEN_BINDINGS(mljs_ann) {
  REGISTER_LOSS_BCE(arma::Mat<double>, "loss_bce_mat_double")
  REGISTER_LOSS_BCE(arma::Mat<int>, "loss_bce_mat_int")

  REGISTER_INIT_CONST_INIT("init_const_init")

  REGISTER_LAYER_LINEAR(arma::Mat<double>, "layer_linear_double")
  REGISTER_LAYER_LINEAR(arma::Mat<int>, "layer_linear_int")

  REGISTER_FFN(mlpack::BCELossType<arma::Mat<double>>, mlpack::ConstInitialization, arma::Mat<double>, "ffn_bce_const_init_mat_double")
}
