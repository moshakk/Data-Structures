#include<iostream>
using namespace std;
class Stack{
private:
	int* dataList;
	int topIndex;
	int intialSize;
	int currentSize;
public:
	Stack() {
		this->intialSize = 5;
		this->dataList = new int[this->intialSize];
		this->currentSize = this->intialSize;
		this->topIndex = -1;
	}
	void resizeOrNot() {
		if (this->topIndex < this->currentSize - 1) return;
		cout << "will Be Resized. \n";
		int* newArray = new int[this->intialSize + this->currentSize];
		copy(this->dataList, this->dataList+this->currentSize, newArray); //
		this->currentSize += this->intialSize;
		delete []this->dataList;
		this->dataList = newArray;
						
	}
	void push(int _data) {
		this->resizeOrNot();
		this->dataList[++topIndex] = _data;
	}
	int peek() {
		if (this->topIndex == -1) {
			throw runtime_error("Stack Is Empty ");
		}
		return this->dataList[this->topIndex];
	}
	int pop() {
		if (this->topIndex == -1) {
			throw runtime_error("Stack Is Empty ");
		}
		int headData = this->dataList[this->topIndex];
		this->topIndex--;
		return headData;
	}
	bool isEmpty() {
		return this->topIndex == -1;
	}
	int size() {
		return this->topIndex + 1;
	}
	void print() {
		for (int i = this->topIndex; i >= 0; i--) {
			cout << dataList[i] << "-->";
			
		}
		
		cout << endl;
	}





};
