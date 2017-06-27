#include "Genotype/SelectGenotype.hpp"
#include "Genotype/IntegerGenotype.hpp"
#include "Genotype/BooleanGenotype.hpp"
#include "Genotype/DoubleGenotype.hpp"
#include "Genotype/BooleanMapGenotype.hpp"
#include "Optimizer/Population.hpp"
#include "Optimizer/SequentialIndividualCompleter.hpp"
#include "Operator/Mutate/MutateBoolean.hpp"
#include "Operator/Crossover/CrossoverBooleanRate.hpp"
#include "Optimizer/EA/SelectorDefault.hpp"
#include "Optimizer/EA/MatingCrossoverMutate.hpp"
#include "Optimizer/EA/EvolutionaryAlgorithm.hpp"
#include "Optimizer/OptimizerMediator.hpp"
#include "Individual.hpp"
#include "DefaultIndividualFactory.hpp"
#include "Objectives.hpp"
#include "Objective.hpp"
#include "Config.hpp"
#include "Problem/Test/TestCreator.hpp"
#include "Problem/Test/TestDecoder.hpp"
#include "Problem/Test/TestEvaluator.hpp"

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

  return 1;
}
