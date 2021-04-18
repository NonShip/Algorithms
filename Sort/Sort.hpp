#ifndef SORT_HPP
#define SORT_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
class Sort {
	public:
		virtual void sort(vector<T>&);
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
	for (i = 1; i < array.size(); i++) {
		if (array[i-1] > array[i]) {
			cout << "sort failed\n";
			break;
		}
	}
	cout << "sort success\n";
}

#endif
