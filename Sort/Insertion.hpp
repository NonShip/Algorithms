#ifndef INSERT_SORT_H
#define INSERT_SORT_H

#include "Sort.hpp"

template<typename T>
class InsertSort:public Sort<T> {
	public:
		void sort(vector<T> &) override;
};

template<typename T>
void InsertSort<T>::sort(vector<T> &array) {
	int i, j;
	int N = array.size();
	for (i = 1; i < N; i++) {
		for (j = i; j > 0 && array[j] < array[j-1]; j--) {
			swap(array[j-1], array[j]);
		}
	}
}










#endif
