template<class T, class Allocator>
void list<T, Allocator>::initialize() {
  head = alloc.allocate(1);
  head->next = alloc.allocate(1);
  tail = head->next;
  tail->prev = head;
}

template<class T, class Allocator>
list<T, Allocator>::list() {
  initialize();
}

template<class T, class Allocator>
list<T, Allocator>::list(const list &rhs) noexcept {
  initialize();
  for (auto &e: rhs) {
    push_back(e->value);
  }
}

template<class T, class Allocator>
list<T, Allocator>::list(list &&rhs) noexcept {
  head = rhs.head;
  tail = rhs.tail;
}

template<class T, class Allocator>
list<T, Allocator>::~list() {
  clear();
  alloc.deallocate(head);
  alloc.deallocate(tail);
}

template<class T, class Allocator>
node<T> *list<T, Allocator>::create_node(const T &value) {
  auto tmp = alloc.allocate(1);
  tmp->value = value;
  tmp->next = nullptr;
  tmp->prev = nullptr;
  return tmp;
}

template<class T, class Allocator>
list<T, Allocator> &list<T, Allocator>::operator=(const list &rhs) {
  clear();
  for (auto &e: rhs) {
    push_back(e->value);
  }
  return *this;
}

template<class T, class Allocator>
typename list<T, Allocator>::allocator_type list<T, Allocator>::get_allocator() {
  return alloc;
}

template<class T, class Allocator>
bool list<T, Allocator>::empty() {
  return head->next == tail;
}

template<class T, class Allocator>
typename list<T, Allocator>::size_type list<T, Allocator>::size() {
  size_type result = 0;
  for (auto &e: *this) {
    ++result;
  }
  return result;
}

template<class T, class Allocator>
void list<T, Allocator>::push_front(T value) {
  auto temp = create_node(value);
  temp->next = head->next;
  temp->next->prev = temp;
  temp->prev = head;
  head->next = temp;
}

template<class T, class Allocator>
void list<T, Allocator>::push_back(T value) {
  auto temp = create_node(value);
  temp->prev = tail->prev;
  temp->prev->next = temp;
  temp->next = tail;
  tail->prev = temp;
}

template<class T, class Allocator>
typename list<T, Allocator>::reference list<T, Allocator>::pop_back() {
  if (head->next != tail)
    return nullptr;
  auto result = tail->prev->value;
  auto temp = tail->prev->prev;
  auto to_delete = tail->prev;
  temp->next = tail;
  tail->prev = temp;
  alloc.deallocate(to_delete);
  return result;
}

template<class T, class Allocator>
void list<T, Allocator>::clear() {
  while (head->next != tail) {
    auto to_delete = head->next;
    head->next = head->next->next;
    head->next->prev = head;
    alloc.deallocate(to_delete);
  }
}

template<class T, class Allocator>
void list<T, Allocator>::assign(list::size_type count, const T &value) {
  // TODO
}

template<class T, class Allocator>
typename list<T, Allocator>::reference list<T, Allocator>::front() {
  return head->next->value;
}

template<class T, class Allocator>
typename list<T, Allocator>::reference list<T, Allocator>::back() {
  return tail->prev->value;
}

template<class T, class Allocator>
typename list<T, Allocator>::const_reference list<T, Allocator>::front() const {
  return head->next->value;
}

template<class T, class Allocator>
typename list<T, Allocator>::const_reference list<T, Allocator>::back() const {
  return tail->prev->value;
}

template<class T, class Allocator>
typename list<T, Allocator>::iterator list<T, Allocator>::begin() {
  return typename list<T, Allocator>::iterator(head->next);
}

template<class T, class Allocator>
typename list<T, Allocator>::const_iterator list<T, Allocator>::begin() const {
  return typename list<T, Allocator>::const_iterator(head->next);
}

template<class T, class Allocator>
typename list<T, Allocator>::const_iterator list<T, Allocator>::cbegin() const {
  return typename list<T, Allocator>::const_iterator(head->next);
}

template<class T, class Allocator>
typename list<T, Allocator>::iterator list<T, Allocator>::end() {
  return typename list<T, Allocator>::iterator(tail);
}

template<class T, class Allocator>
typename list<T, Allocator>::const_iterator list<T, Allocator>::end() const {
  return typename list<T, Allocator>::const_iterator(tail);
}

template<class T, class Allocator>
typename list<T, Allocator>::const_iterator list<T, Allocator>::cend() const {
  return typename list<T, Allocator>::const_iterator(tail);
}

template<class T, class Allocator>
typename list<T, Allocator>::reverse_iterator list<T, Allocator>::rbegin() {
  return typename list<T, Allocator>::reverse_iterator(tail->prev);
}

template<class T, class Allocator>
typename list<T, Allocator>::const_reverse_iterator list<T, Allocator>::rbegin() const {
  return typename list<T, Allocator>::const_reverse_iterator(tail->prev);
}

template<class T, class Allocator>
typename list<T, Allocator>::const_reverse_iterator list<T, Allocator>::crbegin() const {
  return typename list<T, Allocator>::const_reverse_iterator(tail->prev);
}

template<class T, class Allocator>
typename list<T, Allocator>::reverse_iterator list<T, Allocator>::rend() {
  return typename list<T, Allocator>::reverse_iterator(head);
}

template<class T, class Allocator>
typename list<T, Allocator>::const_reverse_iterator list<T, Allocator>::rend() const {
  return typename list<T, Allocator>::const_reverse_iterator(head);
}

template<class T, class Allocator>
typename list<T, Allocator>::const_reverse_iterator list<T, Allocator>::crend() const {
  return typename list<T, Allocator>::const_reverse_iterator(head);
}