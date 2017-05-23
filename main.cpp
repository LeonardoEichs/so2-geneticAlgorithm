#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Individual.hpp"
#include "Environment.hpp"

using namespace std;

int main() {
  srand (time(NULL));
  Environment env = Environment(5000, 10000, 0.8, 0.5);
  //env.displayPopulation();
  env.run();
  cout << "-----------------------" << endl;
  cout << env.best().fitness_score << endl;
  cout << env.generation << endl;

}
