/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef POPULATION_H
#define POPULATION_H

#include "../Individual.hpp"
#include "../Objectives.hpp"
#include <vector>
#include <string>
#include <memory>

using namespace std;

template<typename G, typename T, typename P>
class Population {
  protected:
    vector<Individual<G, T, P>> population;
  public:
    Population(){}
    int size() {  return population.size(); }
    void push_back(Individual<G, T, P> individual) {  this->population.push_back(individual); }
    void setAt(int i, Individual<G, T, P> newIndividual) {
      G newGen = newIndividual.getGenotype();
      this->population[i].setGenotype(newGen);
      this->population[i].setPhenotype(newIndividual.getPhenotype());
      this->population[i].setObjectives(newIndividual.getObjectives());
    }
    void setPopulation(vector<Individual<G, T, P>> newPopulation) {
      for (int i = 0; i < newPopulation.size(); i++) {
        G newGen = newPopulation[i].getGenotype();
        this->population[i].setGenotype(newGen);
        this->population[i].setPhenotype(newPopulation[i].getPhenotype());
        this->population[i].setObjectives(newPopulation[i].getObjectives());
      }
    }
    T bestIndividualValue() {
      T best = this->population.at(0).getObjectives().getValue(0);
      for(int i = 1; i < this->population.size(); i++) {
        if (this->population.at(i).getObjectives().getKeySign(0) == 1) {
          if (this->population.at(i).getObjectives().getValue(0) > best)
            best = this->population.at(i).getObjectives().getValue(0);
        }
        else {
          if (this->population.at(i).getObjectives().getValue(0) < best)
            best = this->population.at(i).getObjectives().getValue(0);
        }
      }
      return best;
    }
    int bestIndividualPos() {
      int pos = 0;
      T best = this->population.at(0).getObjectives().getValue(0);
      for(int i = 1; i < this->population.size(); i++) {
        if (this->population.at(i).getObjectives().getKeySign(0) == 1) {
          if (this->population.at(i).getObjectives().getValue(0) > best) {
            best = this->population.at(i).getObjectives().getValue(0);
            pos = i;
          }
        }
        else {
          if (this->population.at(i).getObjectives().getValue(0) < best) {
            best = this->population.at(i).getObjectives().getValue(0);
            pos = i;
          }
        }
      }
      return pos;
    }
    vector<Individual<G, T, P>> getPopulation() { return this->population; }
    Individual<G, T, P> at(int i) {  return this->population.at(i); }
};

#endif
