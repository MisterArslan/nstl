#ifndef NSTL_INCLUDE_INTERNAL_SORT_H
#define NSTL_INCLUDE_INTERNAL_SORT_H

namespace nstl {
namespace internal {

template <typename Iter, typename Func = std::less<typename std::iterator_traits<Iter>::value_type>>
void bubble_sort (Iter begin, Iter end, Func func = Func()) {
  using std::swap;
  for (auto l = begin; l != end; l++) {
    for (auto r = l; r != end; r++) {
      if (func(*r, *l)) {
        swap(*l, *r);
      }
    }
  }
}

}
}

#endif //NSTL_INCLUDE_INTERNAL_SORT_H
