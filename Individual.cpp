#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
#include "Individual.hpp"

using namespace std;

#define CROMOSSOME_SIZE 22

double bin_to_int(vector<bool> bit_seq) {
  double num = 0;
  int j;
  for (int i = 0; i < bit_seq.size(); i++) {
    j = bit_seq.size() - 1 - i;
    num += ((int) bit_seq[j]) * pow(2, i);
  }
  return num;
}

Individual::Individual() {
  bitset<CROMOSSOME_SIZE> random_binary(rand());
  for (int i = 0; i < random_binary.size(); i++)
    cromossome.push_back(random_binary.test(i));
  evaluate();
}

void Individual::evaluate() {
  //
  // normalize()
  //fitness_score = pow(bin_to_int(cromossome), 2);
  double x = normalize();
  fitness_score = x * sin(10*M_PI*x) + 1.0;
}

double Individual::normalize() {
  //
  //
  return -1 + (2+1)*(bin_to_int(cromossome)/(pow(2, 22) - 1));
}

void Individual::mutate(int position) {
  // Invert the value contained in that position of the cromossome
  cromossome[position] = !cromossome[position];
}

vector<vector<bool> > Individual::crossover(vector<bool> cromossome2) {
  // Can't get the first and last position
  int pivot_point = rand() % (cromossome.size() - 2) + 1;

  // Create the assistance vector which will hold the values
  // of the cromossome starting from the pivot point
  vector<bool> assist1, assist2;
  for (int i = pivot_point; i < CROMOSSOME_SIZE; i++){
    assist1.push_back(cromossome[i]);
    assist2.push_back(cromossome2[i]);
  }

  // Remove values from cromossomes 1 and 2
  for (int i = 0; i < assist1.size(); i++){
    cromossome.pop_back();
    cromossome2.pop_back();
  }

  // Insert values from the assistance vector 2 on cromossome 1
  // and values from assistance vector 1 on cromossome 2
  for (int i = 0; i < assist1.size(); i++){
    cromossome.push_back(assist2[i]);
    cromossome2.push_back(assist1[i]);
  }

  // Create a vector of boolean vectors in which the 2 new cromossomes
  // will be stored
  vector< vector<bool> > return_value;
  return_value.push_back(cromossome);
  return_value.push_back(cromossome2);
  // Return vector containing new cromossomes
  return return_value;
}

void Individual::getCromossomeRepr() {
  for (int i = 0; i < cromossome.size(); i++)
    cout << cromossome[i];
  cout << endl;
}
