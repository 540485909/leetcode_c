#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <fstream>
#include <unordered_set>
#include <set>
using namespace std;
class Solution {
public:
	int numSquares(int n) {
		if (n <= 0) return 0;
		vector<int> dp(n + 1, 10000000);
		dp[0] = 0;

		for (int i = 1; i <= n; i++){
			for (int j = 0; j*j <= i; ++j){
				dp[i] = min(dp[i], dp[i - j*j] + 1);
			}
		}
		return dp[n];
	}
};




int main(){
	
	Solution s;
	cout<<s.numSquares(12);



}
