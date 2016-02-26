/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ¡Ü i < j < k ¡Ü n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.

this  is a longest increasing sebsequence problem


*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 0x3fffffff;
class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int len = nums.size();
		if (len < 3) return false;
		int dp[4];
		fill(dp, dp + 4, INF);
		for (int i = 0; i < len; ++i)
		{
			*lower_bound(dp,  dp+4, nums[i]) = nums[i];
			if (lower_bound(dp, dp + 4, INF) - dp >= 3) return true;
		}
		return false;
	}
};
int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(3);
	cout << s.increasingTriplet(nums);
}