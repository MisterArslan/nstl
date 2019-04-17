#ifndef NSTL_INCLUDE_INTERNAL_VECTOR_H
#define NSTL_INCLUDE_INTERNAL_VECTOR_H

#include "allocator.h"
#include <iterator>

namespace nstl {
namespace internal {

template<typename T, typename Allocator = allocator<T>>
class vector {
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
  using const_iterator = iterator_const_impl<T>;
  using reverse_iterator = reverse_iterator_impl<T>;
  using const_reverse_iterator = reverse_iterator_const_impl<T>;
private:
  allocator_type alloc;
  pointer tab;
  size_type m_size;
  size_type m_capacity;
public:
  vector();
  explicit vector(size_type size);
  explicit vector(size_type size, value_type value);
  vector(const std::initializer_list<T> &init);
  vector(const vector &rhs) noexcept;
  vector(vector &&rhs) noexcept;
  ~vector();
  vector& operator=(const vector &rhs );
  vector& operator=(vector&& rhs);
  void assign(size_type count, const_reference value);
  template<typename InputIt>
  void assign(InputIt first, InputIt last);
  allocator_type get_allocator() const;
  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  reference front();
  const_reference front() const;
  reference back();
  const_reference back() const;
  pointer data();
  const_pointer data() const;
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
  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  size_type capacity() const;
  void shrink_to_fit();
  void clear();
  iterator insert(const_iterator pos, const_reference value);
  iterator insert(const_iterator pos, T&& value);
  iterator insert(const_iterator pos, size_type count, const_reference value);
  template<typename InputIt>
  iterator insert(const_iterator pos, InputIt first, InputIt last);
  iterator insert(const_iterator pos, std::initializer_list<T> ilist);
  template<typename... Args>
  iterator emplace(const_iterator pos, Args&&... args);
  iterator erase(const_iterator pos);
  iterator erase(const_iterator first, const_iterator last);
  void push_back(T &&value);
  template<typename... Args>
  void emplace_back(Args&&... args);
  void pop_back();
  void resize(size_type count);
  void resize(size_type count, const_reference value);
  void swap(vector& other);
};

#include "vector.inl"

}
}

#endif //NSTL_INCLUDE_INTERNAL_VECTOR_H
