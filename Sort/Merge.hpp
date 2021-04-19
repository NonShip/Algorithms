#ifndef MERGE_HPP
#define MERGE_HPP
#include "Shell.hpp"

template<typename T>
class MergeSort:public Shell<T> {
	public:
		void merge(vector<T> &,int low_index, int medium_index, int hight_index);
		void sort(vector<T> &) override;

	private:
		vector<T> aux;
		void mergesort(vector<T> &, int low_index, int hight_index);
};

template<typename T>
void MergeSort<T>::merge(vector<T> &arr, int lo, int mid, int hi) {
	if (aux == arr) {
		cout << "assign arr to aux" << endl;
		return;
	}
	else {
		aux = arr;
	}
	int i = lo, j = mid+1;
	for (int k = lo; k < hi; k++) {
		if (i > mid) {
			arr[k] = aux[j++];
		}
		else if (j > hi) {
			arr[k] = aux[i++];
		}
		else if (aux[i] < aux[j]) {
			arr[k] = aux[i++];
		}
		else {
			arr[k] = aux[j++];
		}
	}
}


template<typename T>
void MergeSort<T>::mergesort(vector<T> &arr, int lo, int hi) {
	if (hi <= lo) {
		return;
	}
	int mid = lo + (hi -lo)/2;
	this->shellsort(arr, lo, mid);
	this->shellsort(arr, mid + 1, hi);
	merge(arr, lo, mid, hi);
}

template<typename T>
void MergeSort<T>::sort(vector<T> &arr) {
	mergesort(arr, 0, arr.size());
}

#endif
