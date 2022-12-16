import { getInstance } from "@ml.js/core";
import { Init } from "./Init";

export class GlorotInit implements Init {
  private mlpack_Init: any;
  private mlpack_Name: string = "glorot_init";
  private mlpack_Type: string = "init";

  constructor() {
    this.init();
  }

  getMlpackName(): string {
    return this.mlpack_Name;
  }

  getMlpackInstance() {
    return this.mlpack_Init;
  }

  getMlpackType(): string {
    return this.mlpack_Type
  }

  getFullName(): string {
    return this.getMlpackType() + "_" + this.getMlpackName();
  }

  init() {
    const instance = getInstance();
    this.mlpack_Init = new instance[this.getFullName()]();
  }
}
