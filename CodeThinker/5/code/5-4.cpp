/* LeetCode Question No.454
 * Given four integer arrays `nums1`, `nums2`, `nums3` and `nums4` all of length
 * `n`, return the number of tuples (i, j, k, l) such that:
 * `0 <= i, j, k, l < n`
 * `nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0`
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public: 
	int fourSumCount(vector<int>& A, vector<int>& B, 
					 vector<int>& C, vector<int>& D)
	{
		unordered_map<int, int> umap;	// key: a+b的数值
										// value: a+b数值出现的次数	
		
		// 遍历A、B数组，统计两个数组元素之和及出现的次数，并放到map中
		for (int a : A) {
			for (int b : B) {
				umap[a + b] ++;
			}
		}
		int count = 0;	// 统计a+b+c+d=0出现的次数
		
		// 在遍历C、D数组时，如果 0-(c+d) 在 map 中出现过，
		// 就统计 map 中 key 对应的 value，即两数之和出现的次数
		for (int c : C) {
			for (int d : D) {
				if (umap.find(0 - (c + d)) != umap.end()) {
					count += umap[0 - (c + d)];
				}
			}
		}
		return count;
	}
};

int main(void){
	vector<int> nums1 = {1, 2};
	vector<int> nums2 = {-2, -1};
	vector<int> nums3 = {-1, 2}; 
	vector<int> nums4 = {0, 2};

	Solution sl;
	
	cout << sl.fourSumCount(nums1, nums2, nums3, nums4) << endl;	
}
