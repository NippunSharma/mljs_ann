import { getInstance } from "@ml.js/core";
import { Layer } from "./Layer";

export class Linear implements Layer {
  private numNeurons: number;
  private mlpack_Layer: any;
  private mlpack_Name: string = "linear";
  private mlpack_Type: string = "layer";

  constructor(numNeurons: number) {
    this.numNeurons = numNeurons;
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
    this.mlpack_Layer = new instance[this.getFullName()](this.numNeurons);
  }
}
