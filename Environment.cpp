#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include "Environment.hpp"
#include "Individual.hpp"

using namespace std;

void printCromossome(vector<bool> cromossome) {
  for (int i = 0; i < cromossome.size(); i++){
    cout << cromossome[i];
  }
  cout << endl;
}

Environment::Environment(int pop_size, int max_gen, double cross_rate, double mut_rate) {
  population_size = pop_size;
  max_generations = max_gen;
  generation = 0;
  cross_rate = crossover_rate;
  mut_rate = mutation_rate;
  best_score = 0;
  best_repetition = 0;
  max_repetitions = 100;
  for (int i = 0; i < population_size; i++) {
    population.push_back(Individual());
  }
}

void Environment::displayPopulation() {
  for (int i = 0; i < population.size(); i++) {
    printCromossome(population[i].cromossome);
    cout << population[i].fitness_score << endl;
  }
}

bool Environment::test_variation() {
  double this_generation_best = best().fitness_score;
  if (best_score == this_generation_best) {
    best_repetition += 1;
    if (best_repetition == max_repetitions)
      return true;
  }
  else {
    best_repetition = 0;
    best_score = this_generation_best;
  }
  return false;
}

void Environment::run() {
  while(max_generations > generation && (!test_variation())) {
    step();
  }
  displayPopulation();
}

void Environment::step() {
  vector<Individual> next_generation;
  Individual best = population[0];
  for (int i = 1; i < population.size(); i++) {
    if (population[i].fitness_score > best.fitness_score)
      best = population[i];
  }
  // Elitism
  next_generation.push_back(best);
  // Elitism and non-elite crossover and mutation
  Individual selected = population[tournament()];
  vector<vector<bool> > offsprings = best.crossover(selected.cromossome);
  Individual new_individual1 = Individual();
  new_individual1.cromossome = offsprings[0];
  Individual new_individual2 = Individual();
  new_individual2.cromossome = offsprings[1];
  next_generation.push_back(_mutate(new_individual1));
  next_generation.push_back(_mutate(new_individual2));
  //
  double random;
  while (next_generation.size() < population_size) {
    Individual selected = population[tournament()];
    random = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
    if (random <= crossover_rate) {
      Individual selected2 = population[tournament()];
      vector<vector<bool> > offsprings = selected.crossover(selected2.cromossome);
      Individual new_individual1 = Individual();
      new_individual1.cromossome = offsprings[0];
      Individual new_individual2 = Individual();
      new_individual2.cromossome = offsprings[1];
      next_generation.push_back(_mutate(new_individual1));
      next_generation.push_back(_mutate(new_individual2));
    }
    else {
      next_generation.push_back(_mutate(selected));
    }
  }
  population = next_generation;
  for (int i = 0; i < population.size(); i++)
    population[i].evaluate();
  generation += 1;
}

Individual Environment::_mutate(Individual ind) {
  double random;
  for (int i = 0; i < ind.cromossome.size(); i++) {
    random = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
    if (random <= mutation_rate)
      ind.mutate(i);
  }
  return ind;
}

int Environment::tournament() {
  double total_score = 0;
  for (int i = 0; i < population.size(); i++) {
    total_score += population[i].fitness_score;
  }
  double random = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
  double num_low = 0, num_high = 0;
  for (int i = 0; i < population_size; i++) {
    num_high += static_cast <double> (population[i].fitness_score)/static_cast <double> (total_score);
    if (random >= num_low && random <= num_high) {
      //printCromossome(population[i].cromossome);
      return i;
    }
    num_low = num_high;
  }
}

double Environment::average() {
  double result = 0.0;
  for (int i = 0; i < population_size; i++) {
    result += population[i].fitness_score;
  }
  result = result/population_size;
  return result;
}

Individual Environment::best() {
  Individual best = population[0];
  for (int i = 1; i < population.size(); i++) {
    if (population[i].fitness_score > best.fitness_score)
      best = population[i];
  }
  return best;
}
