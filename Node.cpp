#include "Node.h"

Node::~Node() {
	delete link;
	delete next;
}
