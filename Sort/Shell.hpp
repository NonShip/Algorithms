#ifndef SHELL_H
#define SHELL_H


#include "Sort.hpp"

template<typename T>
class Shell:public Sort<T> {
	public:
		void sort(vector<T> &) override;
		void shellsort(vector<T> &, int low_index, int hight_index);

};

template<typename T>
void Shell<T>::sort(vector<T> &arr) {
	int h = 1, N = arr.size();
	int i, j;

	while (h < N/3) {
		h = h*3+1;
	}
	while (h >= 1) {
		for (i = h; i < N; i++) {
			for (j = i; j >= h && arr[j] < arr[j-h]; j-=h) {
				swap(arr[j], arr[j-h]);
			}
		}
		h /= 3;
	}

}

template<typename T>
void Shell<T>::shellsort(vector<T> &arr, int lo, int hi){
	if (lo >= hi) {
		return;
	}
	int h = 1, N = hi, L = lo;
	int i, j;
	while (h < N/3) {
		h = h*3+1;
	}
	while (h >= 1) {
		for (i = h + L; i < N; i++) {
			for (j = i; j >= h && arr[j] < arr[j-h]; j-=h) {
				swap(arr[j], arr[j-h]);
			}
		}
		h /= 3;
	}
}









#endif
