#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST


class IntSLLNode {
public:
	int info;
	IntSLLNode *next;

	IntSLLNode(int el, IntSLLNode *ptr);
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
	void deleteNode(int el);
	bool isInList(int) const;

private:
	IntSLLNode *head, *tail;
};

#endif /* INT_LINKED_LIST */