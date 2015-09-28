#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len=nums.size();
        if(len<=0||k<0)return false;

       map<int,int> hashMap;
       for(int i=0;i<len;i++){
        if(hashMap.find(nums[i])!=hashMap.end()&&i-hashMap[nums[i]]<k){
            return true;
        }
        else{
            hashMap[nums[i]]=i;
        }
       }
       return false;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
