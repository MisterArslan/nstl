template<class T>
iterator_impl<T>::iterator_impl(node <T> *node) noexcept :
    current(node) {}

template<class T>
iterator_impl <T> &iterator_impl<T>::operator++() {
  current = current->next;
  return *this;
}

template<class T>
iterator_impl <T> iterator_impl<T>::operator++(int) {
  auto iterator = *this;
  ++*this;
  return iterator;
}

template<typename T>
iterator_impl <T> &iterator_impl<T>::operator--() {
  current = current->prev;
  return *this;
}

template<typename T>
iterator_impl <T> iterator_impl<T>::operator--(int) {
  auto iterator = *this;
  --*this;
  return iterator;
}

template<typename T>
bool iterator_impl<T>::operator==(const iterator_impl <T> &rhs) {
  return current == rhs.current;;
}

template<class T>
bool iterator_impl<T>::operator!=(const iterator_impl <T> &rhs) {
  return current != rhs.current;
}

template<class T>
typename std::iterator<std::bidirectional_iterator_tag, T>::reference
iterator_impl<T>::operator*() {
  return current->value;
}
