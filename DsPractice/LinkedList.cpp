#include<iostream>
using namespace std;
class linkedListNode {
public:
	int data;
	linkedListNode* next;
	linkedListNode(int _data) {
		this->data = _data;
		this->next = NULL;
	}
};
class linkedListIteratort {
private:
	linkedListNode *currentNode;
public:
	linkedListIteratort(linkedListNode* _node) {
		this->currentNode = _node;
	}
	int data() {
		return currentNode->data;
	}
	linkedListIteratort next() {
		currentNode = currentNode->next;
		return *this;
	}
	linkedListNode* current() {
		return currentNode;
	}
};
class linkedList {
public:
	linkedListNode *head=NULL;
	linkedListNode *tail=NULL;
	int lenght = 0;

	linkedListIteratort begin() {
		linkedListIteratort itr(head);
		return itr;
	}
	linkedListNode *find(int _data) {
		for (linkedListIteratort itr = this->begin(); itr.current() != NULL; itr.next()) {
			if (itr.data() == _data) {
				return itr.current();
			}
		}
		return NULL;
	}
	linkedListNode* findParent(linkedListNode *_node) {
		for (linkedListIteratort itr = this->begin(); itr.current() != NULL; itr.next()) {
			if (itr.current()->next == _node) {
				return itr.current();
			}
		}
		return NULL;
	}
	void printList() {
		for (linkedListIteratort itr = this->begin(); itr.current() != NULL; itr.next()) {
			cout << itr.data() << " --> ";
		}
		cout << endl;
	}
	void insertLast(int _data)
	{
		linkedListNode *node = new linkedListNode(_data);
		if (head == NULL) {
			this->head = node;
			this->tail = node;
		}
		else {
			this->tail->next = node;
			this->tail = node;
		}
		this->lenght++;
	}
	void insertAfter(int _data, int _Ndata) {
		linkedListNode* existNode = this->find(_data);
		linkedListNode* node = new linkedListNode(_Ndata);
		node->next = existNode->next;
		existNode->next = node;
		if (node->next == NULL) {
			this->tail = node;
		}
		this->lenght++;
	}
	void insertBefore(int _data, int _Ndata) {
		linkedListNode* node = new linkedListNode(_Ndata);
		linkedListNode* existNode = this->find(_data);
		node->next = existNode;
		linkedListNode* parent = this->findParent(existNode);
		if (parent==NULL) {
			this->head = node;
		}
		else {
			parent->next = node;
		}
		this->lenght++;
	}
	void deleteNode(int _data) {
		linkedListNode* targetNode = this->find(_data);
		if (this->head == this->tail) {
			this->head = NULL;
			this->tail = NULL;
		}
		else if (this->head==targetNode) {
			head=targetNode->next;
		}
		else {
			linkedListNode* parent = this->findParent(targetNode);
			if (this->tail == targetNode) {
				this->tail = parent;
				parent->next = NULL;
			}
			else
			{
				parent->next = targetNode->next;
			}
		}
		delete targetNode;
		this->lenght--;
	}
	void insertHead(int _data) {
		linkedListNode *node = new linkedListNode(_data);
		if (this->head == NULL) {
			this->head = node;
			this->tail = node;
		}
		else {
			node->next = this->head;
			this->head = node;
		}
		this->lenght++;
	}
	void deleteHead() {
		if (head == NULL) {
			return;
		}
		linkedListNode* temp = head;
		this->head = head->next;
		delete temp;

		this->lenght--;

	}
	int getLenght(){
		return this->lenght;
	}
};