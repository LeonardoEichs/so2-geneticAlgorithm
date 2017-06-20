#ifndef FIXEDBOUND_H
#define FIXEDBOUND_H

#include "Bound.hpp"
#include <type_traits>

using namespace std;

template <typename NumericType>
class FixedBound : public Bound<NumericType> {
  static_assert(is_arithmetic<NumericType>::value, "NumericType must be numeric");
  protected:
      NumericType lower;
      NumericType upper;
  public:
      FixedBound(NumericType lower, NumericType upper)
        : lower(lower), upper(upper) {};
      NumericType getLowerBound(int index) {  return lower; };
      NumericType getUpperBound(int index) {  return upper; };

};

#endif
