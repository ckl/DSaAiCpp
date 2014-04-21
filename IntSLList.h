#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST


class IntNode {
public:
	int info;
	IntNode *next;

	IntNode(int el, IntNode *ptr);
};

class IntSLList {
public:
	IntSLList();
	~IntSLList();

	int isEmpty();

private:
	IntNode *head, *tail;
};

#endif /* INT_LINKED_LIST */