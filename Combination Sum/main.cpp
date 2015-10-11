#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
     vector<vector<int> > result;
     vector<int> path;
     int currentSum=0;
     combinationSumHelper(candidates,result,path,currentSum,target,0);
     return result;
    }
    void combinationSumHelper(vector<int> &candidates,vector<vector<int> > &path,vector<int> &currentPath,int currentSum,int target,int index)
    {
        if(currentSum==target)
        {
            path.push_back(currentPath);
            return ;
        }
        if(currentSum>target)return ;
        if(currentSum<target)
        {
            for(int i=index;index<candidates.size();index++)
                {
                    currentPath.push_back(candidates[i]);
                    combinationSumHelper(candidates,path,currentPath,currentSum+candidates[i],target,i);
                    currentPath.pop_back();
                }
        }

    }
};
int main()
{
    Solution s;
    vector<int> canditates;
    canditates.push_back(2);
    canditates.push_back(3);
    canditates.push_back(4);
    canditates.push_back(7);
    s.combinationSum(canditates,7);
    return 0;
}
