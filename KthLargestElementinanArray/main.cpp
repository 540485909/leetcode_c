#include <iostream>
#include <vector>
using namespace std;
const int inf = 1 << 8;
class Solution {
public:
	/*if we start from zero then the program will go into loop*/
	void heapAdjust(vector<int> &a, int start, int m)
	{
		int rc = a[start];
		for (int j = 2 * start; j <= m; j *= 2)
		{
			if (j < m&&a[j] < a[j + 1])++j;
			if (rc > a[j])break;
			a[start] = a[j];
			start = j;
		}
		a[start] = rc;
	}
	void heapSort(vector<int> a, int length)
	{
		/*strat from 1*/
		for (int i = length / 2 - 1; i > 0; i--)
			heapAdjust(a, i, length - 1);
		for (int i = length - 1; i > 1; i--)
		{
			int temp = a[i];
			a[i] = a[1];
			a[1] = temp;
			heapAdjust(a, 1, i - 1);
		}
	}
	int findKthLargest(vector<int>& nums, int k) {

		nums.insert(nums.begin(), inf);
		int length = nums.size();
		int index = k;
		for (int i = length / 2 - 1; i > 0; i--)
			heapAdjust(nums, i, length - 1);
		for (int i = length - 1; i > 1 && k > 0; i--, k--)
		{
			int temp = nums[i];
			nums[i] = nums[1];
			nums[1] = temp;
			heapAdjust(nums, 1, i - 1);
		}
		return nums[length - index];
	}
};
int main()
{
	int a[] = {  2, 1};
	Solution s;
	vector<int> vec(a, a + 2);
	cout << s.findKthLargest(vec, 2);
	return 0;
}
