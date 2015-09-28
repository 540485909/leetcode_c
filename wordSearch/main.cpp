#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    struct data
{
    int i;
    int j;
};
    bool exist(vector<vector<char> > &board, string word) {
        if(word.size()==0)return true;
        if(board.size()==0&&word.size()!=0)return false;
        if(board.size()*board[0].size()<word.size())return false;
        vector<data> result;
         data d;
       for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(word[0]==board[i][j])
               {

                   d.i=i;
                   d.j=j;
                result.push_back(d);
               }

            }
        }
        if(word.size()==1&&result.size()!=0)return true;
        for( int i=0;i<result.size();i++)
       {
            if(dp(board,word,1,result[i]))return true;
        }
        return false;
    }
    bool dp(vector<vector<char> > &board, string word,int k, data record)
    {
         if(k==word.size())return true;
         int i=record.i;
         int j=record.j;

         if(i+1<board.size()&&board[i+1][j]==word[k]){
                record.i++;
                dp(board,word,k+1,record);
         }
         else if(j+1<board[0].size()&&board[i][j+1]==word[k]){
             record.j++;
         dp(board,word,k+1,record);
         }
         else if(i-1>=0&&board[i-1][j]==word[k]){record.i--; dp(board,word,k+1,record);}
         else if(j-1>=0&&board[i][j-1]==word[k]){record.j--;dp(board,word,k+1,record);}
         else return false;



    }
};
int main()
{
    vector<vector<char> > result;
    char a[2]={'a','a'};
    vector<char> ivec(a,a+2);
    result.push_back(ivec);


      Solution s;
     cout<< s.exist(result,"aa");
    return 0;
}
