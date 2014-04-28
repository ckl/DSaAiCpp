#include "stdafx.h"
#include "genDLList.h"

template<class T>
void DoublyLinkedList<T>::addToTail(const T &el) {
	if (tail != NULL) {
		tail = new DLLNode<T>(el, 0, tail);
		tail->prev->next = tail;
	}
	else
		head = tail = new DLLNode<T>(el);
}

template<class T>
T DoublyLinkedList<T>::deleteFromTail() {
	T el = tail->info;

	if (head == tail) { // only one node in list
		delete head;
		head = tail = NULL;
	}
	else {
		tail = tail->prev;
		delete tail->next;
		tail->next = NULL;
	}

	return el;
}