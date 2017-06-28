/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef SEQUENTIALINDIVIDUALCOMPLETER_H
#define SEQUENTIALINDIVIDUALCOMPLETER_H

#include "IndividualCompleter.hpp"
#include "../Problem/Decoder.hpp"
#include "../Problem/Evaluator.hpp"
#include "../Individual.hpp"

#include <vector>
#include <iostream>

using namespace std;

template<typename G, typename T, typename P>
class SequentialIndividualCompleter : public IndividualCompleter<G, T, P>{
  protected:
    Decoder<G, P>& decoder;
    Evaluator<T, P>& evaluator;

  public:
    SequentialIndividualCompleter(Decoder<G, P> &  decoder, Evaluator<T, P> & evaluator)
      : decoder(decoder), evaluator(evaluator) {}

    void complete(vector<Individual<G, T, P>> & individuals) {
      int size = individuals.size();

      for (int i = 0; i < size; i++) {
          decode(individuals[i]);
          evaluate(individuals[i]);
      }
    }

    void evaluate(Individual<G, T, P>& individual) {
      P phenotype = individual.getPhenotype();
      Objectives<T> objectives = this->evaluator.evaluate(phenotype);
      individual.setObjectives(objectives);
    }

    void decode(Individual<G, T, P>& individual) {
      G genotype = individual.getGenotype();
      P phenotype = this->decoder.decode(genotype);
      individual.setPhenotype(phenotype);
    }

};

#endif
