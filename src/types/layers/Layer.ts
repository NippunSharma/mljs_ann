export interface Layer {
  init(): void;
  getMlpackInstance(): any;
  getMlpackType(): string;
  getMlpackName(): string;
  getFullName(): string;
}
