#include <iostream>
#include <cstring>
using namespace std;
/*
EDIT[i,j]表示对于字符串a从1到i的子串和字符串b从1到j的字串的编辑距离。（字符串下标从1开始)

EDIT[i - 1,j] + 1表示对a 在i 位置删除delete操作

EDIT[i,j - 1] + 1 表示insert添加操作

EDIT[i-1, j - 1] + f(x[i],y[j])这里如果x[i] == y[j] 则 f(x[i],y[j]) == 0 否则 ==1

表示不变或者是modify操作。

*/
class Solution {
public:
    int minDistance(string word1, string word2) {
    int len1=word1.size();
    int len2=word2.size();
    int dp[len1+1][len2+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=len1;i++)
    dp[i][0]=i;
    for(int j=1;j<=len2;j++)
    dp[0][j]=j;
    for(int i=0;i<len1;i++)
    {
        for(int j=0;j<len2;j++)
        {
            if(word1[i]==word2[j])
            dp[i+1][j+1]=min(dp[i+1][j]+1,min(dp[i][j+1]+1,dp[i][j]));
            else
            {
               dp[i+1][j+1]=min(dp[i+1][j]+1,min(dp[i][j+1]+1,dp[i][j]+1));

            }
        }
    }
    return dp[len1][len2];
    }
};
int main()
{
    cout << "Hello world!" << endl;
    Solution s;
    cout<<s.minDistance("eeba","abca");
    return 0;
}
