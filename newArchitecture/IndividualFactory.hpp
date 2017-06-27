#ifndef INDIVIDUALFACTORY_H
#define INDIVIDUALFACTORY_H

#include "Individual.hpp"
#include "Genotype.hpp"

template<typename G, typename T, typename P>
class IndividualFactory {
  public:
    virtual Individual<G, T, P> create() = 0;
    virtual Individual<G, T, P> create(G genotype) = 0;
};

#endif
