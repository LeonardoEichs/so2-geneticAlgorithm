#ifndef CROSSOVERBOOLEAN_H
#define CROSSOVERBOOLEAN_H

#include "Crossover.hpp"
#include "../../Genotype/BooleanGenotype.hpp"

using namespace std;

class CrossoverBoolean : virtual public Crossover<BooleanGenotype> {
  virtual pair<BooleanGenotype, BooleanGenotype> crossover(BooleanGenotype genotype1, BooleanGenotype genotype2) = 0;
};

#endif
