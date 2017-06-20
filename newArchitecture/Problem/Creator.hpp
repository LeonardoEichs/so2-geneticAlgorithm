#ifndef CREATOR_H
#define CREATOR_H

#include <type_traits>
#include "../Genotype.hpp"

template<typename G>
class Creator {
  static_assert(std::is_base_of<Genotype, G>::value, "Creator must be a Genotype");
  public:
    G create() = 0;
};

#endif
