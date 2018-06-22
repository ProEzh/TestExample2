#include "Node.h"

Node::Node(const Node& source) {
	key = source.key;
	if (source.link) {
		link = new Node();
		link->key = source.link->key;
		link->link = source.link->link;
		link->next = source.link->next;
	}
	else
		link = nullptr;
	if (source.next) {
		next = new Node();
		next->key = source.next->key;
		next->link = source.next->link;
		next->next = source.next->next;
	}
	else
		next = nullptr;
}

Node& Node::operator=(const Node& source) {
	if (this == &source)
		return *this;
	delete[] link;
	delete[] next;
	key = source.key;
	if (source.link) {
		link = new Node();
		link->key = source.link->key;
		link->link = source.link->link;
		link->next = source.link->next;
	}
	else
		link = nullptr;
	if (source.next) {
		next = new Node();
		next->key = source.next->key;
		next->link = source.next->link;
		next->next = source.next->next;
	}
	else
		next = nullptr;
	return *this;
}

Node::~Node() {
	delete[] this;
}
