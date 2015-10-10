#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int len = nums.size();
		int i = 0, j = 0, minLen = 100000;
		if (len == 0)return 0;
		int sum = nums[0];
		while (i < len&&j<len){
			if (sum >= s){
				if (minLen>(j - i)){
					minLen = j - i;
				}
				sum = sum - nums[i];
				i++;

			}
			else if (sum < s){

				j++;
				if (j<len)
				sum = sum + nums[j];
				else{
					break;
				}
			}
		}
		return (minLen==100000)?0:minLen + 1;
	}
};
int main()
{
	int a[] = { 2, 3, 1, 2, 4, 3 };
	vector<int> nums(a, a + 6);

	Solution s;
	cout << s.minSubArrayLen(4, nums);
	cout << s.minSubArrayLen(2, nums);
	return 0;
}
