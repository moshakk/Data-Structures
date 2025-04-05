#include<iostream>
//#include "LinkedList.cpp"
//#include "StackBasedArray.cpp"
//#include "Queue.cpp"
//#include"Dictionary .cpp"
#include"ArrDictionary.cpp"
using namespace std;

int main() {
   /* string key1 = "name";
    string value1 = "John";

    string key2 = "age";
    string value2 = "30";

    string key3 = "city";
    string value3 = "New York";

    string key4 = "country";
    string value4 = "USA";
    string key5 = "Sinar";
    string value5 = "sinar@gmail.com";
    string key6 = "Elvis", value6 = "elvis@gmail.com";
    Dictionary<string, string> dict;
    cout << "adding\n";
    dict.set(&key1, &value1);
    dict.set(&key2, &value2);
    dict.set(&key3, &value3);
    cout << "The Data \n: ";
    dict.print();
    dict.set(&key5, &value5);
    dict.set(&key6,&value6);
    dict.print();
    dict.remove(&key3);
    dict.print();
    dict.remove(&key1);
    dict.print();*/
    
    ArrDictionary<int, string>dict;
    dict.set(1, "Ahmed");
    dict.set(2, "hello");
    dict.set(3, "ismaliaa");
    dict.print();
    //dict.Remove(1);
    dict.set(1, "egypt");
    dict.set(5, "alexandria");
    dict.set(6, "banana");
    dict.print();
	return 0;
}