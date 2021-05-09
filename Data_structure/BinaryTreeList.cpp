/*
 * a simple binary tree using list
 */
#include <iostream>
using namespace std;

struct node {
	node() = default;
	node(char a): data(a){};

	char data;
	node *left = nullptr;
	node *right = nullptr;
	node *parent = nullptr;
};

class BTList {
public:
	BTList() = default;
	BTList(char a) {
		root = new node(a);
	}
	~BTList() {
		delete root;
	}
	node *root; 

};


int main(void) {
	BTList btl('A');
    cout << btl.root->data << " "; 


}

