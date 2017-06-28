/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef OPERATOR_H
#define OPERATOR_H

#include <type_traits>
#include "../Genotype.hpp"

template<typename G>
class Operator {
  static_assert(std::is_base_of<Genotype, G>::value, "Must be a Genotype");
};

#endif
