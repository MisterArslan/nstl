#ifndef NSTL_LIST_H
#define NSTL_LIST_H

#include "allocator.h"

namespace nstl{
    template<class T, class Allocator = nstl::allocator<T>>
    class list {
    public:
        using value_type = T;
        using allocator_type = Allocator;
        //size_type
        //difference_type
        using reference = value_type&;
        using const_reference = const value_type&;
        //using pointer = Allocator::pointer;
        //using const_pointer = Allocator::const_pointer;
        //iterator
        //const_iterator
        //reverse_iterator
        //const_reverse_iterator
    private:
        struct node {
            T value;
            node *next;
            node *prev;
        };

        Allocator alloc;
        node* head;
        node* tail;

        node* createNode(T value){
            node* newNode = alloc::allocate(1);
            newNode->value = value;
            newNode->next = nullptr;
            newNode->prev = nullptr;
        }
    public:
        list() = default;
        list(const list&) noexcept {
            auto temp = list::front();
            while(temp) {
                push_back(temp->value);
                temp = temp->next;
            }
        }
        list(list&& list) noexcept {
            this = list;
        }
        ~list(){
            clear();
        }

        void operator=(const list&) {
            clear();
            auto temp = list::front();
            while(temp) {
                push_back(temp->value);
                temp = temp->next;
            }
        }

        void assign(size_type count, const T& value) {

        }

        Allocator get_allocator() {return alloc;}

        node* front() {return head;}

        node* back() {return tail;}

        bool empty() {
            return head == nullptr;
        }

        size_type size() {
            size_type result = 0;
            auto temp = front();
            while(temp) {
                ++result;
                temp = temp->next;
            }
            return result;
        }

        void push_front(T value) {
            if (head) {
                auto temp = createNode(value);
                temp->next = head;
                head = temp;
            } else {
                head = createNode(value);
                tail = head;
            }
        }

        void push_back(T value) {
            if (tail) {
                tail->next = createNode(value);
            } else {
                head = createNode(value);
                tail = head;
            }
        }

        node* pop_back() {
            auto temp = head;
            while(temp && temp->next != tail) {
                temp = temp->next;
            }
            alloc::deallocate(tail);
            tail = temp;
        }

        void clear() {
            while (head) {
                auto to_delete = head;
                head = head->next;
                alloc::deallocate(to_delete);
            }
        }

    };
}

#endif //NSTL_LIST_H
