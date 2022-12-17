import { CustomLayer, ForwardParams, BackwardParams, GradientParams } from "./CustomLayer";

export class CustomIdentity extends CustomLayer {
  constructor() {
    super();
  }

  // Performs the forward logic of applying the layer 
  // to the input object and storing the result in the output object.
  Forward(params: ForwardParams) {
    params.output = params.input;
  }

  // Performs a backpropagation step through the layer,
  // with respect to the given input.
  Backward(params: BackwardParams) {
    params.g = params.gy;
  }

  // Performs a backpropagation step through the layer,
  // with respect to the given input.
  Gradient(params: GradientParams) {
    // Nothing to do.
  }
}
