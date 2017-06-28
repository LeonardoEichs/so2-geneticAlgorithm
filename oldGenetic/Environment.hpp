/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/
#ifndef ENVIRONMENT
#define ENVIRONMENT
#include <vector>
#include <iostream>
#include "Individual.hpp"
using namespace std;

class Environment {
  public:
    // Vector containing population
    vector<Individual> population;
    // Number of members in the population
    int population_size;
    // Keeps track of which generation the algorithm is in
    int generation;
    // Sets a maximum generation value in which the program stops
    int max_generations;
    // Sets a maximum number of generation in which the best score repeats,
    // in case of the best score repeating we can stop the program earlier
    int max_repetitions;
    // Keeps track of the number of generations in which the best score is repeated
    int best_repetition;
    // Keeps track of the best score in the population
    double best_score;
    // Rate in which the operation of crossover will occur
    double crossover_rate;
    // Rate in which the operation of mutation will occur
    double mutation_rate;
  public:
    // Environment constructor defines the class variables
    // [population_size, max_generations, max_repetitions, crossover_rate, mutation_rate]
    Environment(int pop_size, int max_gen, int max_rep, double cross_rate, double mut_rate);
    // Prints the populations cromossomes and fitness scores
    void displayPopulation();
    // Test if the best score changed from the previous generation to the actual
    bool test_variation();
    // Runs the genetic algorithm
    void run();
    // Executes a step of the algorithm
    void step();
    // Selection of cromossome to go the next generation
    int tournament();
    // Mutates the individual
    Individual _mutate(Individual ind);
    // Average score of the population
    double average();
    // Returns best individual of the population
    Individual best();
};

#endif
