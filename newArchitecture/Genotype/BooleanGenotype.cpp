#include "BooleanGenotype.hpp"
#include <vector>
#include <stdlib.h>     /* srand, rand */

using namespace std;


BooleanGenotype::BooleanGenotype() {}

void BooleanGenotype::init(int n) {
  for (int i = 0; i < n; i++) {
    bool random = rand()%2;
    listGenotype.push_back(random);
  }
}
