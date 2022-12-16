import { getInstance } from "@ml.js/core";
import { Opt } from "./Opt";

export class Adam implements Opt {
  private mlpack_Opt: any;
  private mlpack_Name: string = "adam";
  private mlpack_Type: string = "opt";

  constructor(private stepSize: number = 0.001,
              private batchSize: number = 32,
              private beta1: number = 0.9,
              private beta2: number = 0.999,
              private eps: number = 1e-8,
              private maxIter: number = 100000,
              private tol: number = 1e-5,
              private shuffle: boolean = true,
              private resetPolicy: boolean = true,
              private exactObjective: boolean = false) {
    this.init();
  }

  getMlpackName(): string {
    return this.mlpack_Name;
  }

  getMlpackInstance() {
    return this.mlpack_Opt;
  }

  getMlpackType(): string {
    return this.mlpack_Type
  }

  getFullName(): string {
    return this.getMlpackType() + "_" + this.getMlpackName();
  }

  init() {
    const instance = getInstance();
    this.mlpack_Opt = new instance[this.getFullName()](this.stepSize,
        this.batchSize, this.beta1, this.beta2, this.eps, this.maxIter,
        this.tol, this.shuffle, this.resetPolicy, this.exactObjective);
  }
}
