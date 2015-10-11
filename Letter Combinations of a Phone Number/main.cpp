#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    map<char ,vector<char> > dict;
    vector<string> res;
    void createDic()
    {
        dict.clear();
         dict['2'].push_back('a');
         dict['2'].push_back('b');
         dict['2'].push_back('c');
         dict['3'].push_back('d');
         dict['3'].push_back('e');
         dict['3'].push_back('f');
         dict['4'].push_back('g');
         dict['4'].push_back('h');
         dict['4'].push_back('i');
         dict['5'].push_back('j');
         dict['5'].push_back('k');
         dict['5'].push_back('l');
         dict['6'].push_back('m');
         dict['6'].push_back('n');
         dict['6'].push_back('o');
         dict['7'].push_back('p');
         dict['7'].push_back('q');
         dict['7'].push_back('r');
         dict['7'].push_back('s');
         dict['8'].push_back('t');
         dict['8'].push_back('u');
         dict['8'].push_back('v');
         dict['9'].push_back('w');
         dict['9'].push_back('x');
         dict['9'].push_back('y');
         dict['9'].push_back('z');
    }
    void dfs(string digits,map<char,vector<char> > dict,vector<string> &res,string cur,int step)
    {
        int lens=digits.size();
        if(lens==step)
        {
            res.push_back(cur);
            return ;
        }
        for(int i=0;i<dict[digits[step]].size();i++)
        {

            dfs(digits,dict,res,cur+dict[digits[step]][i],step+1);

        }


    }
    vector<string> letterCombinations(string digits) {
     res.clear();
              if(digits.size()==0)return res;
     createDic();
     dfs(digits,dict,res,"",0);
     return res;
    }
};
int main()
{
    Solution s;
    s.letterCombinations("23");
    return 0;
}
