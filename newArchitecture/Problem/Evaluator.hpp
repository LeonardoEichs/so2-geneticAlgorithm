#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "../Objectives.hpp"

template<typename T, typename P>
class Creator {
  public:
    Objectives<T> evaluate(P phenotype) = 0;
};

#endif
