/*
 * Binary tree using array
 * without using any cpp feature
 */

#include <iostream>

using namespace std;

class BTArray {
public:
	//define array size
	const static int MAXSIZE = 16;
	char binary_tree_array[MAXSIZE] =  {'\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', '\0', '\0', 'V', '\0', 'J', 'L'};
	int get_right_child_index(const int &);
	int get_left_child_index(const int &);
	int get_parent_index(const int &);
	void perorder(const int &);
	void postorder(const int &);
	void inorder(const int &);
};

/*
 * 		A
 * 	   / \
 * 	  /   \
 * 	 B     C
 *  / \   / \
 * D   F E   G  
 *
 */





// return right child index though parent index
int BTArray::get_right_child_index(const int &index) {
	//parent is not nullptr and right index less than MAXSIZE
	if (binary_tree_array[index] != '\0' && (2*index) + 1 <= MAXSIZE) {
		return (2*index) + 1;
	}

	//right child is nullptr
	return -1;
}

int BTArray::get_left_child_index(const int &index) {
	if (binary_tree_array[index] != '\0' && 2*index <= MAXSIZE) {
		return 2*index;
	}
	return -1;
}

int BTArray::get_parent_index(const int &index) {
	if (binary_tree_array[index] != '\0' && binary_tree_array[index/2] != '\0') {
		return index/2;
	}
	return -1;
}

void BTArray::perorder(const int &index) {
	if (index > 0 && binary_tree_array[index] != '\0') {
		cout << binary_tree_array[index] << " " ;
		perorder(get_left_child_index(index));
		perorder(get_left_child_index(index));
	}
}

void BTArray::postorder(const int &index) {
	if (index > 0 && binary_tree_array[index] != '\0')  {
		postorder(get_left_child_index(index));
		postorder(get_right_child_index(index));
		cout << binary_tree_array[index] << " "; 

	}
}

void BTArray::inorder(const int &index) {
	if (index > 0 && binary_tree_array[index] != '\0') {
		inorder(get_left_child_index(index));
		cout << binary_tree_array[index] << " ";
		inorder(get_right_child_index(index));
	}
}





int main(void) {

	BTArray array;
	array.perorder(1);
}
