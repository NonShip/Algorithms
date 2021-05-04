#ifndef SORT_HPP
#define SORT_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
class Sort {
	public:
		virtual void sort(vector<T>&) = 0;
		void show(vector<T> &);
	   	void issort(vector<T> &);
};

template<typename T>
void Sort<T>::show(vector<T> & array) {
	for (auto t : array) {
		cout << t << " ";
	}
	cout << endl;
}

template<typename T>
void Sort<T>::issort(vector<T> &array) {
	int i;
	static int flag = 1;
	for (i = 0; i < array.size()-1; i++) {
		if (array[i+1] > array[i]) {
			flag = 0;
			break;
		}
	}
	cout << ((flag == 0) ? "sort failed\n" :"sort success\n");
}

#endif
