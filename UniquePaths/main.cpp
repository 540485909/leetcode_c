#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
 int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)  {
     int m=obstacleGrid.size();
     int n=obstacleGrid[0].size();
     vector<int> dp(n+1,0);
     m--;
     int i=n-1;
     while(i>=0&&obstacleGrid[m][i]!=1)
     {
         dp[i]=1;
         i--;
     }
     while(m-->0)
     {
         for(int i=n-1;i>=0;i--)
            dp[i]=(obstacleGrid[m][i]!=1)?0:dp[i]+dp[i+1];
     }
     return dp[0];

    }
};
int main()
{

    return 0;
}
