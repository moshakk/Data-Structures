#include<iostream>
#include "LinkedList.cpp"
using namespace std;
class stack {
private:
	linkedList dataList;
public:
	stack() {

	}
	void push(int _data) {
		this->dataList.insertHead(_data);
		
	}
	int pop() {
		int headData = this->dataList.head->data;
		this->dataList.deleteHead();
		return headData;
	}
	int peek() {
		return this->dataList.head->data;
	}
	bool isEmpty() {
		return this->dataList.getLenght() == 0;
	}
	int size() {
		return this->dataList.getLenght();
	}
	void printList() {
		return dataList.printList();
	}
};