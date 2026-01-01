/* LeetCode Question No.209
 *
 * Given an array of positive integers nums and a positive integer target, 
 * return the minimal length of a contiguous subarray [numsl, numsl+1, ..., 
 * numsr-1, numsr] of which the sum is greater than or equal to target. If 
 * there is no such subarray, return 0 instead.
 */

#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int result = INT32_MAX;
		int sum = 0;
		int i = 0;
		int sublength = 0;
		for (int j = 0; j < nums.size(); j++) {
			sum += nums[j];
			while (sum >= s) {	// ">="!
				sublength = (j - 1 + 1);
				result = result < sublength ? result : sublength;
				sum -= nums[i++];
			}
		}
		return result;
	}
};
int main() {
	vector<int> arr = {0, 1, 2, 3, 4, 5, 6};
	Solution sl;
	cout << sl.minSubArrayLen(3, arr) << endl;
}

