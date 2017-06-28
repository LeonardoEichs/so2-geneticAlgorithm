/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#include "BooleanGenotype.hpp"
#include <vector>
#include <iostream>
#include <stdlib.h>     /* srand, rand */

using namespace std;


BooleanGenotype::BooleanGenotype() {}

void BooleanGenotype::init(int n) {
  for (int i = 0; i < n; i++) {
    bool random = rand()%2;
    listGenotype.push_back(random);
  }
}

void BooleanGenotype::printGenotype() {
  int size = this->size();
  for(int i = 0; i < size; i++) {
    cout << this->at(i);
  }
  cout << endl;
}
