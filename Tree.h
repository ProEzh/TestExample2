#ifndef Tree_h
#define Tree_h

#include <cstddef>
#include <ostream>

struct Node;

class Tree {
private:
	Node* root;
private:
	static Node* find(Node* temp, const char* word, size_t length, size_t index);
	static void compare(Node* temp, const char* word, size_t length, size_t index);
	static Node* findLastLink(Node* temp, const char* word, size_t length, size_t index, Node* lastLink, Node*& prevLastLink);
	static void orderInSubTree(Node* temp, std::ostream& stream);
	static Node* insert_word(Node* temp, const char* word, size_t length, size_t index);
	static void destroy(Node const* temp);
public:
	Tree();
	bool isEmpty() const;
	void insert(const char* word, size_t length, int value);
	void remove(const char* word, size_t length);
	int search(const char* word, size_t length) const;
	void wordCmp(const char* word, size_t length) const;
	~Tree();
};

#endif Tree_h