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

