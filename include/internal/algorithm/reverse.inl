template<typename Iter>
void reverse(Iter begin, Iter end) {
  reverse_impl(begin, end, typename std::iterator_traits<Iter>::iterator_category());
}

template<typename Iter>
void reverse_impl(Iter begin, Iter end, std::bidirectional_iterator_tag) {
  using std::swap;
  auto distance = std::distance(begin, end);
  auto l = begin;
  auto r = --end;
  for (int i = 0; i < distance / 2; i++) {
    swap(*l, *r);
    ++l;
    --r;
  }
}
