#ifndef BOOLEANGENOTYPE_H
#define BOOLEANGENOTYPE_H

#include "ListGenotype.hpp"
#include <vector>

using namespace std;

class BooleanGenotype : public ListGenotype<bool> {
  public:
    BooleanGenotype();
    void init(int n);
};

#endif
