/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef CROSSOVER_H
#define CROSSOVER_H

#include <type_traits>
#include <utility>
#include "../../Optimizer/Operator.hpp"
#include "../../Genotype.hpp"

using namespace std;

template<typename G>
class Crossover : public Operator<G> {
  static_assert(std::is_base_of<Genotype, G>::value, "Must be a Genotype");
  public:
    virtual pair<G, G> crossover(G genotype1, G genotype2) = 0;
};

#endif
