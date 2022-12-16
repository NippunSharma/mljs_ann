import { Loss } from "./Loss";
import { getInstance} from "@ml.js/core";

export class MSELoss implements Loss {
  private reduction: boolean;
  private mlpack_Loss: any;
  private mlpack_Name: string = "mse";
  private mlpack_Type: string = "loss";

  constructor(reduction: boolean = true) {
    this.mlpack_Name = "mse";
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
    this.mlpack_Loss = new instance[this.getFullName()](this.reduction);
  }
}
