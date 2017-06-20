#ifndef BOUND_H
#define BOUND_H

#include <type_traits>

using namespace std;

template <typename NumericType>
class Bound {
  static_assert(is_arithmetic<NumericType>::value, "NumericType must be numeric");
  public:
      virtual NumericType getLowerBound(int index) = 0;
      virtual NumericType getUpperBound(int index) = 0;
};

#endif
