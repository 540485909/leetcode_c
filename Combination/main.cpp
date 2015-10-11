#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
      vector<vector<int> > result;
      vector<int> cur;
      if(k>n||k==0)return result;
      dp(result,cur,n,k,1);
      return result;
    }
    void dp(vector<vector<int> >&result,vector<int>&cur,int n,int k,int start)
    {
        if(cur.size()==k)
        {
            result.push_back(cur);
            return ;
        }
        for(int i=start;i<=n;i++)
        {
            cur.push_back(i);
            dp(result,cur,n,k,i+1);
            cur.pop_back();
        }

    }
};
int main()
{
    Solution s;
    vector<vector<int> >result=s.combine(4,2);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[0].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
