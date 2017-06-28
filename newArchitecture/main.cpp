/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#include "Optimizer/OptimizerMediator.hpp"
#include "Config.hpp"

using namespace std;

int main() {
  srand(time(NULL));

  TestCreator testCreator = TestCreator();
  TestDecoder testDecoder = TestDecoder();
  TestEvaluator testEvaluator = TestEvaluator();

  DefaultIndividualFactory<VTypes::G, VTypes::T, VTypes::P> factory = DefaultIndividualFactory<VTypes::G, VTypes::T, VTypes::P>(testCreator);
  SequentialIndividualCompleter<VTypes::G, VTypes::T, VTypes::P> completer = SequentialIndividualCompleter<VTypes::G, VTypes::T, VTypes::P>(testDecoder, testEvaluator);
  SelectorDefault<VTypes::G, VTypes::T, VTypes::P> selector = SelectorDefault<VTypes::G, VTypes::T, VTypes::P>();
  MutateBoolean mutation = MutateBoolean();
  CrossoverBooleanRate cross = CrossoverBooleanRate(1.0);
  MatingCrossoverMutate<VTypes::G, VTypes::T, VTypes::P> mating = MatingCrossoverMutate<VTypes::G, VTypes::T, VTypes::P>(cross, mutation, CROSSOVER_RATE, MUTATION_RATE, factory);
  Population<VTypes::G, VTypes::T, VTypes::P> pop = Population<VTypes::G, VTypes::T, VTypes::P>();
  EvolutionaryAlgorithm<VTypes::G, VTypes::T, VTypes::P> evalg = EvolutionaryAlgorithm<VTypes::G, VTypes::T, VTypes::P>(selector, mating, POPULATION, pop, factory);
  OptimizerMediator<VTypes::G, VTypes::T, VTypes::P> opt = OptimizerMediator<VTypes::G, VTypes::T, VTypes::P>(evalg, pop, completer, MAX_ITERATION);

  double result = opt.optimize();
  cout << result << endl;

  return 0;
}
