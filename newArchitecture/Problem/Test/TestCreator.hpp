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
