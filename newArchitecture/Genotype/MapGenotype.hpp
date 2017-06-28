/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef MAPGENOTYPE_H
#define MAPGENOTYPE_H

#include "../Genotype.hpp"
#include <map>
#include <vector>

using namespace std;

template<typename K, typename V>
class MapGenotype : public Genotype {
  protected:
    map<K, V> mapGenotype;
  public:
    int size() {  return mapGenotype.size(); }
    vector<K> getKeys();
    V getValue(K key);
    void setValue(K key, V value);
    bool containsKey(K key);
    int getIndexOf(K key);
};

#endif
