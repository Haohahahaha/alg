/* LeetCode Question No.349
 * Given two integer arrays nums1 and nums2, return an array of their 
 * intersection. Each element in the result must be unique and you may return
 * the result in any order.
 */

#include "Intersec.h"
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_set<int> result_set;
	unordered_set<int> nums_set(nums1.begin(), nums1.end());
	for (int num : nums2) {
		if (nums_set.find(num) != nums_set.end()) {
			result_set.insert(num);
		}
	}
	return vector<int>(result_set.begin(), result_set.end());
}
