template<typename T>
vector_iter<T>::vector_iter(vector_iter::pointer tab) noexcept {
  m_tab = tab;
}

template<typename T>
vector_iter<T> &vector_iter<T>::operator++() {
  ++m_tab;
  return *this;
}

template<typename T>
vector_iter<T> vector_iter<T>::operator++(int) {
  auto iterator = *this;
  ++*this;
  return iterator;
}

template<typename T>
vector_iter<T> &vector_iter<T>::operator--() {
  --m_tab;
  return *this;
}

template<typename T>
vector_iter<T> vector_iter<T>::operator--(int) {
  auto iterator = *this;
  --*this;
  return iterator;
}

template<typename T>
bool vector_iter<T>::operator==(const vector_iter &rhs) {
  return m_tab == rhs.m_tab;
}

template<typename T>
bool vector_iter<T>::operator!=(const vector_iter &rhs) {
  return m_tab != rhs.m_tab;
}

template<typename T>
typename vector_iter<T>::reference vector_iter<T>::operator*() {
  return *m_tab;
}
