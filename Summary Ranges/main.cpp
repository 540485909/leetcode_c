#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
class Solution {
public:
    string format(int begin,int end){
        char buffer[32];
        if (begin==end){
            sprintf(buffer,"%d",begin);
        }
        else{
            sprintf(buffer,"%d->%d",begin,end);
        }
        return string(buffer);
    }
    vector<string> summaryRanges(vector<int>& nums) {
        int len=nums.size();
        vector<string> res;
        if(len==0)return res;
        int begin,end;
         begin=nums[0];
        for(int i=0;i<len-1;i++){
            end=nums[i];
            if (end+1==nums[i+1]){
               continue;
            }

            res.push_back(format(begin,end));
            begin=nums[i+1];

        }

        res.push_back(format(begin,nums[len-1]));


        return res;

    }
};
int main()
{
    Solution s;
    int a[6]={0,1,2,4,5,7};
    vector vec(a,a+6);
    s.summaryRanges(vec);
    cout << "Hello world!" << endl;
    return 0;
}
