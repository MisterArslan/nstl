template<typename Iter>
void reverse(Iter begin, Iter end) {
  reverse_impl(begin, end, typename std::iterator_traits<Iter>::iterator_category());
}

template<typename Iter>
void reverse_impl(Iter begin, Iter end, std::random_access_iterator_tag) {
  std::cout << "lel" << std::endl;
}

template<typename Iter>
void reverse_impl(Iter begin, Iter end, std::bidirectional_iterator_tag) {
  std::cout << "kek" << std::endl;
}