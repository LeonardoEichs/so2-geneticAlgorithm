#ifndef CROSSOVERLISTRATE_H
#define CROSSOVERLISTRATE_H

#include <type_traits>
#include <stdlib.h>     /* srand, rand */
#include <utility>
#include <algorithm>
#include "Crossover.hpp"
#include "../../Genotype/ListGenotype.hpp"

using namespace std;

template<typename G>
class CrossoverListRate : virtual public Crossover<G> {
  protected:
    double rate;
  public:
    CrossoverListRate(double rate): rate(rate){}
    /*
    Uniform crossover - bits are randomly copied from the first or from the second parent
    */
    pair<G, G> crossover(G genotype1, G genotype2) {
      int size = genotype1.getGenotype().size();
      bool select = rand()%2;
      double random;
      G temp = genotype1;

      for (int i = 0; i < size; i++) {
        random = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
        if (random < this->rate) {
          select = !select;
        }
        if (select) {}
        else {
          genotype1.set(i, genotype2.getGenotype()[i]);
          genotype2.set(i, temp.getGenotype()[i]);
        }
      }

      pair<G, G> offspring;
      offspring.first = genotype1;
      offspring.second = genotype2;

      return offspring;

    }
};

#endif
