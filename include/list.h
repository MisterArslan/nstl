#ifndef NSTL_LIST_H
#define NSTL_LIST_H

#include "allocator.h"

namespace nstl{
    template<class T, class Allocator = nstl::allocator<T>>
    class list {
    private:
        struct node {
            T value;
            node *next;
            node *prev;
        };
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

        node* front() {return head;}
        node* back() {return tail;}

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

        ~list(){

        }
    private:
        node* head;
        node* tail;

        node* createNode(T value){
            node* newNode = new node;
            newNode->value = value;
            newNode->next = nullptr;
            newNode->prev = nullptr;
        }
    };
}

#endif //NSTL_LIST_H
