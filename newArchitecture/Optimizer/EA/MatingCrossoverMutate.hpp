/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef MATINGCROSSOVERMUTATE_H
#define MATINGCROSSOVERMUTATE_H

#include <vector>
#include "../../Operator/Mutate/Mutate.hpp"
#include "../../Operator/Mutate/MutateBoolean.hpp"
#include "../../Operator/Crossover/Crossover.hpp"
#include "../../Operator/Crossover/CrossoverBoolean.hpp"
#include "../../Operator/Crossover/CrossoverBooleanDefault.hpp"
#include "../../Operator/Crossover/CrossoverBooleanRate.hpp"
#include "../../Operator/Crossover/CrossoverListRate.hpp"
#include "../../Individual.hpp"
#include "../../IndividualFactory.hpp"
#include "Mating.hpp"

using namespace std;

template<typename G, typename T, typename P>
class MatingCrossoverMutate : public Mating<G, T, P>{
  protected:
    Crossover<G>& crossover;
    Mutate<G>& mutate;
    double crossoverRate;
    double mutateRate;
    IndividualFactory<G, T, P>& factory;
  public:
    MatingCrossoverMutate(Crossover<G>& crossover, Mutate<G>& mutate, double crossoverRate, double mutateRate, IndividualFactory<G, T, P>& factory)
      : crossover(crossover), mutate(mutate), crossoverRate(crossoverRate), mutateRate(mutateRate), factory(factory){}

    vector<Individual<G, T, P>> mate(vector<Individual<G, T, P>> selected) {
      vector<Individual<G, T, P>> newGeneration;

      for (int i = 0; i < selected.size(); i++) {
        double random = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);

        if (random < crossoverRate) {
          int selectRand = rand() % selected.size();
          pair<G, G> offsprings = this->crossover.crossover(selected[i].getGenotype(), selected[selectRand].getGenotype());
          if (newGeneration.size() + 2 > selected.size()) {
            this->mutate.mutate(offsprings.first, mutateRate);
            Individual<G, T, P> newIndividual = this->factory.create(offsprings.first);
            newGeneration.push_back(newIndividual);
          }
          else {
            this->mutate.mutate(offsprings.first, mutateRate);
            Individual<G, T, P> newIndividual1 = this->factory.create(offsprings.first);
            newGeneration.push_back(newIndividual1);

            this->mutate.mutate(offsprings.second, mutateRate);
            Individual<G, T, P> newIndividual2 = this->factory.create(offsprings.second);
            newGeneration.push_back(newIndividual2);
          }
        }
        else {
          G gen = selected[i].getGenotype();
          this->mutate.mutate(gen, mutateRate);
          Individual<G, T, P> newIndividual = this->factory.create(gen);
          newGeneration.push_back(newIndividual);
        }
        if (newGeneration.size() == selected.size())
          break;
      }

      return newGeneration;
    }
};

#endif
