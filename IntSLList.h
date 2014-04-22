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
	void addToHead(int);
	void addToTail(int);
	int deleteFromHead();	// deletes the head and returns its info
	int deleteFromTail();	// deletes the tail and returns its info
	bool isInList(int) const;

private:
	IntNode *head, *tail;
};

#endif /* INT_LINKED_LIST */