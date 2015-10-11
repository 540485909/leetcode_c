#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int len=nums.size();
        if(len<=0) return 0;
        if(len==1) return nums[0];
        int dp[len+1];
        memset(dp,0,sizeof(dp));
        dp[1]=nums[0];
        dp[2]=(nums[0]>nums[1])?nums[0]:nums[1];
        for(int i=1;i<=len;i++){
                dp[i+1]=max(dp[i],dp[i-1]+nums[i]);

        }
         return dp[len];
    }

};
int main()
{
    Solution s;
    int a[1]={3};
    vector<int> vec(a,a+1);
    cout<<s.rob(vec);
    cout << "Hello world!" << endl;
    return 0;
}
