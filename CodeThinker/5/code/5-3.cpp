/* LeetCode Question No.1
 * Given an array of integers `nums` and an integer `target`, return indices of
 * the two numbers such that they add up to `target`.
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * You can return the answer in any order.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		// The storage arch of `map` is <key,value>,
		// which save number-value with `key`,
		// and save index with `value`.
		std::unordered_map <int, int> map;
		for (int i = 0; i < nums.size(); i++) {
			auto iter = map.find(target - nums[i]);
			if (iter != map.end()) {
				return {iter->second, i};	// iter->first is key;
											// iter->second is value;
			}
			// insert a pair of integer values into the map
			map.insert(pair<int,int>(nums[i], i));
		}
		return {};
	}
	void printV(vector<int> nums){
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
};

int main(void){
	vector<int> nums = {1, 2, 3, 4, 5};
	int target = 0;

	Solution sl;
	
	cout << "0\t1\t2\t3\t4\t" << endl << "1\t2\t3\t4\t5\t" << endl;
	cout << "Please return your target smaller than 9: ";
	cin >> target;
	
	sl.printV(sl.twoSum(nums, target));
}
