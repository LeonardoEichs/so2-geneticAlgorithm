#ifndef OBJECTIVES_H
#define OBJECTIVES_H

#include "Objective.hpp"
#include <vector>
#include <string>
#include <map>

using namespace std;

template<typename T>
class Objectives {
  protected:
    vector< map<Objective, T> > objectives;

  public:
    Objectives(){};
    void add(string name, Objective::Sign sign, T value) {
      Objective objective = Objective(name, sign);
      map<Objective, T> new_objective;
      new_objective[objective] = value;
      objectives.push_back(new_objective);
    }
    string getKeyName(int i) {
      return objectives.at(i).begin()->first.getName();
    }
    Objective::Sign getKeySign(int i) {
      return objectives.at(i).begin()->first.getSign();
    }
    T getValue(int i) {
      return objectives.at(i).begin()->second;
    }

};

#endif
