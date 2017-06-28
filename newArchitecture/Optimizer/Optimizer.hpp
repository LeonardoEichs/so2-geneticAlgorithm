/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <utility>

using namespace std;

template<typename G, typename T, typename P>
class Optimizer {
  public:
    virtual T optimize() = 0;
    virtual int getIteration() = 0;
};

#endif
