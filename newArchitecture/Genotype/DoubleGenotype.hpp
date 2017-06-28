/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef DOUBLEGENOTYPE_H
#define DOUBLEGENOTYPE_H

#include "ListGenotype.hpp"
#include "FixedBound.hpp"
#include <vector>

using namespace std;

class DoubleGenotype : public ListGenotype<double> {
  protected:
    FixedBound<double> *bounds;
  public:
    DoubleGenotype();
    DoubleGenotype(double lowerBound, double upperBound);
    double getLowerBound(int index);
    double getUpperBound(int index);
    void init(int n);
};

#endif
