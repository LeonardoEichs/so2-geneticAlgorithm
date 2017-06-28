/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef SELECTGENOTYPE_H
#define SELECTGENOTYPE_H

#include "IntegerGenotype.hpp"
#include <vector>

using namespace std;

template <typename V>
class SelectGenotype : public IntegerGenotype {
  protected:
    vector<V> values;
  public:
    SelectGenotype(vector<V> values);
    // Not possible to use a C style array for this task because
    // unlike Java, C++ can't deal with arrays with unknown size
    //SelectGenotype(V* values);
    V getValue(int index);
};

#include "SelectGenotype.tpp"

#endif
