#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string> > result;
    bool isPalidr(string s)
    {

        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=s[s.length()-1-i])

            {

                return false;
            }

        }
        return true;

    }

    void dfs(vector<string> &iVec,string  s)
    {

        if(s.length()==0)
        {
            result.push_back(iVec);
            return ;

        }
        for(int i=1;i<=s.length();i++)
        {
            string temp=s.substr(0,i);
            if(isPalidr(temp))
            {
                iVec.push_back(temp);
                string restSubStr = s.substr(i);
                dfs(iVec,restSubStr);
                iVec.pop_back();
            }


        }

    }
    vector<vector<string> > partitione(string s) {
    vector<string> iVec;
    dfs(iVec,s);
    return result;
    }

};
int main()
{
    Solution s;
    vector<vector<string> >result=s.partitione("aab");
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[0].size();j++)
        {
            cout<<result[i][j]<<endl;
        }
    }
    return 0;
}
