#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int cou;


    bool isCorrect(vector<string> vec,int i,int j)
    {
    int s,t;
	for(s=i,t=0;t<vec[0].size();t++)
	if(vec[s][t]=='Q')return 0;//hang
	for(s=0,t=j;s<vec.size();s++)
	if(vec[s][t]=='Q')return 0;//line
	for(s=i-1,t=j-1;t>=0 && s>=0;s--,t--)
	if(vec[s][t]=='Q')return 0;
	for(s=i+1,t=j+1;s<vec.size()&&t<vec.size();s++,t++)
	if(vec[s][t]=='Q')return 0;
	for(s=i-1,t=j+1;s>=0&&t<vec.size();s--,t++)
	if(vec[s][t]=='Q')return 0;
	for(s=i+1,t=j-1;s<vec.size()&&t>=0;s++,t--)
	if(vec[s][t]=='Q')return 0;
	return 1;

    }
    void dfs(int i,vector<string> &vec,vector<vector<string> > &result,int n)
    {
        if(i==n)
        {
            result.push_back(vec);
            cou++;
            return ;
        }
        for(int j=0;j<n;j++)
        {
            if(isCorrect(vec,i,j));
            {
                vec[i][j]='Q';
                dfs(i+1,vec,result,n);
                vec[i][j]='.';
            }
        }

    }

       int totalNQueens(int n) {


             vector<vector<string> > result;
             vector<string> vec;
             for(int i=0;i<n;i++)
             {
                 string s="";
                 for(int j=0;j<n;j++)
                    s+=".";
                 vec.push_back(s);
             }
             dfs(0,vec,result,n);
             return cou;
    }
};
int main()
{
	Solution s;
	s.solveNQueens(1);
}
