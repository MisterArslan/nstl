#ifndef NSTL_LIST_H
#define NSTL_LIST_H

#include "allocator.h"

namespace nstl{
    template<class T, class A = nstl::allocator<T>>
    class list{
    public:
        list() = default;
        list(const list&) noexcept {

        }
        list(list&& list) noexcept {

        }
        list& operator=(const list& other) noexcept {

        }
        ~list(){

        }
    private:
        struct node {
            T value;
            node *next;
            node *prev;
        };

        node* head;
        node* tail;

        node* newNode(T value){
            node* newNode = new node;
            newNode->value = value;
            newNode->next = nullptr;
            newNode->prev = nullptr;
        }

    };
}

#endif //NSTL_LIST_H
