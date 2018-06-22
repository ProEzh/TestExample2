#pragma once
class Node {
private:
	char key;
	int value;
	bool isLeaf;
	Node* link;
	Node* next;
public:
	Node() = default;
	Node(char key_, Node* link_, Node* next_) : key(key_), link(nullptr), next(nullptr) {}
	Node(const Node& source);
	Node& operator=(const Node& source);
	char getKey() { return key; }
	void setKey(char symbol) { key = symbol; }
	Node* getLink() { return link; }
	void setLink(Node* elem) { link = elem; }
	Node* getNext() { return next; }
	void setNext(Node* elem) { next = elem; }
	bool getIsLeaf() { return isLeaf; }
	void setIsLeaf(bool flag) { isLeaf = flag; }
	int getValue() { return value; }
	void setValue(int v) { value = v; }
	~Node();
};

