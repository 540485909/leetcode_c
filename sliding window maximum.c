
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct data{
	int value;
	int index;
	data(int i, int j):index(i), value(j){}
	friend bool operator<(const data &lhs, const data &rhs){
		return lhs.value < rhs.value;
	}
};
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> res;
		size_t len = nums.size();
		if (len <= 0) return res;
		priority_queue<data> p;
		

		for (size_t i = 0; i < len; ++i){
			p.push(data(i,nums[i]));
			if (i +1>= k) {
				while (i - p.top().index >=k){
					p.pop();
				}
				res.push_back(p.top().value);	
			
			}
			
		}
		return res;
	}
};
int main(){
Solution s;
//int a[] = { 3, 4, 3, 2, 5, 4, 3 };
//int a[] = { 2, 3, 1, 1,  4 };
int a[] = { 1, 3, -1, -3, 5, 3,4,3, 6, 7 };
	//int a[] = { 9, 10, 9, -7, -4, -8, 2, -6 };
	vector<int> nums(a,a+9);
	s.maxSlidingWindow(nums,3);
	return 0;
}
