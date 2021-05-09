#ifndef HASH_HPP
#define HASH_HPP


#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct item {
	string key;
	string value;
	item *next;
};

class Hash {
public:
	int hashFun(string key);
	Hash();
	
	void Additem(string key, string value);
	int NumberOfItemIndex(int index);
	void PrintTable(void);
	void PrintIndexInItem(int index);

	const static int tablesize = 10;
	item *HashTable[tablesize];
	void find(string key);
};



#endif
