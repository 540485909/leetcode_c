#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numDistinct(string S, string T) {
        int m=S.length();
        int n=T.length();
        if(m<n)return 0;
       vector<vector<int> > path(m+1,vector<int>(n+1,0));

       for(int i=0;i<=m;i++)
        path[0][i]=1;
       for(int j=1;j<=m;j++)
       {
           for(int i=1;i<=n;i++)
            path[i][j]=path[i][j-1]+((T[i-1]==S[j-1])?path[i-1][j-1]:0);
       }
       return path[n][m];
    }
};
int main()
{

    return 0;
}
