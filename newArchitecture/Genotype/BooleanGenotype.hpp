/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef BOOLEANGENOTYPE_H
#define BOOLEANGENOTYPE_H

#include "ListGenotype.hpp"
#include <vector>

using namespace std;

class BooleanGenotype : public ListGenotype<bool> {
  public:
    BooleanGenotype();
    void init(int n);
    void printGenotype();
};

#endif
