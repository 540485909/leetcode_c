#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> val;
        val.push_back(0);
        val.push_back(0);
        int len=nums.size();
         int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
         diff&=-diff;
         for(int i=0;i<len;i++)
         {
             if((nums[i]&diff)==0)
             {
                 val[0]^=nums[i];
             }
             else{
                val[1]^=nums[i];
             }
         }
         return val;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
