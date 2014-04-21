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
}

int IntSLList::isEmpty() {
	return head == 0;
}