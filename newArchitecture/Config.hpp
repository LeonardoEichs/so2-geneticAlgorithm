#ifndef CONFIG_H
#define CONFIG_H

#include <stdlib.h>     /* srand, rand */
#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include <time.h>       /* time */

extern double POPULATION;
extern double MAX_ITERATION;
extern double MAX_BEST_REPETITIONS;
extern double CROSSOVER_RATE;
extern double MUTATION_RATE;

double POPULATION = 10;
double MAX_ITERATION = 500;
double MAX_BEST_REPETITIONS = 150;
double CROSSOVER_RATE = 0.6;
double MUTATION_RATE = 0.6;

class VTypes {
  public:
  typedef BooleanGenotype G;
  typedef double T;
  typedef double P;
};

#endif
