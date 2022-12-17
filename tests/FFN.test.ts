import { FFN, BCELoss, MSELoss, Linear, ConstInit,
         ReLU, GlorotInit, Dropout, NLLLoss, Adam, CustomIdentity } from "../dist";

import { mljsInit } from "@ml.js/core";
import { Matrix } from "@ml.js/linalg";

before("initialize", async function() {
  await mljsInit();
});

describe('ffn', function() {
  it('ffn_init_nll_glorot_init', function() {
    const nllLoss = new NLLLoss();
    const glorotInit = new GlorotInit();
    const ffn = new FFN<NLLLoss, GlorotInit>(nllLoss, glorotInit);
  });

  it('ffn_init_mse_const_init', function() {
    const mseLoss = new MSELoss();
    const constInit = new ConstInit();
    const ffn = new FFN<MSELoss, ConstInit>(mseLoss, constInit);
  });

  it('ffn_main', function() {
    const mseLoss = new MSELoss();
    const glorotInit = new GlorotInit();
    const ffn = new FFN<MSELoss, GlorotInit>(mseLoss, glorotInit);

    ffn.Add<CustomIdentity>(new CustomIdentity());

    const trainX: Matrix<number> = new Matrix<number>({ n_rows: 1, n_cols: 5 }, "double");
    trainX.fromArray([0, 1, 2, 3, -4]);

    const trainY: Matrix<number> = new Matrix<number>({ n_rows: 1, n_cols: 5 }, "double");
    trainY.fromArray([0, 1, 2, 3, -4]);

    const opt: Adam = new Adam();
    const val = ffn.Train<Adam>(trainX, trainY, opt);
    const preds = ffn.Predict(trainX);
    console.log(preds.toString());
  });
});
