/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#include "DoubleGenotype.hpp"
#include <vector>
#include <stdlib.h>     /* srand, rand */

using namespace std;

DoubleGenotype::DoubleGenotype() {
  DoubleGenotype(0, 1);
}

DoubleGenotype::DoubleGenotype(double lowerBound, double upperBound) {
  this->bounds = new FixedBound<double>(lowerBound, upperBound);
}

double DoubleGenotype::getLowerBound(int index) {
  return bounds->getLowerBound(index);
}

double DoubleGenotype::getUpperBound(int index) {
  return bounds->getUpperBound(index);
}

void DoubleGenotype::init(int n) {
  double lo, up, value;
  for (int i = 0; i < n; i++) {
    lo = getLowerBound(i);
    up = getUpperBound(i);
    double f = (double)rand() / RAND_MAX;
    value = lo + f * (up - lo);
    listGenotype.push_back(value);
  }
}
