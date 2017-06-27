#ifndef EVOLUTIONARYALGORITHM_H
#define EVOLUTIONARYALGORITHM_H

#include "Selector.hpp"
#include "Mating.hpp"
#include "../IterativeOptimizer.hpp"
#include "../Population.hpp"
#include "../../Individual.hpp"
#include "../../IndividualFactory.hpp"
#include <vector>

using namespace std;

template<typename G, typename T, typename P>
class EvolutionaryAlgorithm : public IterativeOptimizer<G, T, P> {
  protected:
    Selector<G, T, P>& selector;
    Mating<G, T, P>& mating;
    int maxPopulation;
    Population<G, T, P>& population;
    IndividualFactory<G, T, P>& factory;
  public:
    EvolutionaryAlgorithm(Selector<G, T, P>& selector, Mating<G, T, P>& mating, double maxPopulation, Population<G, T, P>& population, IndividualFactory<G, T, P>& factory) :
      selector(selector), mating(mating), maxPopulation(maxPopulation), population(population), factory(factory) {}

    void initialize() {
      while (population.size() < maxPopulation) {
        Individual<G, T, P> indv = factory.create();
        this->population.push_back(indv);
      }
    }

    void next() {
      vector<Individual<G, T, P>> selected;
      for (int i = 0; i < this->maxPopulation; i++) {
        int sel = this->selector.select(this->population.getPopulation());
        selected.push_back(this->population.at(sel));
      }
      vector<Individual<G, T, P>> newPopulation = this->mating.mate(selected);
      Individual<G, T, P> bestPast = this->population.at(this->population.bestIndividualPos());
      this->population.setPopulation(newPopulation);
      this->population.setAt(0, bestPast);
    }
};

#endif
