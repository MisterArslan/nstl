#include "LinkedList.h"
#include <iostream>

void transfer(LinkedList*& first, LinkedList*& second, LinkedList*& end) {
	if (first->Next == second) {
		first->Next = end->Next;
		end->Next = first;
		first = second->Next;
	}
	else {
		second->Next = end->Next;
		end->Next = second;
		second = first->Next;
	}
}

LinkedList* reverse(LinkedList* head) {
	if (!head->Next || !head->Next->Next) return nullptr;
	auto end = head;
	while (end->Next) {
		end = end->Next;
	}
	auto first = head;
	auto second = head->Next;
	do {
		transfer(first, second, end);
	} while (first != end && second != end);
	transfer(first, second, end);
	return end;
}

void Print(LinkedList * list) {
	auto temp = list;
	while (temp) {
		std::cout << temp->Key << " ";
		temp = temp->Next;
	}
	std::cout << std::endl;
}
