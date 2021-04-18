#include <fstream>
#include "Insertion.h"


int main(void) {
	ifstream fin;
	string path = "/home/fanyang/Algs4/sorting/data1.txt";
	fin.open(path);
	if (!fin) {
		cout << "failed open: " << path  << endl;
		exit(1);
	}
	else
		cout << "success open: " << path  << endl;
	string str;
	fin >> str;
	fin.close();
	vector<char> data;
	for (auto d : str) {
		data.push_back(d);
	}

	InsertSort<char> v;
	v.sort(data);
	v.show(data);
	v.issort(data);
	
	



	return 0;
}
