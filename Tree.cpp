#include "Tree.h"
#include "Node.h"
#include <iostream>
#include <cassert>

Tree::Tree() {
	root = nullptr;
}

bool Tree::isEmpty() const {
	return !root;
}

//рекурсивный обход поддерева для поиска листьев и вывода их значений
void Tree::orderInSubTree(Node* temp, std::ostream& stream) { 
	if (!temp)
		return;
	if (temp->hasValue) 
		stream << temp->value << ' ';
	orderInSubTree(temp->next, stream);
	orderInSubTree(temp->link, stream);
}
//вспомогательная функция вставки элемента в дерево
Node* Tree::insert_word(Node* temp, const char* word, size_t length, size_t index) {
	assert(word && index < length);
	if (!temp) {
		return nullptr;
	}
	if (temp->key != word[index]) {
		if (temp->link) {
			return insert_word(temp->link, word, length, index);
		}
		else {
			temp->link = new Node(word[index]);
			temp = temp->link;
			index++;
			for (size_t i = index; i < length; i++) {
				temp->next = new Node(word[i]);
				temp = temp->next;
			}
			return temp;
		}
	}
	else {
		index++;
		if (index < length) {
			if (temp->next) {
				return insert_word(temp->next, word, length, index);
			}
			else {
				for (size_t i = index; i < length; i++) {
					temp->next = new Node(word[i]);
					temp = temp->next;
				}
				return temp;
			}
		}
		else {
			return temp;
		}
	}
}

//вспомогательная функция поиска элемента в дереве
Node* Tree::find(Node* temp, const char* word, size_t length, size_t index) {
	assert(word && index < length);
	if (!temp) {
		return nullptr;
	}
	if (temp->key == word[index]) {			
		index++;
		if (index == length) {
			if (temp->hasValue) {
				return temp;
			}
			else
				return nullptr;
		}
		else {
			if (temp->next) {
				return find(temp->next, word, length, index);
			}
			else
				return nullptr;
		}
	}
	else {
		if (temp->link) {
			return find(temp->link, word, length, index);
		}
		else {
			return nullptr;
		}
	}
}

//вспомогательная функция сравнения слов в дереве
void Tree::compare(Node* temp, const char* word, size_t length, size_t index) {
	assert(word && index < length);
	if (!temp) {
		return;
	}
	if (temp->key == word[index]) {
		index++;
		if (index == length) {
			if (temp->next) {
				std::ostream& stream(std::cout);//
				orderInSubTree(temp->next, stream);
			}
			if (temp->link)
				compare(temp->link, word, length, --index);
		}
		else {
			if (temp->next) {
				compare(temp->next, word, length, index);
			}
			if (temp->link) {
				compare(temp->link, word, length, --index);
			}
		}
	}
	else if (temp->key < word[index]) {
		if (temp->link) {
			compare(temp->link, word, length, index);
		}
		else
			return;
	}
	else { //(temp->key > word[index]) 
		if (temp->hasValue)
			std::cout << temp->value << ' ';
		if (temp->next) {
			std::ostream& stream(std::cout);
			orderInSubTree(temp->next, stream);
		}
		if (temp->link)
			compare(temp->link, word, length, index);
	}
}

//вспомогательная функция поиска последней и предпоследней ссылки для удаления всех элементов в диапазоне
Node* Tree::findLastLink(Node* temp, const char* word, size_t length, size_t index, Node* lastLink, Node*& prevLastLink) {
	assert(word && index < length);
	if (!temp) {
		return nullptr;
	}
	if (temp->key == word[index]) {
		index++;
		if (index == length && temp->hasValue)
			return lastLink;
		else {
			if (temp->link || temp->hasValue) {
				if (lastLink != temp) {
					prevLastLink = lastLink;
				}
				lastLink = temp;
			}
			return findLastLink(temp->next, word, length, index, lastLink, prevLastLink);
		}
	}
	else {
		if (temp->link) {
			if (lastLink != temp) {
				prevLastLink = lastLink;
			}
			lastLink = temp->link;
			return findLastLink(temp->link, word, length, index, lastLink, prevLastLink);
		}
		else {
			std::cout << "Something wrong" << std::endl;
			return lastLink;
		}
	}
}

void Tree::destroy(Node const* temp)
{
	if (temp) {
		destroy(temp->link);
		destroy(temp->next);
		delete temp;
	}
}

//метод вставки
void Tree::insert(const char* word, size_t length, int value) {
	if (length == 0)
		return;
	if (isEmpty()) {
		size_t index = 0;
		root = new Node(word[index]);
		index++;
		Node* temp = root;
		for (size_t i = index; i < length; i++) {
			temp->next = new Node(word[i]);
			temp = temp->next;
		}
		temp->hasValue = true;
		temp->value = value;
		return;
	}
	Node* temp = root;
	size_t index = 0;
	temp = insert_word(temp, word, length, index);
	temp->hasValue = true;
	temp->value = value;
}

//метод удаления
void Tree::remove(const char* word, size_t length) {
	if (isEmpty() || length == 0) {
		std::cout << "Tree or word is empty" << std::endl;
		return;
	}
	Node* temp = root;
	Node* lastLink = root;
	Node* prevLastLink = nullptr;
	int index = 0;
	Node* wordIsExist = find(temp, word, length, index);
	if (wordIsExist) {
		if (wordIsExist->next) {
			wordIsExist->hasValue = false;
			return;
		}
		else {
			temp = root;
			lastLink = findLastLink(temp, word, length, index, lastLink, prevLastLink);
			temp = lastLink;
			if (wordIsExist == root || lastLink == root) {
				if (lastLink->link) {
					root = lastLink->link;
					lastLink->link = nullptr;
					delete lastLink;
				}
				else
					delete lastLink;
				return;
			}
			if (!temp->hasValue && temp->link) {
				if (prevLastLink->next != temp) {
					prevLastLink = prevLastLink->next;
					prevLastLink->link = temp->link;
				}
				else {
					if (!temp->hasValue) {
						prevLastLink->next = temp->link;
					}
				}
			}
			if (temp->hasValue) {
				lastLink = lastLink->next;
				temp->next = nullptr;
				temp = lastLink;
			}
			lastLink->link = nullptr;
			delete lastLink;
		}
	}
	else {
		std::cout << "Tree is not containing this word" << std::endl;
		return;
	}
}

//метод поиска
int Tree::search(const char* word, size_t length) const{
	if (isEmpty() || length == 0) {
		std::cout << "Tree or word is empty" << std::endl;
		return -1;
	}
	Node* temp = root;
	int index = 0;
	Node* result = find(temp, word, length, index);
	if (result) {
		std::cout << result->value << ' ';
		return result->value;
	}
	else {
		std::cout << -1 << ' ';
		return -1;
	}
}

//метод сравнения
void Tree::wordCmp(const char* word, size_t length) const {
	if (isEmpty() || length == 0) {
		std::cout << "Tree or word is empty" << std::endl;
		return;
	}
	Node* temp = root;
	size_t index = 0;
	compare(temp, word, length, index);
}

Tree::~Tree() {
	destroy(root);
}