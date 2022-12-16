export interface Opt {
  init(): void;
  getMlpackInstance(): any;
  getMlpackType(): string;
  getMlpackName(): string;
  getFullName(): string;
}
