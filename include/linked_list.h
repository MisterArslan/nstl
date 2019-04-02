#include <iostream>

namespace nstl {
    template <typename T>
    struct linked_list {
        T key = 0;
        linked_list* next = nullptr;
    };

    template <typename T>
    linked_list<T>* reverse(linked_list<T>* head) {
        if (!head || !head->next) return nullptr;
        auto tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        auto first = head;
        auto second = head->next;
        bool done = false;
        while (!done) {
            if (first->next == second) {
                first->next = tail->next;
                tail->next = first;
                first = second->next;
            }
            else {
                second->next = tail->next;
                tail->next = second;
                second = first->next;
            }
            done = (first == tail && first->next == second)
                || (second == tail && second->next == first);
        }
        return tail;
    };

    template <typename T>
    void print(linked_list<T>* head) {
        auto temp = head;
        while (temp) {
            std::cout << temp->key << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}