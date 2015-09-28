#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isValidRow(vector<vector<char> >&board, int a){
        bool valueCount[9]={false};
        for(int i=0;i<9;i++)
        {
            if(board[a][i]=='.')continue;
            if(valueCount[board[a][i]-'1']==true)return false;
            else valueCount[board[a][i]-'1']=true;

        }
        return true;
    }
    bool isValidCol(vector<vector<char> >&board, int b)
    {
        bool valueCount[9]={false};
        for(int j=0;j<9;j++)
        {
            if(board[j][b]=='.')continue;
            if(valueCount[board[j][b]-'1']==true)return false;
            else valueCount[board[j][b]-'1']=true;
        }
        return true;
    }
    bool isValidCell(vector<vector<char> >&board,int a,int b)
    {
        bool valueCount[9]={false};
        for(int i=a;i<3+a;i++)
        {
            for(int j=b;j<3+b;j++)
            {
                if(board[i][j]=='.')continue;
                if(valueCount[board[i][j]-'1']==true)return false;
                else valueCount[board[i][j]-'1']=true;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char> > &board) {
      bool isCell=false;
      for(int i=0;i<3;i++)
      {
          for(int j=0;j<3;j++)
            {
                isCell=isValidCell(board,3*i,3*j);
                if(isCell==false)return false;
            }
      }

      bool isRow=false;
      for(int i=0;i<9;i++)
      {
         isRow=isValidRow(board,i);
         if(isRow==false)return false;
      }
      bool isCol=false;

      for(int i=0;i<9;i++)
      {
        isCol=isValidCol(board,i);
        if(isCol==false)return false;
      };
      return true;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
