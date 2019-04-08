#include "linked_list.h"
#include <iostream>

int main() {
    nstl::linked_list<int>* head = new nstl::linked_list<int>;
    head->key = 1;
    nstl::linked_list<int>* temp = head;
    for (int i = 2; i < 11; i++) {
        temp->next = new nstl::linked_list<int>;
        temp->next->key = i;
        temp = temp->next;
    }
    print(reverse(head));
}
