#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

template<class T>
class DLLNode {
public:
	DLLNode();
	DLLNode(const T&, DLLNode *n = NULL, DLLNode *p = NULL);
	T info;
	DLLNode *next, *prev;
};

template<class T>
class DoublyLinkedList {
public:
	DoublyLinkedList();
	void addToTail(const T&);
	T deleteFromTail();

protected:
	DLLNode<T> *head, *tail;
};

#endif /* DOUBLY_LINKED_LIST */