template<typename T, typename Allocator>
vector<T, Allocator>::vector(vector::size_type size)
  : m_size(0), m_capacity(size) {
  tab = alloc.allocate(m_capacity);
}

template<typename T, typename Allocator>
vector<T, Allocator>::vector(vector::size_type size, value_type value)
    : m_size(size), m_capacity(size) {
  tab = alloc.allocate(m_capacity);
  for(auto i = 0; i < m_size; i++) {
    tab[i] = value;
  }
}

template<typename T, typename Allocator>
vector<T, Allocator>::vector(const std::initializer_list<T> &init)
    : m_size(init.size()), m_capacity(init.size()) {
  tab = alloc.allocate(m_capacity);
  for (auto i = 0; i < m_size; i++) {
    tab[i] = *(init.begin() + i);
  }
}

template<typename T, typename Allocator>
vector<T, Allocator>::vector(const vector &rhs) noexcept
    : m_size(rhs.m_size), m_capacity(rhs.m_capacity) {
  tab = alloc.allocate(m_capacity);
  for (auto i = 0; i < m_size; i++) {
    tab[i] = rhs.tab[i];
  }
}

template<typename T, typename Allocator>
vector<T, Allocator>::vector(vector &&rhs) noexcept
    : m_size(rhs.m_size), m_capacity(rhs.m_capacity), tab(rhs.tab) {}

template<typename T, typename Allocator>
vector<T, Allocator>::~vector() {
  alloc.deallocate(tab);
}

template<typename T, typename Allocator>
vector<T, Allocator> &vector<T, Allocator>::operator=(const vector &rhs) {
  clear();
  m_capacity = rhs.m_capacity;
  m_size = rhs.m_size;
  for (auto i = 0; i < m_size; i++) {
    tab[i] = rhs[i];
  }
  return *this;
}

template<typename T, typename Allocator>
vector<T, Allocator> &vector<T, Allocator>::operator=(vector &&rhs) {
  clear();
  m_capacity = rhs.m_capacity;
  m_size = rhs.m_size;
  for (auto i = 0; i < m_size; i++) {
    tab[i] = rhs[i];
  }
  return *this;
}

template<typename T, typename Allocator>
void vector<T, Allocator>::assign(vector::size_type count, const_reference value) {
  if (count > m_capacity) {
    alloc.deallocate(tab);
    m_capacity *= 2;
    tab = alloc.allocate(m_capacity);
  }
  if (count > m_size) {
    m_size = count;
  }
  for (auto i = 0; i < count; i++) {
    tab[i] = value;
  }
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::allocator_type vector<T, Allocator>::get_allocator() const {
  return alloc;
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::at(vector::size_type pos) {
  return tab[pos];
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::at(vector::size_type pos) const {
  return tab[pos];
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::operator[](vector::size_type pos) {
  return tab[pos];
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::operator[](vector::size_type pos) const {
  return tab[pos];
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::front() {
  return tab[0];
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::front() const {
  return tab[0];
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::back() {
  return tab[m_size - 1];
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::back() const {
  return tab[m_size - 1];
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::pointer vector<T, Allocator>::data() {
  return tab;
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::const_pointer vector<T, Allocator>::data() const {
  return tab;
}

template<typename T, typename Allocator>
bool vector<T, Allocator>::empty() const {
  return m_size == 0;
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::size_type vector<T, Allocator>::size() const {
  return m_size;
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::size_type vector<T, Allocator>::capacity() const {
  return m_capacity;
}

template<typename T, typename Allocator>
void vector<T, Allocator>::shrink_to_fit() {
  auto new_tab = alloc.allocate(m_size);
  for (int i = 0; i < m_size; i++) {
    new_tab[i] = tab[i];
  }
  alloc.deallocate(tab);
  tab = new_tab;
  m_capacity = m_size;
}

template<typename T, typename Allocator>
void vector<T, Allocator>::clear() {
  alloc.deallocate(tab);
  tab = alloc.allocate(m_capacity);
  m_size = 0;
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(vector::iterator pos, const_reference value) {
  if (m_size < m_capacity) {
    auto iter = end();
    for (auto i = end(); i != pos; i--) {
      *i = *(--iter);
    }
    *pos = value;
    m_size += 1;
    return pos;
  }
  else {
    m_capacity *= 2;
    auto new_tab = alloc.allocate(m_capacity);
    auto iter = vector<T, Allocator>::iterator(new_tab);
    for (auto i = begin(); i != pos; i++, iter++) {
      *iter = *i;
    }
    auto temp = iter;
    ++iter;
    for (auto i = pos; i != end(); i++, iter++) {
      *iter = *i;
    }
    *temp = value;
    alloc.deallocate(tab);
    tab = new_tab;
    m_size += 1;
    return iter;
  }
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::pop_back() {
  auto tmp = back();
  alloc.deallocate(back());
  --m_size;
  return tmp;
}

template<typename T, typename Allocator>
void vector<T, Allocator>::push_back(T &&value) {
  if (m_size >= m_capacity) {
    m_capacity *= 2;
    auto new_tab = alloc.allocate(m_capacity);
    for (auto i = 0; i < m_size; i++) {
      new_tab[i] = tab[i];
    }
    alloc.deallocate(tab);
    tab = new_tab;
  }
  tab[m_size] = value;
  ++m_size;
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::begin() {
  return typename vector<T, Allocator>::iterator(tab);
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::end() {
  return typename vector<T, Allocator>::iterator(tab + m_size);
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::begin() const {
  return typename vector<T, Allocator>::iterator(tab);
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::end() const {
  return typename vector<T, Allocator>::iterator(tab + m_size);
}

template<typename T, typename Allocator>
void vector<T, Allocator>::resize(vector::size_type count) {
  auto new_tab = alloc.allocate(count);
  if (m_size < count) {
    for (auto i = 0; i < m_size; i++) {
      new_tab[i] = tab[i];
    }
  }
  else {
    for (auto i = 0; i < count; i++) {
      new_tab[i] = tab[i];
    }
  }
  alloc.deallocate(tab);
  tab = new_tab;
  m_size = count;
  m_capacity = count;
}

template<typename T, typename Allocator>
void vector<T, Allocator>::resize(vector::size_type count, const_reference value) {
  auto new_tab = alloc.allocate(count);
  if (m_size < count) {
    for (auto i = 0; i < m_size; i++) {
      new_tab[i] = tab[i];
    }
    for (auto i = m_size; i < count; i++) {
      new_tab[i] = value;
    }
  }
  else {
    for (auto i = 0; i < count; i++) {
      new_tab[i] = tab[i];
    }
  }
  alloc.deallocate(tab);
  tab = new_tab;
  m_size = count;
  m_capacity = count;
}
