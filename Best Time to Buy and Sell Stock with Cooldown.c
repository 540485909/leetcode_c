class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (prices.size() < 2) return 0;
		prices.insert(prices.begin(), 0);
		len = len + 1;
		vector<int> dp(len+1,0);
		dp[0] = 0;
		for (int i = 2; i <=len; i++){
			for (int j = 1; j<=i-1; j++){
				int profit= max(prices[i-1] - prices[j] + dp[j-1],dp[j]);
				if (dp[i] < profit){
					dp[i] = profit;
				}
			}
			
		}
		return dp[len];
	}
};