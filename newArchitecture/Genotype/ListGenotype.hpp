/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

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
    virtual void init(int n) = 0;
    int size() {  return listGenotype.size(); }
    vector<T> getGenotype() { return listGenotype;  }
    T at(int i) { return listGenotype.at(i);  }
    void set(int i, T newValue) { this->listGenotype.at(i) = newValue;  }
};

#endif
