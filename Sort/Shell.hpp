#ifndef SHELL_H
#define SHELL_H


#include "Sort.hpp"

template<typename T>
class Shell:public Sort<T> {
	public:
		void sort(vector<T> &) override;
};

template<typename T>
void Shell<T>::sort(vector<T> &array) {
	int h = 1, N = array.size();
	int i, j;

	while (h < N/3) {
		h = h*3+1;
	}
	while (h >= 1) {
		for (i = h; i < N; i++) {
			for (j = i; j >= h && array[j] < array[j-h]; j-=h) {
				swap(array[j], array[j-h]);
			}
		}
		h /= 3;
	}

}









#endif
