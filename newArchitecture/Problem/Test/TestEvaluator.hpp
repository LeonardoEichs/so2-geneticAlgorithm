/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef TESTEVALUATOR_H
#define TESTEVALUATOR_H

#include "../../Objectives.hpp"
#include "../Evaluator.hpp"
#include <iostream>

using namespace std;

class TestEvaluator: public Evaluator<double, double> {
  public:
    Objectives<double> evaluate(double phenotype) {
      double fitness_score = phenotype * sin(10*M_PI*phenotype) + 1.0;

      Objectives<double> objectives = Objectives<double>();
      objectives.add("objective", Objective::MIN, fitness_score);
      return objectives;

    }
};

#endif
