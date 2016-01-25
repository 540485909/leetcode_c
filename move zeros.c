class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const size_t len=nums.size();
        size_t index=0;
        for(int i=0;i<len;++i){
            if(nums[i]!=0){
                nums[index++]=nums[i];
            }
        }
        for(int i=index;i<len;++i){
            nums[i]=0;
        }
        
    }
};