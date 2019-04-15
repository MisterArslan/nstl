template<typename T, typename Allocator>
vector<T, Allocator>::vector()
    : tab(nullptr), _size(), _capacity() {}

template<typename T, typename Allocator>
vector<T, Allocator>::vector(vector::size_type size)
  : _size(size), _capacity(size) {
  tab = new T[_size];
}

template<typename T, typename Allocator>
vector<T, Allocator>::vector(vector::size_type size, value_type value)
    : _size(size), _capacity(size) {
  tab = new T[_size];
  for(auto i = 0; i < _size; i++) {
    tab[i] = value;
  }
}

template<typename T, typename Allocator>
vector<T, Allocator>::vector(const std::initializer_list<T> &init)
    : _size(init.size()), _capacity(init.size()) {
  tab = new T[_size];
  for (auto i = 0; i < _size; i++) {
    tab[i] = *(init.begin() + i);
  }
}

template<typename T, typename Allocator>
vector<T, Allocator>::vector(const vector &rhs) noexcept
    : _size(rhs._size), _capacity(rhs._capacity) {
  tab = new T[_capacity];
  for (auto i = 0; i < _size; i++) {
    tab[i] = rhs.tab[i];
  }
}

template<typename T, typename Allocator>
vector<T, Allocator>::vector(vector &&rhs) noexcept
    : _size(rhs._size), _capacity(rhs._capacity), tab(rhs.tab) {}

