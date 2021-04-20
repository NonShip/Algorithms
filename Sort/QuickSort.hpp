#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include "Shell.hpp"


template<typename T>
class QuickSort: public Shell<T> {
	public:
		int partition(vector<T> &, int lo, int hi);
		void sort(vector<T> &) override;
		void quicksort(vector<T> &arr, int lo, int hi);
};


template<typename T>
int QuickSort<T>::partition(vector<T> & arr, int lo, int hi) {
	int i = lo;
	int j = hi + 1;
	T V = arr[lo];
	
	while(true) {
		while (arr[++i] < V) {
			if (i == hi) {
				break;
			}
		}

		while (arr[--j] > V) {
			if (j == lo) {
				break;
			}
		}

		if (i >= j) {
			break;
		}

		swap(arr[i], arr[j]);
	}

	swap(arr[lo], arr[j]);

	return j;
}

template<typename T>
void QuickSort<T>::quicksort(vector<T> &arr, int lo, int hi) {
	if (hi <= lo) {
		return;
	}
	int partition_index = partition(arr, lo, hi);
	quicksort(arr, lo, partition_index-1);
	quicksort(arr, partition_index+1, hi);
}

template<typename T>
void QuickSort<T>::sort(vector<T> &arr) {
	quicksort(arr, 0, arr.size());
}

	





#endif 
