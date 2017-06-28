/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef TESTCREATOR_H
#define TESTCREATOR_H

#include "../Creator.hpp"
#include "../../Genotype/BooleanGenotype.hpp"

class TestCreator : public Creator<BooleanGenotype> {
  public:
    BooleanGenotype create() {
      BooleanGenotype genotype = BooleanGenotype();
      genotype.init(22);
      return genotype;
    }
};

#endif
