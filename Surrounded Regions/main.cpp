#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int direction[4][2]
{
    0,1,
    1,0,
    -1,0,
    0,-1
};
class Solution {
public:
    void solve(vector<vector<char> > &board) {
        int row=board.size();
        int col=board[0].size();
        if(row<2||col<2)return;
        //top line
        for(int i=0;i<col;i++)
        {
            if(board[0][i]=='O')
            {
                board[0][i]='#';
                dfs(board,0,i,row,col);
            }
        }
             // bottom一行
        for(int i=0;i<col;i++)
        {
            if(board[row-1][i] == 'O')
            {
                board[row-1][i] = '#';
                dfs(board, row-1, i, row, col);
            }
        }
        //left一列
        for(int i=1;i<row-1;i++)
        {
            if(board[i][0] == 'O')
            {
                board[i][0] = '#';
                dfs(board, i, 0, row, col);
            }
        }
        // right一列
        for(int i=1;i<row-1;i++)
        {
            if(board[i][col-1] == 'O')
            {
                board[i][col-1] = '#';
                dfs(board, i, col-1, row, col);
            }
        }
           //将'O'变为'X'，将'#'恢复回'O'
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }


    }
    void dfs(vector<vector<char> >&board,int i,int j,int row ,int col)
    {
        if(i>1&&board[i-1][j]=='O')
        {
            board[i-1][j]='#';
            dfs(board,i-1,j,row,col);
        }
        if(i<row-1&&board[i+1][j]=='O')
        {
            board[i+1][j]='#';
            dfs(board,i,j,row,col);

        }
            if(j > 1 && board[i][j-1] == 'O')
        {
            board[i][j-1] = '#';
            dfs(board, i, j-1, row, col);
        }
        if(j < col-1 && board[i][j+1] == 'O')
        {
            board[i][j+1] = '#';
            dfs(board, i, j+1, row, col);
        }

    }
};
int main()
{

    return 0;
}
