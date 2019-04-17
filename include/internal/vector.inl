template<typename T, typename Allocator>
vector<T, Allocator>::vector()
    : tab(nullptr), m_size(), m_capacity() {}

template<typename T, typename Allocator>
vector<T, Allocator>::vector(vector::size_type size)
  : m_size(size), m_capacity(size) {
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
  alloc.deallocate(m_capacity);
  alloc.deallocate(m_size);
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
    tab[i] = *value;
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
  return tab[m_size];
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::back() const {
  return tab[m_size];
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
  for (auto i = m_size; i < m_capacity; i++) {
    alloc.deallocate(tab[i]);
  }
  m_capacity = m_size;
}

template<typename T, typename Allocator>
void vector<T, Allocator>::clear() {
  alloc.deallocate(tab);
  tab = alloc.allocate(m_capacity);
  m_size = 0;
}

template<typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(vector::const_iterator pos, const_reference value) {
  //todo
}

