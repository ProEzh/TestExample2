#include "Tree.h"

Tree::Tree() {
	root = nullptr;
}

Tree::Tree(Node* elem) {
	root = elem;
}

bool Tree::isEmpty() {
	if (!root)
		return true;
	return false;
}

void orderInSubTree(Node* temp) {
	if (temp->getIsLeaf()) {
		std::cout << temp->getValue() << ' ';
		if (temp->getNext() != nullptr && temp->getLink() != nullptr) {
			orderInSubTree(temp->getNext());
			orderInSubTree(temp->getLink());
		}
		else if (temp->getNext() != nullptr && temp->getLink() == nullptr) {
			orderInSubTree(temp->getNext());
		}
		else if (temp->getLink() != nullptr && temp->getNext() == nullptr) {
			orderInSubTree(temp->getLink());
		}
		else
			return;
	}
	else {
		if (temp->getNext() != nullptr && temp->getLink() != nullptr) {
			orderInSubTree(temp->getNext());
			orderInSubTree(temp->getLink());
		}
		else if (temp->getNext() != nullptr && temp->getLink() == nullptr) {
			orderInSubTree(temp->getNext());
		}
		else if (temp->getLink() != nullptr && temp->getNext() == nullptr) {
			orderInSubTree(temp->getLink());
		}
		else
			return;
	}
}

Node* insert_word(Node* temp, char* word, size_t length, size_t index) {
	if (temp->getKey() != word[index]) {
		if (temp->getLink() != nullptr) {
			return insert_word(temp->getLink(), word, length, index);
		}
		else {
			temp->setLink(new Node(word[index], nullptr, nullptr));
			temp = temp->getLink();
			index++;
			for (size_t i = index; i < length; i++) {
				temp->setNext(new Node(word[i], nullptr, nullptr));
				temp = temp->getNext();
			}
			return temp;
		}
	}
	else {
		index++;
		if (index < length) {
			if (temp->getNext() != nullptr) {
				return insert_word(temp->getNext(), word, length, index);
			}
			else {
				for (size_t i = index; i < length; i++) {
					temp->setNext(new Node(word[i], nullptr, nullptr));
					temp = temp->getNext();
				}
				return temp;
			}
		}
		else {
			return temp;
		}
	}
}

Node* find(Node* temp, char* word, size_t length, size_t index) {
	if (temp->getKey() == word[index]) {			
		index++;
		if (index == length && temp->getIsLeaf() == true)
			return temp;
		else {
			if (temp->getNext() != nullptr) {
				return find(temp->getNext(), word, length, index);
			}
			else
				return nullptr;
		}
	}
	else {
		if (temp->getLink() != nullptr) {
			return find(temp->getLink(), word, length, index);
		}
		else {
			return nullptr;
		}
	}
}

void compare(Node* temp, char* word, size_t length, size_t index) {
	if (temp->getKey() == word[index]) {
		index++;
		if (index == length && temp->getIsLeaf()) {
			if (temp->getNext() != nullptr) {
				compare(temp->getNext(), word, length, index);
			}
			if (temp->getLink() != nullptr)
				compare(temp->getLink(), word, length, --index);
			
			return;
		}
		else if (index == length && !temp->getIsLeaf()) {
			if (temp->getNext() != nullptr)
				orderInSubTree(temp->getNext());
			if (temp->getLink() != nullptr)
				compare(temp->getLink(), word, length, --index);
		}
		else {
			if (temp->getNext() == nullptr && temp->getLink() == nullptr) {
				return;
			}
			if (temp->getNext() != nullptr) {
				compare(temp->getNext(), word, length, index);
			}
			if (temp->getLink() != nullptr) {
				compare(temp->getLink(), word, length, --index);
			}
			
			return;
		}
	}
	else if (temp->getKey() < word[index]) {
		if (temp->getLink() != nullptr) {
			compare(temp->getLink(), word, length, index);
		}
		else
			return;
	}
	else { //(temp->getKey() > word[index]) 
		if (temp->getIsLeaf())
			std::cout << temp->getValue() << ' ';
		if (temp->getNext() != nullptr)
			orderInSubTree(temp->getNext());
		if (temp->getLink() != nullptr)
			compare(temp->getLink(), word, length, --index);
	}
}

