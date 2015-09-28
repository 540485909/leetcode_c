#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void dp(string digits,string cur,vector<string> &result,int index)
    {
        if(index==digits.size())
        {
            result.push_back(cur);
            return ;
        }
         string mp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
         for(int i=0;i<mp[cur[index]-'0'].size();i++)
         {
             int c=cur.size();
             cur.push_back(mp[cur[index]-'0'][i]);
             dp(digits,cur,result,index+1);
             cur.resize(c);
         }



    }
    vector<string> letterCombinations(string digits) {
       vector<string> result;
       if(digits.size()==0)return null;

       string cur;
       dp(digits,cur,result,0);
       return result;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
