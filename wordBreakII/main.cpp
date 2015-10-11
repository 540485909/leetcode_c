#include <iostream>
#include <vector>
#include <set>
#include<tr1/unordered_set>
using namespace std;
class Solution {
vector<string>  result;

public:
vector<bool> wordBreak1(string s, std::tr1::unordered_set<string> &dict) {
       vector<bool> wordB(s.length()+1,false);       //wordB stands for the string from 0 to i can be segument

        wordB[0]=true;
        for(int i=1;i<s.length()+1;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(wordB[j]&&dict.find(s.substr(j,i-j))!=dict.end())
                    {
                        wordB[i]=true;
                        break;
                    }
            }
        }
        return wordB;


}
void dfs(int start,int n,string s,string cur,std::tr1::unordered_set<string> &dict,vector<bool> wordB)
{
    if(start==n)
    {
        result.push_back(cur);
        return ;
    }
    for(int i=start;i<n;i++)
    {
        string t=s.substr(start,i+1-start);
        if(wordB[i+1]&&dict.find(t)!=dict.end())
        {
            int c=cur.size();//used to record the current element ,will be used to keep the size like the pop operation,all is caused by " "signal
            cur+=t;
            if(i<n-1)
            cur.push_back(' ');//the last element do not need to add a space symbol
            dfs(i+1,n,s,cur,dict,wordB);
            cur.resize(c);//being used to back to the previous condition
        }
    }
}
    vector<string> wordBreak(string s, tr1::unordered_set<string> &dict) {
        for(string::iterator it=s.begin();it!=s.end();it++)
        {
            if(*it==' ')it=s.erase(it);
        }
        vector<bool> wordB=wordBreak1(s,dict);
        dfs(0,s.length(),s,string(""),dict,wordB);
        return result;

    }
};








int main()
{
    string s="catsanddog";
    tr1::unordered_set<string> dict;
    dict.insert("cat");
      dict.insert("cats");
        dict.insert("and");
          dict.insert("sand");
    dict.insert("dog");
    Solution sou;
   vector<string> result= sou.wordBreak(s,dict);
   for(vector<string>::iterator it=result.begin();it!=result.end();it++)
   {
       cout<<*it<<endl;
   }
    return 0;
}
