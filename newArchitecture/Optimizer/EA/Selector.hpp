/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef SELECTOR_H
#define SELECTOR_H

#include "../../Individual.hpp"
#include <vector>

using namespace std;

template<typename G, typename T, typename P>
class Selector {
  public:
    virtual int select(vector<Individual<G, T, P>> population) = 0;
};

#endif
