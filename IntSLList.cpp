#include "stdafx.h"
#include "IntSLList.h"

IntSLLNode::IntSLLNode(int el, IntSLLNode *ptr = 0) {
	info = el;
	next = ptr;
}

IntSLList::IntSLList() {
	head = tail = 0;
}

IntSLList::~IntSLList() {
	for (IntSLLNode *p; !isEmpty(); /**/)
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
	head = new IntSLLNode(el, head);
	if (tail == 0)
		tail = head;
}

void IntSLList::addToTail(int el) {
	if (tail != 0) {	// if the list is not empty
		tail->next = new IntSLLNode(el);
		tail = tail->next;
	}
	else
	{
		// this is the first element being added
		head = tail = new IntSLLNode(el);
	}
}

int IntSLList::deleteFromHead() {
	int el = head->info;
	IntSLLNode *tmp = head;

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
		IntSLLNode *tmp;	// find the predecessor of tail
		for (tmp = head; tmp->next != tail; tmp = tmp->next);
		delete tail;
		tail = tmp;
		tail->next = 0;
	}
	return el;
}

void IntSLList::deleteNode(int el) {
	if (head != NULL) {
		if (head == tail && el == head->info) { // only 1 node in list
			delete head;
			head = tail = NULL;
		}
		else if (el == head->info) { // if el to delete is first node
			IntSLLNode *tmp = head;
			head = head->next;
			delete tmp;
		}
		else {
			IntSLLNode *pred, *tmp;
			for (pred = head, tmp = head->next;
				tmp != NULL && !(tmp->info == el);
				pred = pred->next, tmp = tmp->next);
			
			if (tmp != NULL) {
				pred->next = tmp->next;
				if (tmp == tail)	// adjust tail if we are deleting the tail
					tail = pred;
				delete tmp;
			}
		}
	}
}

bool IntSLList::isInList(int el) const {
	IntSLLNode *tmp;
	for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
	return tmp != 0;
}