#ifndef INDIVIDUAL
#define INDIVIDUAL

#include <vector>
using namespace std;

class Individual {
  public:
    double fitness_score;
    vector<bool> cromossome;
  public:
    Individual();
    void evaluate();
    double normalize();
    void mutate(int position);
    vector<vector<bool> > crossover(vector<bool> cromossome2);
    void getCromossomeRepr();
};

#endif
