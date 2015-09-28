#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len=nums.size();
        int sum=0;
        for(int i=0;i<len;i++){
            sum+=nums[i];
        }
        return (nums[len-1]+1)*nums[len]/2-sum;
    }
};
int main()
{
    Solution s;
    int a[10]={1,2,3,4,5,7,8,9,10,11};
    vector<int> vec(a,a+10);

    cout<<s.missingNumber(vec);
    return 0;
}
