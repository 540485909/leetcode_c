#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void dfs(vector<vector<char> >& grid,int i,int j,bool& isLands){

		if(grid[i][j]=='0'||grid[i][j]=='2') return;
		if(grid[i][j]=='1'){
			isLands=true;
			grid[i][j]='2';
		}
		if(j+1<grid[i].size())
		dfs(grid,i,j+1,isLands);//横着走
		if(i+1<grid.size())
		dfs(grid,i+1,j,isLands);//竖着走
		if(j-1>=0)
		dfs(grid,i,j-1,isLands);//竖着走
		if(i-1>=0)
		dfs(grid,i-1,j,isLands);

	}
	int numIslands(vector<vector<char> >& grid) {
		int res=0;
		for(int i=0;i<grid.size();i++){
			for(int j=0;j<grid[i].size();j++){
				bool isLands=false;
				if(grid[i][j]=='1'){
					dfs(grid,i,j,isLands);
					if(isLands==true){
						res++;
					}

				}
			}
		}
		return res;

	}
};
int main()
{
	vector<vector<char> > grid;
	char a[5]={'1','1','0','0','0'};vector<char> temp(a,a+5);
	grid.push_back(temp);
	grid.push_back(temp);
	char b[5]={'0','0','1','0','0'};vector<char> tempb(b,b+5);  grid.push_back(tempb);
	char  c[5]={'0','0','0','1','1'};vector<char> tempc(c,c+5);  grid.push_back(tempc);
	Solution s;
	cout<<s.numIslands(grid);


	return 0;
}
