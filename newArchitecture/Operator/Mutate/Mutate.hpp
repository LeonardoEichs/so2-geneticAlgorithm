#ifndef MUTATE_H
#define MUTATE_H

#include <type_traits>
#include "../../Optimizer/Operator.hpp"
#include "../../Genotype.hpp"

template<typename G>
class Mutate : public Operator<G> {
  static_assert(std::is_base_of<Genotype, G>::value, "Must be a Genotype");
  public:
    virtual void mutate(G& genotype, double p) = 0;
};

#endif
