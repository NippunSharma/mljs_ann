import { BCELoss } from "./losses/BCELoss";
import { MSELoss } from "./losses/MSELoss";
import { ConstInit } from "./inits/ConstInit";
import { Linear } from "./layers/Linear";
import { LogSoftMax } from "./layers/LogSoftmax";
import { ReLU } from "./layers/ReLU";
import { Adam } from "./optimizers/Adam";
import { NLLLoss } from "./losses/NLLLoss";
import { GlorotInit } from "./inits/GlorotInit";
import { Dropout } from "./layers/Dropout";
import { CustomLayer } from "./layers/CustomLayer";

export type LossTypes = BCELoss | MSELoss | NLLLoss;
export type InitializationRuleTypes = ConstInit | GlorotInit;
export type LayerTypes = Linear | LogSoftMax | ReLU | Dropout | CustomLayer;
export type OptimizerTypes = Adam;
