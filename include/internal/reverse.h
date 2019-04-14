#ifndef NSTL_INTERNAL_REVERSE_H
#define NSTL_INTERNAL_REVERSE_H

#include <iterator>
#include <iostream>
#include <utility>

namespace nstl {
namespace internal {

template<typename Iter>
void reverse(Iter begin, Iter end);

template<typename Iter>
void reverse_impl(Iter begin, Iter end, std::bidirectional_iterator_tag);

template<typename Iter>
void reverse_impl(Iter begin, Iter end, std::random_access_iterator_tag);

#include "reverse.inl"
}
}
#endif //NSTL_INTERNAL_REVERSE_H
