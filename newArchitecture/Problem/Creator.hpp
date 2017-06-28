/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef CREATOR_H
#define CREATOR_H

#include <type_traits>
#include "../Genotype.hpp"

template<typename G>
class Creator {
  static_assert(std::is_base_of<Genotype, G>::value, "Must be a Genotype");
  public:
    virtual G create() = 0;
};

#endif
