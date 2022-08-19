#include "TwoSum.h"

int main() {
	TwoSum judge;
	vector<int> nums = {1,5,10,20,50,100};
	int target = 0;
	cin >> target; 
	judge.twoSum(nums, target);
	return 0;
}
