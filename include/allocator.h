#ifndef NSTL_ALLOCATOR_H
#define NSTL_ALLOCATOR_H

#include "size_t.h"
#include "ptrdiff_t.h"

namespace nstl {
    template <class T>
    class allocator {
    public:
        using value_type = T;
        using pointer = T*;
        using const_pointer = const T*;
        using reference = T&;
        using const_reference = const T&;
        using size_type = nstl::size_t;
        using difference_type = nstl::ptrdiff_t;

        allocator() = default;

        allocator(const allocator&) = default;

        template <class U>
        explicit allocator (const allocator<U>&)  {
        }

        pointer allocate (size_type num, const void* = nullptr) {
            auto ret = (pointer)(::operator new(num*sizeof(T)));
            return ret;
        }

        void deallocate (pointer p) {
            ::operator delete((void*)p);
        }

        template <class U>
        struct rebind {
            using other = allocator<U>;
        };

        ~allocator() = default;
    };
}

#endif //NSTL_ALLOCATOR_H
