#include <map>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

template<typename K>
BooleanMapGenotype<K>::BooleanMapGenotype(vector<K> keyList) {
  this->keyList = keyList;
}

template<typename K>
void BooleanMapGenotype<K>::init() {
  BooleanGenotype::init(keyList.size());
  for (int i = 0; i < keyList.size(); i++) {
    this->mapGenotype[this->keyList.at(i)] = this->listGenotype.at(i);
  }
}

template<typename K>
void BooleanMapGenotype<K>::init(int n) { // Throw Error
  throw std::invalid_argument( "You should use init()" );
}

template<typename K>
void BooleanMapGenotype<K>::toString() {
  typename map<K, bool>::iterator a = this->mapGenotype.begin();
  cout << "Aqui" << endl;
  cout << "[";
  for (const auto &p : this->mapGenotype) {
    cout <<  p.first << " = " << p.second << "; ";
  }
  cout << "]" << endl;
}

template<typename K>
vector<K> BooleanMapGenotype<K>::getKeys() {
  vector<K> keys;
  for (const auto &p : this->mapGenotype) {
    keys.push_back(p.first);
  }
  return keys;
}

template<typename K>
bool BooleanMapGenotype<K>::getValue(K key) {
  return this->mapGenotype.find(key)->second;
}

template<typename K>
void BooleanMapGenotype<K>::setValue(K key, bool value) {
  this->mapGenotype[key] = value;
}

template<typename K>
bool BooleanMapGenotype<K>::containsKey(K key) {
  for (const K& i : getKeys()) {
    if (*i == key)
      return true;
  }
  return false;
}

template<typename K>
int BooleanMapGenotype<K>::getIndexOf(K key) {
  vector<K> keys = getKeys();
  for (int i = 0; i < keys.size(); i++) {
    if (key == keys.at(i))
      return i;
  }
  return -1;
}
