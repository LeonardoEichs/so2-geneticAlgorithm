/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "../Objectives.hpp"

template<typename T, typename P>
class Evaluator {
  public:
    virtual Objectives<T> evaluate(P phenotype) = 0;
};

#endif
