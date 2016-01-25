
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
When we find 5, then swap it with A[4].

At last, the first place where its number is not right, return the place + 1.*/
class Solution {
public:
	int getState(int i, int j, vector<vector<int>>& board,int row,int column){
		int liveNeighbors = 0;
		if (i - 1 >= 0){
			if (j - 1 >= 0){
				if (board[i-1][j-1] == 1){
					liveNeighbors++;
				}
			}
			if (board[i - 1][j] == 1){
				liveNeighbors++;
			}
			if (j + 1 < column){
				if (board[i - 1][j + 1] == 1){
					liveNeighbors++;
				}
			}
		}

		if (j - 1 >= 0){
			if (board[i][j - 1] == 1){
				liveNeighbors++;
			}
		}
		if (j + 1 < column){
			if (board[i][j + 1] == 1){
				liveNeighbors++;
			}
		}


		if (i +1 < row){
			if (j - 1 >= 0){
				if (board[i +1][j - 1] == 1){
					liveNeighbors++;
				}
			}
			if (board[i + 1][j] == 1){
				liveNeighbors++;
			}
			if (j + 1 < column){
				if (board[i + 1][j + 1] == 1){
					liveNeighbors++;
				}
			}
		}
		if (board[i][j] == 1){
			if (liveNeighbors < 2){
				return 0;
			}
			else if (liveNeighbors >= 2 && liveNeighbors <= 3){
				return 1;
			}
			else if (liveNeighbors > 3){
				return 0;
			}
		}

		if (board[i][j] == 0){
			if (liveNeighbors == 3){
				return 1;
			}
		}
		
		return board[i][j];
	}
	void gameOfLife(vector<vector<int>>& board) {
		int row = board.size();
		if (row <= 0) return;
		int column = board[0].size();
		vector<vector<int> > nextState(row,vector<int>(column,'0'));
		for (int i = 0; i < row; ++i){
			for (int j = 0; j < column; ++j){
				nextState[i][j]=getState(i, j, board, row, column);
			}
		}
		board = nextState;
	}
};
int main(){
	int a[] = { 1 };
	int b[] = { 0 };
	int c[] = { 1 };
	int d[] = { 0 };
	int e[] = { 1 };
	vector<int> veca(a,a+1);
	vector<int> vecb(b, b + 1);
	vector<int> vecc(c, c + 1);
	vector<int> vecd(d, d + 1);
	vector<int> vece(e, e + 1);
	vector<vector<int> > vec;
	vec.push_back(veca);
	vec.push_back(vecb);
	vec.push_back(vecc);
	vec.push_back(vecd);
	vec.push_back(vece);
	Solution s;
	s.gameOfLife(vec);
	return 0;
}
