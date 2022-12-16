export interface Loss {
  init(): void;
  getMlpackInstance(): any;
  getMlpackType(): string;
  getMlpackName(): string;
  getFullName(): string;
}
