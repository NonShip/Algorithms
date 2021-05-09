#include "Hash.hpp"

Hash::Hash() {
	for (int i = 0; i < tablesize; i++) {
		HashTable[i] = new item;
		HashTable[i]->key = "";
		HashTable[i]->value = "";
		HashTable[i]->next = nullptr;
	}
}

int Hash::hashFun(string key) {
	int sum = 0;
	int index = key.size();

	for (int i = 0; i < index; i++) {
		sum += static_cast<int>(key[i]);
	}

	return sum % tablesize;

}

void Hash::Additem(string key, string value) {
	int index = hashFun(key);

	if (HashTable[index]->key == "") {
		HashTable[index]->value = value;
		HashTable[index]->key = key;
	}
	else {
		item *ptr = HashTable[index];

		item *n = new item;
		n->key = key;
		n->value = value;
		n->next = nullptr;

		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}

		ptr->next = n;
	}
}

int Hash::NumberOfItemIndex(int index) {
	int count = 0;

	if (HashTable[index]->key == "") {
		return count;
	}
	else {
		count++;
		item* ptr = HashTable[index];

		while (ptr->next != nullptr) {
			count++;
			ptr = ptr->next;
		}
	}

	return count;
}

void Hash::PrintTable(void) {
	int number;
	cout << "------------" << endl;
	for (int i = 0; i < tablesize; i++) {
		number = NumberOfItemIndex(i);
		cout << "i = " << i << ": " << endl;
		cout << "======================\n";
		cout << "items number: " << number << endl;
		cout << "=====================\n";
	}
}

void Hash::PrintIndexInItem(int index) {
	item *ptr = HashTable[index];
	if (ptr->key == "") {
		cout << "index = " << index << " is empty" << endl;
	}
	else {
		cout << "-----key--------" << endl;
		cout << ptr->key << endl;
		ptr = ptr->next;
		while (ptr->next != nullptr) {
			cout << "-----next key-------" << endl;
			cout << ptr->key << endl;
			cout << "----next value------" << endl;
			cout << ptr->value << endl;
			cout << "--------------------" << endl;
			ptr = ptr->next;
		}
	}
}

void Hash::find(string key) {
	int index = hashFun(key);
	string re;
	bool flag = false;

	item *ptr = HashTable[index];
	while (ptr != nullptr) {
		if(ptr->key == key) {
		   flag = true;
	   		re = ptr->value;
		}
		ptr = ptr->next;
	}
	if (flag) {
		cout << "find key: " << key << " value: " << re << endl;
	}
	else {
		cout << "don't find key: " << key << endl;
	}

	
}	







int main(void) {
	Hash hash;

	hash.Additem("yang","fan");
	hash.Additem("yang", "fang");

	hash.Additem("Paul", "Locha");
	hash.Additem("Kim", "Iced Mocha");
	hash.Additem("Anni", "Strawberry Smoothy");
	hash.Additem("Sara", "Passion Tea");
	hash.Additem("Mike", "Tea");
	hash.Additem("steve", "Apple cider");
	hash.Additem("Sill", "Root beer");
	hash.Additem("Bill", "Lochs");
	hash.Additem("Susan", "Cola");
	hash.Additem("Joe", "Green Tea");
	int index = hash.hashFun("yang");

	hash.find("yan");



}
