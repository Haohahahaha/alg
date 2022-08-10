#include "Intersec.h"

int main() {
	Intersec judge;
	vector<int> nums1 {1, 2, 3, 4, 5};
	vector<int> nums2 {3, 3};
	vector<int> intersec(judge.intersection(nums1, nums2));
	for (vector<int>::iterator it = intersec.begin(); it != intersec.end(); it++) {
		cout << *it << " ";
	}
	return 0;
}
