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
