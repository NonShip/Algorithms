
#include <vector>
using namespace std;

/*
 * binary search 
 * note: array must be sorted
 */


//if find target return position
int binarysearch(const vector<int> &ar, const int &target, int lo, int hi) {
	if (hi >= 1) {
		int mid = lo + (hi - lo) / 2;
		if (ar[mid] == target) {
			return mid;
		}
		else if (ar[mid] > target) {
			return binarysearch(ar, target, lo, mid - 1);
		}

		return binarysearch(ar, target, mid+1, lo);
	}
	return -1;

	
}
