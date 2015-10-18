#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
#include <algorithm>
using namespace std;


class Solution {
public:


	int maximalSquare(vector<vector<char> >& matrix) {
		int row = matrix.size();
		if (row == 0)return 0;
		int column = matrix[0].size();
		int maxsize = 0;

		vector<vector<int>> dp(2, vector<int>(column, 0));
		for (int i = 0; i < column; ++i){
			dp[0][i] = matrix[0][i] - '0';
			maxsize = max(maxsize, dp[0][i]);
		}
		for (int i = 1; i < row; ++i){
			for (int j = 0; j < column; ++j){
				if (matrix[i][j] == '1'){
					if (j > 0){
						dp[i & 1][j] = min(min(dp[(i - 1) & 1][j], dp[i & 1][(j - 1)]), dp[(i - 1) & 1][j - 1]) + 1;
					}
					
					else{
						/************************************************************************/
						/* 若保存两行 则对每列进行初始化无法一次初始化完全，
						/* 必须一步一步初始化，一次初始化会形成覆盖 因为只有两个变量                                                                    */
						/************************************************************************/
						dp[i & 1][j] = 1;
					}
					
					maxsize = max(maxsize, dp[i & 1][j]);
				}
				else if (matrix[i][j] == '0'){
					dp[i & 1][j] = matrix[i][j] - '0';
				}
			}
		}
		/*row
		vector<vector<int>> dp(row, vector<int>(2, 0));
		for (int i = 0; i < row; ++i){
		dp[i][0] = matrix[i][0] - '0';
		maxsize = max(maxsize, dp[i][0]);
		}
		if (column > 1){
		dp[0][1] = matrix[0][1] - '0';
		}
		for (int j = 1; j < column; ++j){
		for (int i = 1; i < row; ++i){

		if (matrix[i][j] == '1'){
		dp[i][j & 1] = min(min(dp[i][(j-1) & 1], dp[i-1][j&1]), dp[i - 1][(j - 1)&1]) + 1;
		maxsize = max(maxsize, dp[i][j & 1]);
		}
		else if (matrix[i][j] == '0'){
		dp[i][j & 1] = matrix[i][j] - '0';
		}
		}
		}*/
		return maxsize*maxsize;

	}
	/*as we can see, each time when we update size[i][j],
	we only need size[i][j - 1], size[i - 1][j - 1](at the previous left column)
	and size[i - 1][j](at the current column).
	So we do not need to maintain the full m*n matrix.
	In fact, keeping two columns is enough.
	Now we have the following optimized solution.*/
};


int main()
{

	

        /*omit*/	

	return 0;
}
