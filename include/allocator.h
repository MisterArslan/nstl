#ifndef NSTL_ALLOCATOR_H
#define NSTL_ALLOCATOR_H

namespace nstl {
    template <class T>
    class allocator {
    public:
        typedef T value_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef int size_type; // td::size_t
        typedef int difference_type; // std::ptrdiff_t

        template <class U>
        struct rebind {
            typedef allocator<U> other;
        };

        pointer address (reference value) const {
            return &value;
        }
        const_pointer address (const_reference value) const {
            return &value;
        }

        allocator() throw() {
        }
        allocator(const allocator&) throw() {
        }
        template <class U>
        allocator (const allocator<U>&) throw() {
        }
        ~allocator() throw() {
        }

        size_type max_size () const throw() {
            //return std::numeric_limits<std::size_t>::max() / sizeof(T);
            return 2147483647 / sizeof(T);
        }

        pointer allocate (size_type num, const void* = nullptr) {
            auto ret = (pointer)(::operator new(num*sizeof(T)));
            return ret;
        }

        void construct (pointer p, const T& value) {
            new((void*)p)T(value);
        }

        void destroy (pointer p) {
            p->~T();
        }

        void deallocate (pointer p, size_type num) {
            ::operator delete((void*)p);
        }
    };

    template <class T1, class T2>
    bool operator== (const allocator<T1>&,
                     const allocator<T2>&) throw() {
        return true;
    }
    template <class T1, class T2>
    bool operator!= (const allocator<T1>&,
                     const allocator<T2>&) throw() {
        return false;
    }
}

#endif //NSTL_ALLOCATOR_H
