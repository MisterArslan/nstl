#ifndef NSTL_INCLUDE_INTERNAL_VECTOR_H
#define NSTL_INCLUDE_INTERNAL_VECTOR_H

#include "allocator.h"
#include <iterator>

namespace nstl {
namespace internal {

template<typename T, typename Allocator = allocator<T>>
class vector {
public:
  using value_type = T;
  using allocator_type = typename Allocator::template rebind<node<T>>::other;
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;
  using reference = value_type &;
  using const_reference = const value_type &;
  using pointer = typename Allocator::pointer;
  using const_pointer = typename Allocator::const_pointer;
  using iterator = iterator_impl<T>;
  using const_iterator = iterator_const_impl<T>;
  using reverse_iterator = reverse_iterator_impl<T>;
  using const_reverse_iterator = reverse_iterator_const_impl<T>;
private:
  vector() = default;
  vector(const vector& rhs) noexcept;
  vector(vector&& rhs) noexcept;

};

}
}

#endif //NSTL_INCLUDE_INTERNAL_VECTOR_H
