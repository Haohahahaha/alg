/* LeetCode Question No.704
 *
 * Given an array of integers `nums` which is sorted in ascending order, and an 
 * integer `target`, write a function to search `target` in `nums`. If `target`
 * exists, then return its index. Otherwise, return `-1`.
 */

#include <iostream>
#include <vector>

using namespace std;
// [left, right] edition.
class Solution {
public:
	int search(vector<int>& nums, int target) {
		
		int left = 0;
		int right = nums.size() - 1;

		while (left <= right) {
			int middle = left + ((right - left) / 2);
			if (nums[middle] > target) {
				right = middle - 1;
			} else if (nums[middle] < target) {
				left = middle + 1;
			} else {
				return middle;
			}
		}
		return -1;
	}
};

int main() {
	vector<int> v1={0, 1, 2, 3, 4, 5};
	Solution sl;
	cout << sl.search(v1, 3) << endl;

}
