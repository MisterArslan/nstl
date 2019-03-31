#include "LinkedList.h"

int main()
{
	LinkedList* head = new LinkedList;
	head->Key = 1;
	LinkedList* temp = head;
	for (int i = 2; i < 11; i++) {
		temp->Next = new LinkedList;
		temp->Next->Key = i;
		temp = temp->Next;
	}
	Print(reverse(head));
}