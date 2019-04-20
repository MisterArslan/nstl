template<typename T>
reverse_iterator_impl<T>::reverse_iterator_impl(node <T> *node) noexcept :
    current(node) {}

template<typename T>
reverse_iterator_impl <T> &reverse_iterator_impl<T>::operator++() {
  current = current->prev;
  return *this;
}

template<typename T>
reverse_iterator_impl <T> reverse_iterator_impl<T>::operator++(int) {
  auto iterator = *this;
  ++*this;
  return iterator;
}

template<typename T>
reverse_iterator_impl <T> &reverse_iterator_impl<T>::operator--() {
  current = current->next;
  return *this;
}

template<typename T>
reverse_iterator_impl <T> reverse_iterator_impl<T>::operator--(int) {
  auto iterator = *this;
  --*this;
  return iterator;
}

template<typename T>
bool reverse_iterator_impl<T>::operator==(const reverse_iterator_impl &rhs) {
  return current == rhs.current;;
}

template<typename T>
bool reverse_iterator_impl<T>::operator!=(const reverse_iterator_impl &rhs) {
  return current != rhs.current;
}

template<typename T>
typename std::iterator<std::bidirectional_iterator_tag, T>::reference
reverse_iterator_impl<T>::operator*() {
  return current->value;
}