/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#include "IntegerGenotype.hpp"
#include <vector>
#include <stdlib.h>     /* srand, rand */

using namespace std;

IntegerGenotype::IntegerGenotype(int lowerBound, int upperBound) {
  this->bounds = new FixedBound<int>(lowerBound, upperBound);
  //IntegerGenotype(bounds);
}

//IntegerGenotype::IntegerGenotype(FixedBound<int> bounds) {
  //this.bounds = bounds;
//}

int IntegerGenotype::getLowerBound(int index) {
  return bounds->getLowerBound(index);
}

int IntegerGenotype::getUpperBound(int index) {
  return bounds->getUpperBound(index);
}

void IntegerGenotype::init(int n) {
  int lo, up, value;
  for (int i = 0; i < n; i++) {
    lo = getLowerBound(i);
    up = getUpperBound(i);
    value = rand() % up + lo;
    listGenotype.push_back(value);
  }
}
