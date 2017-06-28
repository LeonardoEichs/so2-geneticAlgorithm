/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef INDIVIDUALCOMPLETER_H
#define INDIVIDUALCOMPLETER_H

#include "../Individual.hpp"
#include <vector>

template<typename G, typename T, typename P>
class IndividualCompleter {
  public:
    virtual void complete(vector<Individual<G, T, P>> & individuals) = 0;
};

#endif
