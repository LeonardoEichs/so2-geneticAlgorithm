#ifndef LISTGENOTYPE_H
#define LISTGENOTYPE_H

#include "../Genotype.hpp"
#include <vector>

using namespace std;

template<typename T>
class ListGenotype : public Genotype {
  protected:
    vector<T> listGenotype;
  public:
    int size() {  return listGenotype.size(); }
};

#endif
