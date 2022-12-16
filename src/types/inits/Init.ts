export interface Init {
  init(): void;
  getMlpackInstance(): any;
  getMlpackType(): string;
  getMlpackName(): string;
  getFullName(): string;
}
