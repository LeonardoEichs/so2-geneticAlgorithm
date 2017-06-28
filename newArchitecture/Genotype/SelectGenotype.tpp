/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#include "SelectGenotype.hpp"
#include <vector>

using namespace std;

template <typename V>
SelectGenotype<V>::SelectGenotype(vector<V> values)
  : IntegerGenotype(0, values.size() - 1){
    this->values = values;
}

// Not possible to use a C style array for this task because
// unlike Java, C++ can't deal with arrays with unknown size
/*
template <typename V>
SelectGenotype<V>::SelectGenotype(V* values) {
  vector<V> vectorValues(values);
  SelectGenotype(vectorValues);
}
*/

template <typename V>
V SelectGenotype<V>::getValue(int index) {
  return values.at(listGenotype.at(index));
}
