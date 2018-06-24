#ifndef Node_h
#define Node_h

struct Node {
	char key;
	int value;
	bool hasValue;
	Node* link;
	Node* next;
	Node(char _key) : key(_key), value(0), hasValue(false), link(nullptr), next(nullptr) {}
	Node(const Node& source) = delete;
	Node& operator=(const Node& source) = delete;
	Node(Node&&) = delete;
	Node& operator=(Node&& source) = delete;
	~Node();
};

#endif Node_h