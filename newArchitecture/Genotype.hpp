#ifndef GENOTYPE_H
#define GENOTYPE_H

class Genotype {
  public:
    virtual void init(int n) = 0;
    virtual int size() = 0;
};

#endif
