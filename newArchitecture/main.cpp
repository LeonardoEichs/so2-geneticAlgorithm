#include <stdlib.h>     /* srand, rand */
#include <vector>
#include <string>
#include <iostream>
#include <time.h>       /* time */
#include "Genotype/SelectGenotype.hpp"
#include "Genotype/IntegerGenotype.hpp"
#include "Genotype/BooleanGenotype.hpp"
#include "Genotype/DoubleGenotype.hpp"
#include "Genotype/BooleanMapGenotype.hpp"
#include "Objectives.hpp"
#include "Objective.hpp"

using namespace std;

int main() {
  srand(time(NULL));
  vector<char> teste = {'a', 'b', 'c', 'd', 'e'};
  SelectGenotype<char> genotype = SelectGenotype<char>(teste);
  genotype.init(4);
  Objectives<int> objectives = Objectives<int>();
  objectives.add("objective", Objective::MIN, 5);
  cout << objectives.getKeyName(0) << endl;
  cout << objectives.getKeySign(0) << endl;
  cout << objectives.getValue(0) << endl;

  return 1;
}
