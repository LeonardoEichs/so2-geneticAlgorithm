#ifndef DEFAULTINDIVIDUALFACTORY_H
#define DEFAULTINDIVIDUALFACTORY_H

#include "IndividualFactory.hpp"
#include "Individual.hpp"
#include "Genotype.hpp"
#include "Problem/Creator.hpp"

template<typename G, typename T, typename P>
class DefaultIndividualFactory : public IndividualFactory<G, T, P>{
  protected:
    Creator<G> & creator;
  public:
    DefaultIndividualFactory(Creator<G>& creator) : creator(creator){}
    Individual<G, T, P> create() {
      G genotype = this->creator.create();
      Individual<G, T, P> indv = Individual<G, T, P>(genotype);
      return indv;
    };

    Individual<G, T, P> create(G genotype) {
      Individual<G, T, P> indv = Individual<G, T, P>(genotype);
      return indv;
    };

};

#endif
