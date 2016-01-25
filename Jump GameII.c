
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct data{
	int index;
	int value;
	friend bool operator< (const data &lhs, const data  &rhs){
		return lhs.value < rhs.value;
	}
	data(int i, int j) :index(i), value(j){};

};
class Solution {
public:
	int jump(vector<int>& nums) {
	size_t len = nums.size();
	if (len <= 1) return 0;

	priority_queue<data> pq;
	int minStep = 0;
	pq.push(data(0, 0 + nums[0]));



	int i = 0;
	while (i<len){
		data d = pq.top();
		i = d.index;
		int maxJump = d.value;
		if (maxJump == 0)return 0;

		int j = i+1;
		for ( ; j <=maxJump&&j<len; ++j){
			pq.push(data(j,j + nums[j]));
		}
		minStep++;
		i = j;
	}
	return minStep;

}
};
int main(){
Solution s;
//int a[] = { 3, 4, 3, 2, 5, 4, 3 };
//int a[] = { 2, 3, 1, 1,  4 };
int a[] = { 1, 2, 3 };
vector<int> nums(a,a+3);
cout << s.jump(nums);
}
