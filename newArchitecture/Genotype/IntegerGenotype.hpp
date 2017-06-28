/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef INTEGERGENOTYPE_H
#define INTEGERGENOTYPE_H

#include "ListGenotype.hpp"
#include "FixedBound.hpp"
#include <vector>

using namespace std;

class IntegerGenotype : public ListGenotype<int> {
  protected:
    FixedBound<int> *bounds;
  public:
    IntegerGenotype(int lowerBound, int upperBound);
    //IntegerGenotype(FixedBound<int> bounds);
    int getLowerBound(int index);
    int getUpperBound(int index);
    void init(int n);
};

#endif
