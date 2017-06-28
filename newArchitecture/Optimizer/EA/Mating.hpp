/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef MATING_H
#define MATING_H

#include <vector>
#include "../../Individual.hpp"

using namespace std;

template<typename G, typename T, typename P>
class Mating {
  public:
    virtual vector<Individual<G, T, P>> mate(vector<Individual<G, T, P>> selected) = 0;
};

#endif
