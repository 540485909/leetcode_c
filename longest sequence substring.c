class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=nums.size();
        if(len<=0) return 0;
        vector<int> dp(len,1);
        for(int i=1;i<len;++i){
            int maxValue=1;
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j]){
                    if(maxValue<dp[j]+1){
                        maxValue=dp[j]+1;
                    }
                }
            }
            dp[i]=maxValue;
        }
        int result=1;
        for(int i=0;i<dp.size();++i){
           if(result<dp[i]) {
               result=dp[i];
           }
        }
        return result;
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       /* int len=nums.size();
        int vector<int> vec;
        int ans = 0;
        for(int i=0;i<len;i++) {
            if(vec.empty()||nums[i]>vec.pop_back()){
            
                vec.push_back(nums[i]);
            }            vec[pos] = nums[i];
        }
        return ans;*/
        int a[100010];
        int len = nums.size();
        fill(a,a+100000,0x3f3f3f3f);
        for(int i=0;i<len;i++) {
            *lower_bound(a,a+100000,nums[i]) = nums[i];
        }
        return lower_bound(a,a+100000,0x3f3f3f3f) - a;
    }
};