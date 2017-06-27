#ifndef MUTATEBOOLEAN_H
#define MUTATEBOOLEAN_H

#include <type_traits>
#include <stdlib.h>     /* srand, rand */
#include "Mutate.hpp"
#include "../../Genotype/BooleanGenotype.hpp"

class MutateBoolean : public Mutate<BooleanGenotype> {
  public:
    MutateBoolean(){};
    void mutate(BooleanGenotype& genotype, double p) {
      int size = genotype.size();
      double random;
      for (int i = 0; i < size; i++) {
        random = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
        if (random < p) {
          genotype.set(i, !genotype.at(i));
        }
      }
    }
};

#endif
