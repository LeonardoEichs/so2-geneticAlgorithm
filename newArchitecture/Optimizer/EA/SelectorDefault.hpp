#ifndef SELECTORDEFAULT_H
#define SELECTORDEFAULT_H

#include "../../Individual.hpp"
#include "Selector.hpp"
#include <vector>
#include <iostream>

using namespace std;

template<typename G, typename T, typename P>
class SelectorDefault : public Selector<G, T, P> {
  public:
    int select(vector<Individual<G, T, P>> population) {
      double total_score = 0;
      for (int i = 0; i < population.size(); i++) {
        total_score += population[i].getObjectives().getValue(0);
      }
      double random = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
      double num_low = 0, num_high = 0;
      for (int i = 0; i < population.size(); i++) {
        num_high += static_cast <double> (population[i].getObjectives().getValue(0))/static_cast <double> (total_score);
        if (random >= num_low && random <= num_high) {
          return i;
        }
        num_low = num_high;
      }
    }
};

#endif
