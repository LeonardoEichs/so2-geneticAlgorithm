#ifndef ENVIRONMENT
#define ENVIRONMENT
#include <vector>
#include <iostream>
#include "Individual.hpp"
using namespace std;

class Environment {
  public:
    vector<Individual> population;
    int population_size;
    int max_generations;
    double best_score;
    int best_repetition;
    int max_repetitions;
    int generation;
    double crossover_rate;
    double mutation_rate;
  public:
    Environment(int pop_size, int max_gen, double cross_rate, double mut_rate);
    void displayPopulation();
    void run();
    void step();
    int tournament();
    Individual _mutate(Individual ind);
    double average();
    Individual best();
    bool test_variation();
};

#endif
