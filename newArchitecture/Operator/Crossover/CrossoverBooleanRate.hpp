/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef CROSSOVERBOOLEANRATE_H
#define CROSSOVERBOOLEANRATE_H

#include "CrossoverListRate.hpp"
#include "CrossoverBoolean.hpp"
#include "../../Genotype/BooleanGenotype.hpp"

using namespace std;

class CrossoverBooleanRate : public CrossoverListRate<BooleanGenotype>, public CrossoverBoolean{
  public:
    CrossoverBooleanRate(double rate) : CrossoverListRate(rate){}
    pair<BooleanGenotype, BooleanGenotype> crossover(BooleanGenotype genotype1, BooleanGenotype genotype2) {
      return CrossoverListRate<BooleanGenotype>::crossover(genotype1, genotype2);
    }
};

#endif
