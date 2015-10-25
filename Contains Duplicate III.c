#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
/*vector<int> tempNums;
for (int j = i; j < len&&j<=i+k; ++j){
tempNums.push_back(nums[j]);
}
sort(tempNums.begin(), tempNums.end());
int minValue = 10000000;
for (int j = 0; j <k; ++j){
tempNums[j] = tempNums[j + 1] - tempNums[j];
if (minValue>tempNums[j]){
minValue = tempNums[j];
}
}*/
class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (k < 0 || t < 0)return false;
	
		int len = nums.size();
		if (len <= 0)return false;
		set<int> window;// set is ordered automatically 
		for (int i = 0; i < len; ++i){
			if (i>k)window.erase(nums[i-k-1]);
			// -t <= x - nums[i] <= t;
			auto pos = window.lower_bound(nums[i] - t);
			if (pos != window.end() && *pos -nums[i]<= t){
				return true;
			}
			window.insert(nums[i]);
		}
		return false;


	}
};
int main(){
	Solution s;
	/*int arr[] = { 12, 10, 2, 3, 14, 7, 8, 20, 3, 5 };
	vector<int> vec(arr,arr+10);
	int arr[] = {-1, 2147483647};
	vector<int> vec(arr, arr + 2);

		
	cout << s.containsNearbyAlmostDuplicate(vec, 1, 2147483647);*/
	return 0;
}