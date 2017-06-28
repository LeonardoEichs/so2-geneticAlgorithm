/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/
#ifndef INDIVIDUAL
#define INDIVIDUAL

#include <vector>
using namespace std;

class Individual {
  public:
    // Score of the individual
    double fitness_score;
    // Array of bits that represent an individual
    vector<bool> cromossome;
  public:
    // Creates a random cromossome and evaluates
    Individual();
    // Normalize the value of the cromossome to be used in the evaluate function
    double normalize();
    // Function responsible for assigning a score to the individual
    void evaluate();
    // Mutation operation, invert the value of a bit
    void mutate(int position);
    // Crossover operation
    vector<vector<bool> > crossover(vector<bool> cromossome2);
    // Display the cromossome
    void getCromossomeRepr();
};

#endif