Node* findLastLink(Node* temp, char* word, size_t length, size_t index, Node* lastLink, Node*& prevLastLink) {
	if (temp->getKey() == word[index]) {
		index++;
		if (index == length && temp->getIsLeaf() == true)
			return lastLink;
		else {
			if (temp->getLink() != nullptr || temp->getIsLeaf() == true) {
				if (lastLink != temp) {
					prevLastLink = lastLink;
				}
				lastLink = temp;
			}
			//if (temp->getNext() != nullptr) {
			return findLastLink(temp->getNext(), word, length, index, lastLink, prevLastLink);
			//}
			//else
				//return nullptr;
		}
	}
	else {
		if (temp->getLink() != nullptr) {
			if (lastLink != temp) {
				prevLastLink = lastLink;
			}
			lastLink = temp->getLink();
			return findLastLink(temp->getLink(), word, length, index, lastLink, prevLastLink);
		}
		else {
			std::cout << "Something wrong" << std::endl;
			return lastLink;
		}
	}
}

void Tree::insert(char* word, size_t length, int value) {
	if (length == 0)
		return;
	if (isEmpty()) {
		size_t index = 0;
		root = new Node(word[index], nullptr, nullptr);
		index++;
		Node* temp = root;
		for (size_t i = index; i < length; i++) {
			temp->setNext(new Node(word[i], nullptr, nullptr));
			temp = temp->getNext();
		}
		temp->setIsLeaf(true);
		temp->setValue(value);
		return;
	}
	Node* temp = root;
	size_t index = 0;
	temp = insert_word(temp, word, length, index);
	temp->setIsLeaf(true);
	temp->setValue(value);
}

void Tree::remove(char* word, size_t length) {
	if (isEmpty() || length == 0) {
		std::cout << "Tree or word is empty" << std::endl;
		return;
	}
	Node* temp = root;
	Node* lastLink = root;
	Node* prevLastLink = nullptr;
	int index = 0;
	Node* wordIsExist = find(temp, word, length, index);
	if (wordIsExist != nullptr) {
		if (wordIsExist->getNext() != nullptr) {
			wordIsExist->setIsLeaf(false);
			return;
		}
		else {
			temp = root;
			lastLink = findLastLink(temp, word, length, index, lastLink, prevLastLink);
			temp = lastLink;
			if (!temp->getIsLeaf() && temp->getLink() != nullptr) {
				if (prevLastLink->getNext() != temp) {
					prevLastLink = prevLastLink->getNext();
					prevLastLink->setLink(temp->getLink());
				}
				else {
					if (temp->getIsLeaf()) {
						
					}
					else {
						prevLastLink->setNext(temp->getLink());
					}
				}
				//prevLastLink->setLink(temp->getLink());
			}
			if (temp->getIsLeaf()) {
				lastLink = lastLink->getNext();
				temp->setNext(nullptr);
				temp = lastLink;
			}
			while (lastLink != wordIsExist) {
				lastLink = lastLink->getNext();
				delete temp;
				temp = lastLink;
			}
			delete wordIsExist;
		}
	}
	else {
		std::cout << "Tree is not containing this word" << std::endl;
		return;
	}
}

int Tree::search(char* word, size_t length) {
	if (isEmpty() || length == 0) {
		std::cout << "Tree or word is empty" << std::endl;
		return -1;
	}
	Node* temp = root;
	int index = 0;
	Node* result = find(temp, word, length, index);
	if (result != nullptr) {
		std::cout << result->getValue() << ' ';
		return result->getValue();
	}
	else {
		std::cout << -1 << ' ';
		return -1;
	}
}

void Tree::wordCmp(char* word, size_t length) {
	if (isEmpty() || length == 0) {
		std::cout << "Tree or word is empty" << std::endl;
		return;
	}
	Node* temp = root;
	int index = 0;
	compare(temp, word, length, index);//
}

Tree::~Tree() {
}


