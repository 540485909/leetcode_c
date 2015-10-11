#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if(n<=0)return 0;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
int main()
{
 Solution s;
cout<< s.climbStairs(4);
    return 0;
}
