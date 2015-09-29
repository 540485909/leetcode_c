#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int a=0,b=0;
        vector<int> result;

        for(int i=0;i<nums.size();i++){
            if(cnt1==0||a==nums[i]){
               cnt1++;
               a=nums[i];
            }else if(cnt2==0||b==nums[i]){
               cnt2++;
               b=nums[i];
            }else{
               cnt1--;
               cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(a==nums[i]){
                cnt1++;
            }
            if(b==nums[i]){
                cnt2++;
            }
        }
        if(cnt1>nums.size()/3)result.push_back(a);
        if(cnt2>nums.size()/3&&a!=b)result.push_back(b);
        return result;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
