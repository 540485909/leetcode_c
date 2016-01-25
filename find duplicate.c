#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
/* the idea of solution :
  the array is not sorted so we can not use binary search but
  the value in array is from 1 to n so we can use binary search to narrow the scope of 1 to n
/*divide and conquer*/
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int len = nums.size();
		int sum = 0;
		int actualSum = 0;
		int low = 0, high = len - 1;
		while (low <= high){
			int mid = low + (high - low) / 2;
			int countResult=0;
			for (int i = 0; i <= len-1; ++i){
				if (nums[i] <= mid){
					countResult++;
				}
			}
			if (countResult > mid){
				high= mid- 1;
			}
			else{
				low= mid + 1;
			}
		}
		return low;
		
		
	}
};
int main(){
	Solution s;
	int arr[] = { 1 ,6,3,4,5,2,6,7};

	//int arr[] = { 12, 10, 2, 3, 14, 7, 8, 20, 3, 5 };
	vector<int> vec(arr,arr+8);
	

		
	cout << s.findDuplicate(vec);
	return 0;
}