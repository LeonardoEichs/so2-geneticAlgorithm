#ifndef BOOLEANMAPGENOTYPE_H
#define BOOLEANMAPGENOTYPE_H

#include "MapGenotype.hpp"
#include "BooleanGenotype.hpp"
#include <map>
#include <vector>
#include <string>

using namespace std;

template<typename K>
class BooleanMapGenotype :
  public MapGenotype<K, bool>, public BooleanGenotype {
  protected:
    vector<K> keyList;
  public:
    BooleanMapGenotype(vector<K> keyList);
    void init();
    void init(int n); // Throw Error
    void toString();
    int size() {  return this->mapGenotype.size(); }
    vector<K> getKeys();
    bool getValue(K key);
    void setValue(K key, bool value);
    bool containsKey(K key);
    int getIndexOf(K key);
};

#include "BooleanMapGenotype.tpp"

#endif
