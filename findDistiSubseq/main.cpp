#include <iostream>

using namespace std;
class Solution {
public:
    int numDistinct(string S, string T) {
        int s=0;
        dfs(0,S.length(),S,s);
        int t=0;
        dfs(0,T.length(),T,t);
        return s-t;

    }
    void dfs(int start,int tail,string s,int &cou)
    {
        if(start==tail)return ;
        for(int i=start;i<s.length();i++)
        {
            string temp=s.substr(start,i+1);
            cou++;
            dfs(start+1,tail,s,cou);

        }

    }
};
int main()
{
    Solution s;
   int result= s.numDistinct("rabbbit","rabbit");
   cout<<result<<endl;
    return 0;
}
