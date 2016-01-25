class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        int max_profit=0;
        for(int i=1;i<len;++i){
            max_profit+=max(prices[i]-prices[i-1],0);
        }
        return max_profit;
    }
};