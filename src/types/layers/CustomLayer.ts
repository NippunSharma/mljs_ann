import { getInstance } from "@ml.js/core";
import { Matrix } from "@ml.js/linalg";
import { Layer } from "./Layer";

export interface ForwardParams {
  input: Matrix<number>;
  output: Matrix<number>;
}

export interface BackwardParams {
  input: Matrix<number>;
  gy: Matrix<number>;
  g: Matrix<number>;
}

export interface GradientParams {
  input: Matrix<number>;
  error: Matrix<number>;
  gradient: Matrix<number>;
}

export abstract class CustomLayer implements Layer {
  protected mlpack_Layer: any;
  protected mlpack_Name: string = "custom_layer";
  protected mlpack_Type: string = "layer";

  constructor() {
    this.init();
  }

  getMlpackName(): string {
    return this.mlpack_Name;
  }

  getMlpackInstance() {
    return this.mlpack_Layer;
  }

  getMlpackType(): string {
    return this.mlpack_Type
  }

  getFullName(): string {
    return this.getMlpackType() + "_" + this.getMlpackName();
  }

  init() {
    const instance = getInstance();
    this.mlpack_Layer = new instance[this.getFullName()]();
  }

  abstract Forward(params: ForwardParams): void;
  abstract Backward(params: BackwardParams): void;
  abstract Gradient(params: GradientParams): void;

  int_Forward(input: any, output: any) {
    const inputMatrix = new Matrix<number>({ n_cols: input.n_cols(), n_rows: input.n_rows() }, "double");
    inputMatrix.setArmaMat(input);

    const outputMatrix = new Matrix<number>({ n_cols: output.n_cols(), n_rows: output.n_rows() }, "double");
    outputMatrix.setArmaMat(output);

    const params: ForwardParams = { input: inputMatrix, output: outputMatrix };
    this.Forward(params);
    return params.output.getArmaMat();
  }

  int_Backward(input: any, gy: any, g: any) {
    const inputMatrix = new Matrix<number>({ n_cols: input.n_cols(), n_rows: input.n_rows() }, "double");
    inputMatrix.setArmaMat(input);

    const gyMatrix = new Matrix<number>({ n_cols: gy.n_cols(), n_rows: gy.n_rows() }, "double");
    gyMatrix.setArmaMat(gy);

    const gMatrix = new Matrix<number>({ n_cols: g.n_cols(), n_rows: g.n_rows() }, "double");
    gMatrix.setArmaMat(g);

    const params: BackwardParams = { input: inputMatrix, gy: gyMatrix, g: gMatrix };
    this.Backward(params);
    return params.g.getArmaMat();
  }

  int_Gradient(input: any, error: any, gradient: any) {
    const inputMatrix = new Matrix<number>({ n_cols: input.n_cols(), n_rows: input.n_rows() }, "double");
    inputMatrix.setArmaMat(input);

    const errorMatrix = new Matrix<number>({ n_cols: error.n_cols(), n_rows: error.n_rows() }, "double");
    errorMatrix.setArmaMat(error);

    const gradientMatrix = new Matrix<number>({ n_cols: gradient.n_cols(), n_rows: gradient.n_rows() }, "double");
    gradientMatrix.setArmaMat(gradient);

    const params: GradientParams = { input: inputMatrix, error: errorMatrix, gradient: gradientMatrix };
    this.Gradient(params);
    return params.gradient.getArmaMat();
  }
}
