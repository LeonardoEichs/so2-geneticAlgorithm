#ifndef OPTIMIZERMEDIATOR_H
#define OPTIMIZERMEDIATOR_H

#include "../Config.hpp"
#include "Population.hpp"
#include "Optimizer.hpp"
#include "IndividualCompleter.hpp"
#include "IterativeOptimizer.hpp"
#include <iostream>

template<typename G, typename T, typename P>
class OptimizerMediator : public Optimizer<G, T, P> {
  protected:
    IterativeOptimizer<G, T, P>& iterativeOptimizer;
    Population<G, T, P>& population;
    IndividualCompleter<G, T, P>& completer;
    int maxIteration;
    int iteration = 0;
    T currentBest;
    int repetition = 0;
  public:
    OptimizerMediator(IterativeOptimizer<G, T, P>& iterativeOptimizer, Population<G, T, P>& population, IndividualCompleter<G, T, P>& completer, int maxIteration)
      : iterativeOptimizer(iterativeOptimizer), population(population), completer(completer), maxIteration(maxIteration) {}

    T optimize() {
      this->iterativeOptimizer.initialize();
      nextIteration();
      while ((this->iteration < this->maxIteration) && this->repetition != MAX_BEST_REPETITIONS) {
        this->iterativeOptimizer.next();
        nextIteration();
      }
      return this->population.bestIndividualValue();

    }

    int getIteration() {
      return this->iteration;
    }

    void nextIteration() {
      vector<Individual<G, T, P>> pop = this->population.getPopulation();
      this->completer.complete(pop);
      this->population.setPopulation(pop);
      if (this->population.bestIndividualValue() == this->currentBest)
        this->repetition++;
      else
        this->currentBest = this->population.bestIndividualValue();
      cout << this->population.bestIndividualValue() << endl;
      this->iteration += 1;
    }
};

#endif
