/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#include "IntegerBound.hpp"

using namespace std;

IntegerBound::IntegerBound(int* lower, int* upper) {
  this->lower = lower;
  this->upper = upper;
}

IntegerBound::IntegerBound(vector<int> lower, vector<int> upper) {
  copy(lower.begin(), lower.end(), this->lower);
  copy(upper.begin(), upper.end(), this->upper);
}

int IntegerBound::getLowerBound(int index) {
    return lower[index];
}

int IntegerBound::getUpperBound(int index) {
  return upper[index];
}
