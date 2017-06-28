/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef CROSSOVERBOOLEANDEFAULT_H
#define CROSSOVERBOOLEANDEFAULT_H

#include "CrossoverBooleanRate.hpp"

using namespace std;

class CrossoverBooleanDefault : public CrossoverBooleanRate {
  public:
    CrossoverBooleanDefault(double rate) : CrossoverBooleanRate(0.5){}
};

#endif
