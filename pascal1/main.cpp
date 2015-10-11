#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if(numRows==0)return result;
        for(int i=1;i<=numRows;i++)
        {
            vector<int> re;
            re.clear();
            re.push_back(1);
            for(int j=1;j<i;j++)
            {
             re.push_back(result[i-2][j-1]+(j<i-1?result[i-2][j]:0));

            }
            result.push_back(re);
        }
        return result;

    }
        vector<int> getRow(int rowIndex) {
            vector<int> dp(0,rowIndex);

    }
};
int main()
{
}
