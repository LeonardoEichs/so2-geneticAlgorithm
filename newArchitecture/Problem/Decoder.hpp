#ifndef DECODER_H
#define DECODER_H

#include <type_traits>
#include "../Genotype.hpp"

template<typename G, typename P>
class Decoder {
  static_assert(std::is_base_of<Genotype, G>::value, "Decoder must be a Genotype");
  public:
    P decode(G genotype) = 0;
};

#endif
