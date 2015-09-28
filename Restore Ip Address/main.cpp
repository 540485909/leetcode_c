#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
           vector<string> result;
           string ip;
           dfs(0,0,result,ip,s);
           return result;
    }
    void dfs(int start,int step,vector<string> &result,string ip,string s)
    {
        if(start==s.size()&&step==4)
        {
            ip.resize(ip.size()-1);
            result.push_back(ip);
            return;

        }
        if(s.size()-start<4-step)return;
        if(s.size()-start>(4-step)*3)return ;
        int num=0;
        for(int i=start;i<start+3&&i<s.size();i++)
        {
            num=10*num+(s[i]-'0');
            if(num<=255)
            {
                int c=ip.size();
                ip+=s.substr(start,i+1-start);
                ip.push_back('.');
                dfs(i+1,step+1,result,ip,s);
                ip.resize(c);
            }
            if(num==0)break;

        }
    }
};
int main()
{
    Solution s;
   vector<string> result=s.restoreIpAddresses("25525511135");
   cout<<result[0]<<endl;
   cout<<result[1]<<endl;
    return 0;
}
