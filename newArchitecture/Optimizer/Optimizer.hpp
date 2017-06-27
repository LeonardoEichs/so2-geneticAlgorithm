#ifndef OPTIMIZER_H
#define OPTIMIZER_H

template<typename G, typename T, typename P>
class Optimizer {
  public:
    virtual T optimize() = 0;
    virtual int getIteration() = 0;
};

#endif
