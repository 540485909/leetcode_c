#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n=matrix.size();
        if(n==0)return false;
        int m=matrix[0].size();
        int low=0,high=n-1;
        int row=0;
        while(low<high)
        {
           int mid=(low+high)>>1;
           if(target==matrix[mid][0])return true;
           else if(target>matrix[mid][0])
          {
              if(target<matrix[mid+1][0])row=mid;
              else low=mid;
          }
          else
          {
              high=mid;
          }

        }
        low=0,high=m-1;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(target==matrix[row][mid])return true;
            else if(target<matrix[row][mid]){
                high=mid-1;
            }
            else low=mid+1;
        }
        return false;

    }
};
int main()
{
    Solution s;
    vector<vector<int> > matrix;
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(2);
    matrix.push_back(temp);

    cout<<s.searchMatrix(matrix,2);
    return 0;
}
