`@ml.js/ann` is a library powered my `mlpack` that can run

neural networks right in the browser. It uses emscripten to

compile the c++ codebase of mlpack to WebAssembly.

#### Install (via npm).

```bash
npm install "@ml.js/ann"
```

#### Basic Usage.

```typescript
import { mljsInit } from "@ml.js/core";
import { Matrix } from "@ml.js/linalg";
import { FFN, Linear, MSELoss, ConstInit, ReLU, Adam } from "@ml.js/ann";

mljsInit().then(() => {
  const trainX = new Matrix<number>({ n_rows: 1, n_cols: 5 }, "double"); // currently ann only supports double matrices.
  const trainY = new Matrix<number>({ n_rows: 1, n_cols: 5 }, "double");
  trainX.fromArray([0, 1, 2, 3, 4]);
  trainY.fromArray([0, 1, 2, 3, 4]);

  const model = new FFN<MSELoss, ConstInit>(new MSELoss, new ConstInit(2.5)); // create FFN instance.
  model.Add<Linear>(new Linear(2)); // add a linear layer, currently regularization is not supported.
  model.Add<ReLU>(new ReLU());
  model.Add<Linear>(new Linear(1));
  model.Add<ReLU>(new ReLU());

  model.Train<Adam>(trainX, trainY, new Adam()); // start training using default Adam optimizer.
  const preds = model.Predict(trainX); // predict on data.
});
```
