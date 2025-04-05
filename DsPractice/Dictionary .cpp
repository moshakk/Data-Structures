#include<iostream>
#include <cstring>
#include <vector>
#include <type_traits>
using namespace std;
template <typename Tkey, typename Tvalue>
class Dictionary{
	//static_assert(is_class<Tkey>::value, "TKey must be a class type");
private:	
	class keyValuePair {
	private:
		Tkey *_key;
		Tvalue* _value;
	public:
		Tkey* key()const {
			return _key;
		}
		Tvalue* value()const { return _value; }
		void setValue(Tvalue* value) { _value = value; }
		keyValuePair(Tkey* key, Tvalue *val) {
			_key = key;
			_value = val;
		}
	};
	vector<keyValuePair> entries;
	int initialSize;
	int entriesCount;
public:
	Dictionary() {
		initialSize = 3;
		entries.reserve(initialSize);
		entriesCount = 0;
	}
	void ResizeOrNot() {
		if (entriesCount < entries.capacity()) {
			return;
		}
		int newSize = entries.capacity() + initialSize;
		cout << "[resize] from " << entries.capacity() << " to " << newSize << endl;
		vector<keyValuePair> newArray;
		newArray.reserve(newSize);
		for (int i = 0; i < entries.size(); i++) {
			newArray.push_back(entries[i]);
			
		}
		entries = newArray;
	}
	int size() { return entriesCount; }
	void set(Tkey* key, Tvalue* value) {
		for (int i = 0; i < entries.size(); i++) {
			if ( entries[i].key() == key) {
				entries[i].setValue(value);
				return;
			}
		}
		ResizeOrNot();
		keyValuePair newpair(key, value);
		entries.push_back(newpair);
		entriesCount++;
	}
	Tvalue* Get(Tkey* key) {
		for (int i = 0; i < entries.size(); i++) {
			if (entries[i].key() == key) {
				return entries[i].value();
			}
		}
		return nullptr;
	}
	bool remove(Tkey* key) {
		for (int i = 0; i < entries.size(); i++) {
			if (entries[i].key() == key) {
				if (i != entriesCount - 1) {
					entries[i] = entries[entriesCount - 1];
				}
				entries.pop_back();
				entriesCount--;
				return true;
			}
		}
		return false;
	}
	void print() {
		cout << "-------------\n";
		cout << "Size: " << size()<<"\n";
		cout << "Data---->\n";
		for (int i = 0; i < entries.size(); i++) {
			
			cout << *(entries[i].key()) << " : " << *(entries[i].value()) << "\n";

		}
	}
};

