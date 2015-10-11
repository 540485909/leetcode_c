#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int> >&result,vector<int> &curRes,vector<int> &num,int sum,int target,int index){
        if(sum==target)
        {
            result.push_back(curRes);
            return;
        }
        if(sum>target)return;
        if(sum<target)
        {
            for(int i=index;i<num.size();i++){
                int c=curRes.size();
                curRes.push_back(num[i]);
                dfs(result,curRes,num,sum+num[i],target,i+1);
                curRes.resize(c);

            }


        }

    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> >result;
        vector<int> curRes;
        sort(num.begin(),num.end());

        dfs(result,curRes,num,0,target,0);
        sort(result.begin(),result.end());
        vector<vector<int> >::iterator newEnd= unique(result.begin(),result.end());
        result.erase(newEnd,result.end());
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> num;
    num.push_back(10);
    num.push_back(1);
    num.push_back(2);num.push_back(7);num.push_back(6);num.push_back(1);num.push_back(5);
    s.combinationSum2(num,8);
    return 0;
}
