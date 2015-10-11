#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int row=triangle.size();
        if(row==0)return 0;
        vector<int> dp;
        dp.resize(row);
        for(int i=row-1;i>=0;i--)
        {
            vector<int> value=triangle[i];
            for(int j=0;j<value.size();j++)
            {
                if(i==row-1)
                    dp[j]=value[j];
                else{dp[j]=min(dp[j]+value[j],dp[j+1]+value[j]);}
            }
        }
        return dp[0];

    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
