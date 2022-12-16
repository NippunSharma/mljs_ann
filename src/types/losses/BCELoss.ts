import { Loss } from "./Loss";
import { getInstance} from "@ml.js/core";

export class BCELoss implements Loss {
  private eps: number;
  private reduction: boolean;
  private mlpack_Loss: any;
  private mlpack_Name: string = "bce";
  private mlpack_Type: string = "loss";

  constructor(eps: number = 1e-10, reduction: boolean = true) {
    this.mlpack_Name = "bce";
    this.eps = eps;
    this.reduction = reduction;
    this.init();
  }

  getMlpackName(): string {
    return this.mlpack_Name;
  }

  getMlpackInstance() {
    return this.mlpack_Loss;
  }

  getMlpackType(): string {
    return this.mlpack_Type
  }

  getFullName(): string {
    return this.getMlpackType() + "_" + this.getMlpackName();
  }

  init() {
    const instance = getInstance();
    this.mlpack_Loss = new instance[this.getFullName()](this.eps, this.reduction);
  }
}
