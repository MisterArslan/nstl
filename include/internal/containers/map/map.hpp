#ifndef NSTL_INTERNAL_MAP_HPP
#define NSTL_INTERNAL_MAP_HPP

#include "allocator.hpp"

namespace nstl {
namespace internal {

template <typename Key, typename T>
class node {
public:
    using key_type = Key;
    using mapped_type = T;
};

template <
    typename Key, typename T,
    typename Compare = std::less<Key>,
    typename Allocator = std::allocator<std::pair<const Key, T>>
>
class map {
public:
    using key_type = Key;
    using mapped_type = T;
    using value_type = std::pair<Key, T>;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = std::allocator_traits<Allocator>::pointer;
    using const_pointer = std::allocator_traits<Allocator>::const_pointer;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using key_compare = Compare;
    using allocator_type = Allocator;

    map() {

    }

private:

};

} /* internal */
} /* nstl */

#endif /* NSTL_INTERNAL_MAP_HPP */
