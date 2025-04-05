#include <iostream>
#include <cstring>

using namespace std;
template <typename Tkey,typename Tvalue>
class ArrDictionary {
private:
	class KeyValuePair {
	private:
		Tkey _key;
		Tvalue _value;
	public:
		Tkey key() { return _key; }
		Tvalue getValue() { return _value; }
		void setValue(Tvalue value) {
			_value = value;
		}
		KeyValuePair() {} 

		KeyValuePair(Tkey key,Tvalue value) {
			this->_key = key;
			this->_value = value;
		}
	};
	KeyValuePair *entiries;
	int entriesCount, initialSize, capacity;
public:
	ArrDictionary() {
		initialSize = 3;
		capacity = initialSize;
		entiries = new KeyValuePair[capacity];
		entriesCount = 0;
	}
	void ResizeOrNot() {
		if (entriesCount < capacity) {
			return;
		}
		int newcapacity = capacity + initialSize;
		KeyValuePair* newEntries = new KeyValuePair[newcapacity];
		for (int i = 0; i < entriesCount; i++) {
			newEntries[i] = entiries[i];
		}
		delete[] entiries;
		entiries = newEntries;
		capacity = newcapacity;

		cout << "[resize] from " << capacity - initialSize << " to " << capacity << endl;
	}
	int size() {
		return entriesCount;
	}
	void set(Tkey key, Tvalue value) {
		for (int i = 0; i < entriesCount; i++) {
			if (entiries[i].key() == key) {
				entiries[i].setValue(value);
				return;
			}
		}
		ResizeOrNot();
		KeyValuePair newPair(key, value);
		entiries[entriesCount] = newPair;
		entriesCount++;
	}
	Tvalue Get(Tkey key) {
		for (int i = 0; i < entriesCount; i++) {
			if (entiries[i].key() == key) {
				return entiries[i].getValue();
			}
		}
		return Tvalue();
	}
	bool Remove(Tkey key) {
		for (int i = 0; i < entriesCount; i++) {
			if (entiries[i].key() == key) {
				entiries[i] = entiries[entriesCount - 1];
				entriesCount--;
				return true;
			}

		}
		return false;
	}
	void print() {
		cout << "-------------\n";
		cout << "Size: " << size() << "\n";
		for (int i = 0; i < entriesCount; i++) {
			cout << entiries[i].key() << " : " << entiries[i].getValue() << "\n";
		}
	}



	

};