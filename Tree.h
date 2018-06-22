#pragma once
#include "Node.h"
#include <iostream>
class Tree {
private:
	Node* root;
public:
	friend Node* find(Node* temp, char* word, size_t length, size_t index);
	friend void compare(Node* temp, char* word, size_t length, size_t index);
	friend Node* findLastLink(Node* temp, char* word, size_t length, size_t index, Node* lastLink, Node*& prevLastLink);
	friend void orderInSubTree(Node* temp);
	friend Node* insert_word(Node* temp, char* word, size_t length, size_t index);
	Tree();
	Tree(Node* elem);
	bool isEmpty();
	void insert(char* word, size_t length, int value);
	void remove(char* word, size_t length);
	int search(char* word, size_t length);
	void wordCmp(char* word, size_t length);
	~Tree();
};

