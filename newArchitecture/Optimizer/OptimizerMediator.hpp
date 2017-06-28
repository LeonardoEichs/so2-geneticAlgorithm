/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef OPTIMIZERMEDIATOR_H
#define OPTIMIZERMEDIATOR_H

#include "../Config.hpp"

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
      T result;
      this->iterativeOptimizer.initialize();
      cout << " Creating Population..." << endl;
      nextIteration();
      while ((this->iteration < this->maxIteration) && this->repetition != MAX_BEST_REPETITIONS) {
        this->iterativeOptimizer.next();
        cout << "----------------------------" << endl;
        nextIteration();
        cout << "Repetition of Best Individual: " << this->repetition << endl;
        cout << "----------------------------" << endl;

      }
      result = population.bestIndividualValue();
      return result;

    }

    int getIteration() {
      return this->iteration;
    }

    void nextIteration() {
      cout << "Generation:  " << getIteration() << endl;
      vector<Individual<G, T, P>> pop = this->population.getPopulation();
      this->completer.complete(pop);
      this->population.setPopulation(pop);
      if (this->population.bestIndividualValue() == this->currentBest)
        this->repetition++;
      else
        this->currentBest = this->population.bestIndividualValue();
      cout << "Best Individual Value: " << this->population.bestIndividualValue() << endl;
      this->iteration += 1;
    }
};

#endif
