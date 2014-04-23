#include "stdafx.h"
#include "IntSLList.h"

IntNode::IntNode(int el, IntNode *ptr = 0) {
	info = el;
	next = ptr;
}

IntSLList::IntSLList() {
	head = tail = 0;
}

IntSLList::~IntSLList() {
	for (IntNode *p; !isEmpty(); /**/)
	{
		p = head->next;
		delete head;
		head = p;
	}
}

int IntSLList::isEmpty() {
	return head == 0;
}

void IntSLList::addToHead(int el) {
	head = new IntNode(el, head);
	if (tail == 0)
		tail = head;
}

void IntSLList::addToTail(int el) {
	if (tail != 0) {	// if the list is not empty
		tail->next = new IntNode(el);
		tail = tail->next;
	}
	else
	{
		// this is the first element being added
		head = tail = new IntNode(el);
	}
}

int IntSLList::deleteFromHead() {
	int el = head->info;
	IntNode *tmp = head;

	if (head == tail) {		// only one node in the list
		head = tail = 0;
	}
	else {
		head = head->next;
	}
	delete tmp;
	return el;
}

int IntSLList::deleteFromTail() {
	int el = tail->info;
	if (head == tail) {
		delete head;
		tail = head = 0;
	}
	else {
		IntNode *tmp;	// find the predecessor of tail
		for (tmp = head; tmp->next != tail; tmp = tmp->next);
		delete tail;
		tail = tmp;
		tail->next = 0;
	}
	return el;
}