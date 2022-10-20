#ifndef NSTL_INTERNAL_ALLOCATOR_HPP
#define NSTL_INTERNAL_ALLOCATOR_HPP

#include <cstddef>

namespace nstl {
namespace internal {

template<class T>
class allocator {
public:
  using value_type = T;
  using pointer = T *;
  using const_pointer = const T *;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;

  allocator() = default;

  allocator(const allocator &) = default;

  template<class U>
  explicit allocator(const allocator<U> &) {
  }

  pointer allocate(size_type num, const void * = nullptr) {
    auto ret = (pointer) (::operator new(num * sizeof(T)));
    return ret;
  }

  void deallocate(pointer p) {
    ::operator delete((void *) p);
  }

  template<class U>
  struct rebind {
    using other = allocator<U>;
  };

  ~allocator() = default;
};

} /* internal */
} /* nstl */

#endif /* NSTL_INTERNAL_ALLOCATOR_HPP */
