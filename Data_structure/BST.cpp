/*
 * a simple binary search tree
 * implemention using cpp
 */

#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node() = default;

	Node(int d){
		data = d;
		left = nullptr;
		right = nullptr;
	}
};


Node *serch(Node *root, int key) {
	if (root == nullptr || root->data == key) {
		return root;
	}

	if (root->data < key) {
		return serch(root->right, key);
	}
		return serch(root->left, key);
}

Node *insert(Node *root, int key) {
	if (root == nullptr) {
		return new Node(key);
	}
	else {
		Node *tmp;
		if (key <=  root->data) {
			tmp = insert(root->left, key);
			root->left = tmp;
		}
		else {
			tmp = insert(root->right, key);
			root->right = tmp;
		}

		return root;
	}
}

Node *deletenode(Node *root, int key) {
	if (root == nullptr) {
		return root;
	}

	if (root->data > key) {
		root->left = deletenode(root->left, key);
		return root;
	}
	else if (root->data < key) {
		root->right = deletenode(root->right, key);
		return root;
	}

	if (root->left == nullptr) {
		Node *tmp = root->right;
		delete root;
		return tmp;
	}
	else if (root->right == nullptr) {
		Node *tmp = root->left;
		delete root;
		return tmp;
	}
	else {
		Node *parent = root;
		Node *succ = root->right;
		//find minium node in root->right
		while (succ->left != nullptr) {
			parent= succ;
			succ = succ->left;
		}

		if (parent != root) {
			parent->left = succ->right;
		}
		else {
			parent->right = succ->right;
		}
		root->data = succ->data;

		delete succ;
		return root;

	}
}



int main(void) {
	Node *p = new Node(1);
	Node *p1 = insert(p, 2);

}

