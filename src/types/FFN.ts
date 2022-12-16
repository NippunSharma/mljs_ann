import { LossTypes, InitializationRuleTypes, LayerTypes, OptimizerTypes } from "./Types";
import { Matrix } from "@ml.js/linalg";
import { getInstance } from "@ml.js/core";

export class FFN<LossType extends LossTypes,
                 InitializationRuleType extends InitializationRuleTypes> {
  private lossType: LossType;
  private initRuleType: InitializationRuleType;
  private mlpack_FFN;

  constructor(lossType: LossType, initRuleType: InitializationRuleType) {
    this.lossType = lossType;
    this.initRuleType = initRuleType;
    this.init();
  }

  init() {
    const instance = getInstance();
    this.mlpack_FFN = new instance["ffn_" +
        this.lossType.getMlpackName() + "_" + this.initRuleType.getMlpackName()]
        (this.lossType.getMlpackInstance(),
         this.initRuleType.getMlpackInstance());
  }

  getMlpackInstance() {
    return this.mlpack_FFN;
  }

  Add<LayerType extends LayerTypes>(layer: LayerType): void {
    this.mlpack_FFN["add_" + layer.getMlpackName()](layer.getMlpackInstance());
  }

  Train<OptimizerType extends OptimizerTypes>(predictors: Matrix<number>, responses: Matrix<number>, opt: OptimizerType) {
    return this.mlpack_FFN["train_" + opt.getMlpackName()](predictors.getArmaMat(), responses.getArmaMat(), opt.getMlpackInstance());
  }

  Predict(predictors: Matrix<number>, batchSize: number = 128): Matrix<number> {
    const internal = this.mlpack_FFN["predict"](predictors.getArmaMat(), batchSize);
    const ret = new Matrix<number>({ n_rows: internal.n_rows(), n_cols: internal.n_cols() }, "double");
    ret.setArmaMat(internal);
    return ret;
  }
}
