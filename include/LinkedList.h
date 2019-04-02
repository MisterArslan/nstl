struct LinkedList {
	int Key = 0;
	LinkedList* Next = nullptr;
};

void transfer(LinkedList*& first, LinkedList*& second, LinkedList*& end);
LinkedList* reverse(LinkedList* head);
void Print(LinkedList* list);