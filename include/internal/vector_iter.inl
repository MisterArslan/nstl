template<typename T, typename V>
vector_iter<T, V>::vector_iter(vector_iter::size_type index) noexcept {
  current = index;
}

template<typename T, typename V>
vector_iter<T, V> &vector_iter<T, V>::operator++() {
  ++current;
}

template<typename T, typename V>
vector_iter<T, V> vector_iter<T, V>::operator++(int) {
  ++current;
}

template<typename T, typename V>
vector_iter<T, V> &vector_iter<T, V>::operator--() {
  --current;
}

template<typename T, typename V>
vector_iter<T, V> vector_iter<T, V>::operator--(int) {
  --current;
}

template<typename T, typename V>
bool vector_iter<T, V>::operator==(const vector_iter &rhs) {
  return current == rhs.current;
}

template<typename T, typename V>
bool vector_iter<T, V>::operator!=(const vector_iter &rhs) {
  return current != rhs.current;
}

template<typename T, typename V>
typename std::iterator<std::bidirectional_iterator_tag, T>::reference vector_iter<T, V>::operator*() {
  return tab[index];
}

