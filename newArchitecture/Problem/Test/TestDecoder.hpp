/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef TESTDECODER_H
#define TESTDECODER_H

#include <vector>
#include "../../Genotype.hpp"
#include "../../Genotype/BooleanGenotype.hpp"
#include "../Decoder.hpp"


class TestDecoder: public Decoder<BooleanGenotype, double> {
  public:
    double bin_to_int(vector<bool> bit_seq) {
      double num = 0;
      int j;
      for (int i = 0; i < bit_seq.size(); i++) {
        j = bit_seq.size() - 1 - i;
        num += ((int) bit_seq[j]) * pow(2, i);
      }
      return num;
    }

    double decode(BooleanGenotype genotype) {
      return -1 + (2+1)*(bin_to_int(genotype.getGenotype())/(pow(2, 22) - 1));
    }
};

#endif
