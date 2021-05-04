#ifndef BUBBLE_SORT
#define BUBBLE_SORT
#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
class Bubble:public Sort<T>{
	public:
		void sort(vector<T> &) override;

};

template<typename T>
void Bubble<T>::sort(vector<T> &ar) {
	int i, j;
	for (i = 0; i < ar.size()-1; i++) {
		for (j = 0; j < ar.size()-1-i; j++) {
			if (ar[j+1] > ar[j]) {
				swap(ar[j+1],ar[j]);
			}
		}
	}
}


#endif
