/* LeetCode Question No.349
 * Given two integer arrays `nums1` and `nums2`, return an array of their
 * intersection. Each element in the result must be unique and you may return
 * the result in any order.
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public: 
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
		unordered_set<int> result_set;
		unordered_set<int> nums_set(nums1.begin(), nums1.end());
		for (int num : nums2) {
			// 发现nums2的元素在nums_set中出现过
			if (nums_set.find(num) != nums_set.end()) {
				result_set.insert(num);
			}
		}
		return vector<int>(result_set.begin(), result_set.end());
	}
	void printV(vector<int> nums){
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
			cout << *it << " ";
		}	
		cout << endl;
	}
};

int main(void){
	vector<int> nums1 = {1, 2, 2, 1};
	vector<int> nums2 = {2, 3, 4};

	Solution sl;

	sl.printV(sl.intersection(nums1, nums2));
	return 0;
}
