#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <string>
#include <iostream>
#include "Genotype.hpp"
#include "Objectives.hpp"

using namespace std;

template<typename G, typename T, typename P>
class Individual {
  public:
    struct State {
        const string name;
        const bool decoded;
        const bool evaluated;
        const bool processing;
        State(string name, bool decoded, bool evaluated, bool processing)
          : name(name), decoded(decoded), evaluated(evaluated), processing(processing){};
        string getName() {  return name; };
        bool isDecoded() { return decoded; };
        bool isEvaluated() { return evaluated;  };
        bool isProcessing() { return processing;  };
    };
    const State EMPTY = State("Empty", false, false, false);
    const State GENOTYPED = State("Genotyped", false, false, false);
    const State DECODING = State("Decoding", false, false, true);
    const State PHENOTYPED = State("Phenotyped", true, false, false);
    const State EVALUATING = State("Evaluating", true, false, true);
    const State EVALUATED = State("Evaluated", true, true, false);
  protected:
    G genotype;
    P phenotype;
    Objectives<T> objectives;
    State state = EMPTY;
  public:
    Individual(G genotype) : genotype(genotype) {};
    P getPhenotype() {  return phenotype; };
    Objectives<T> getObjectives() { return objectives;  };
    G getGenotype() {  return genotype;  };
    State getState() {  return state; };
    bool isDecoded() {  return state.isDecoded(); };
    bool isEvaluated() {  return state.isEvaluated(); };
    void setObjectives(Objectives<T> objectives) { this->objectives = objectives; };
    void setGenotype(G& genotype) { this->genotype = genotype; };
    void setPhenotype(P phenotype) { this->phenotype = phenotype;};
    void setState(State state) { this.state = state; };

};

#endif
