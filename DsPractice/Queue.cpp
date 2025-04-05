#include<iostream>
#include "LinkedList.cpp"
using namespace std;
class Queue {
private:
	linkedList *list;
public:
	Queue() {
		this->list = new linkedList();
	}
	void enqueue(int _data) {
		this->list->insertLast(_data);
	}
	int dequeue() {
		if (this->isEmpty()) {
			cout << "Cannot peek an empty list\n";
			return -1; // Or any other sentinel value
		}
			int nodeData = this->list->head->data;
			this->list->deleteHead();
			return nodeData;
		
	}
	int peek() {
		if (this->isEmpty()) {
			cout << "Cannot peek an empty list\n";
			return -1; // Or any other sentinel value
		}
		return  this->list->head->data;
	}
	bool isEmpty() {
		if (this->list->getLenght() == 0) {
			return true;
		}
		else
		{
			return false;
		}
	}
	int size() {
		return this->list->getLenght();
	}
	void print() {
		this->list->printList();
	}
};