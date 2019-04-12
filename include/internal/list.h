#ifndef NSTL_INTERNAL_LIST_H
#define NSTL_INTERNAL_LIST_H

#include "allocator.h"
#include <iterator>

namespace nstl {
namespace internal {

template<class T, class Allocator = allocator<T>>
class list;

template <typename T>
struct node {
  T value;
  node<T> *next;
  node<T> *prev;
};

template <typename T>
class iterator_impl {
private:
  node<T> *current;
public:
  using iterator_category = std::bidirectional_iterator_tag;
  using value_type = typename list<T>::value_type;
  using difference_type = typename list<T>::difference_type;
  using pointer = typename list<T>::pointer;
  using reference = typename list<T>::reference;
  using const_reference = typename list<T>::const_reference;

  explicit iterator_impl(node<T> *node) noexcept;
  iterator_impl &operator++();
  iterator_impl operator++(int);
  bool operator!=(const iterator_impl &iterator);
  reference operator*();
  const_reference operator*() const;
};

template<class T, class Allocator>
class list {
public:
  using value_type = T;
  using allocator_type = typename Allocator::template rebind<node<T>>::other;
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;
  using reference = value_type &;
  using const_reference = const value_type &;
  using pointer = typename Allocator::pointer;
  using const_pointer = typename Allocator::const_pointer;
  using iterator = iterator_impl<T>;
  using const_iterator = int;
  using reverse_iterator = int;
  using const_reverse_iterator = int;
private:
  allocator_type alloc;
  node<T> *head = nullptr;
  node<T> *tail = nullptr;

  node<T> *createnode(const T &value);

public:

  list() = default;

  list(const list &rhs) noexcept;

  list(list
       &&rhs) noexcept;

  ~list();

  list &operator=(const list &);

  void assign(size_type count, const T &value);

  allocator_type get_allocator();

  reference front();

  reference back();

  const_reference front() const;

  const_reference back() const;

  iterator begin();

  const_iterator begin() const;

  const_iterator cbegin() const;

  iterator end();

  const_iterator end() const;

  const_iterator cend() const;

  reverse_iterator rbegin();

  const_reverse_iterator rbegin() const;

  const_reverse_iterator crbegin() const;

  reverse_iterator rend();

  const_reverse_iterator rend() const;

  const_reverse_iterator crend() const;

  bool empty();

  size_type size();

  void push_front(T value);

  void push_back(T value);

  node<T> *pop_back();

  void clear();
};
template<class T>
iterator_impl<T>::iterator_impl(node<T> *node) noexcept :
    current(node) {}

template<class T>
iterator_impl<T> &iterator_impl<T>::operator++() {
  if (current)
    current = current->next;
  return *this;
}
template<class T>
iterator_impl<T> iterator_impl<T>::operator++(int) {
  auto iterator = *this;
  ++*this;
  return iterator;
}
template<class T>
bool iterator_impl<T>::operator!=(const iterator_impl<T> &iterator) {
  return current != iterator.current;
}

template<class T>
typename iterator_impl<T>::reference iterator_impl<T>::operator*() {
  return current->value;
}

template<class T>
typename iterator_impl<T>::const_reference iterator_impl<T>::operator*() const {
  return current->value;
}

template<class T, class Allocator>
node<T> *list<T, Allocator>::createnode(const T &value) {
  auto tmp = alloc.allocate(1);
  tmp->value = value;
  tmp->next = nullptr;
  tmp->prev = nullptr;
  return tmp;
}

template<class T, class Allocator>
list<T, Allocator>::list(const list &rhs) noexcept {
  auto temp = rhs.head;
  while (temp) {
    push_back(temp->value);
    temp = temp->next;
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
}

template<class T, class Allocator>
list<T, Allocator> &list<T, Allocator>::operator=(const list &) {
  clear();
  auto temp = list::front();
  while (temp) {
    push_back(temp->value);
    temp = temp->next;
  }
  return *this;
}

template<class T, class Allocator>
typename list<T, Allocator>::allocator_type list<T, Allocator>::get_allocator() { return alloc; }

template<class T, class Allocator>
bool list<T, Allocator>::empty() {
  return head == nullptr;
}

template<class T, class Allocator>
typename list<T, Allocator>::size_type list<T, Allocator>::size() {
  size_type result = 0;
  auto temp = front();
  while (temp) {
    ++result;
    temp = temp->next;
  }
  return result;
}

template<class T, class Allocator>
void list<T, Allocator>::push_front(T value) {
  if (head) {
    auto temp = createnode(value);
    temp->next = head;
    head = temp;
  } else {
    head = createnode(value);
    tail = head;
  }
}

template<class T, class Allocator>
void list<T, Allocator>::push_back(T value) {
  if (tail) {
    tail->next = createnode(value);
    tail = tail->next;
  } else {
    head = createnode(value);
    tail = head;
  }
}

template<class T, class Allocator>
node<T> *list<T, Allocator>::pop_back() {
  auto temp = head;
  while (temp && temp->next != tail) {
    temp = temp->next;
  }
  alloc.deallocate(tail);
  tail = temp;
}

template<class T, class Allocator>
void list<T, Allocator>::clear() {
  while (head) {
    auto to_delete = head;
    head = head->next;
    alloc.deallocate(to_delete);
  }
}

template<class T, class Allocator>
void list<T, Allocator>::assign(list::size_type count, const T &value) {

}

template<class T, class Allocator>
typename list<T, Allocator>::reference list<T, Allocator>::front() {
  return head->value;
}

template<class T, class Allocator>
typename list<T, Allocator>::reference list<T, Allocator>::back() {
  return tail->value;
}

template<class T, class Allocator>
typename list<T, Allocator>::const_reference list<T, Allocator>::front() const {
  return head->value;
}

template<class T, class Allocator>
typename list<T, Allocator>::const_reference list<T, Allocator>::back() const {
  return tail->value;
}

template<class T, class Allocator>
typename list<T, Allocator>::iterator list<T, Allocator>::begin() {
  return typename list<T, Allocator>::iterator(head);
}

template<class T, class Allocator>
typename list<T, Allocator>::iterator list<T, Allocator>::end() {
  return typename list<T, Allocator>::iterator(tail->next);
}
}
}

#endif //NSTL_INTERNAL_LIST_H
