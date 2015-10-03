#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void combination(vector<vector<int> >&result, vector<int> cur,  int k, int n){
		if (cur.size() == k&&n == 0){
			result.push_back(cur);

			return;
		}
		if (cur.size<k){

			for (int i = cur.empty()?1:cur.back()+1; i <= 9; i++){
				cur.push_back(i);
				combination(result, cur,  k, n-i);
				cur.pop_back();
			}


		}

	}
	vector<vector<int>> combinationSum3(int k, int n) {

		vector<vector<int>> result;
		vector<int> sol;
		combination(result, sol, k, n);
		return result;



	}
};
class Solution1 {
public:
	void combination(vector<vector<int>>& result, vector<int> sol, int k, int n) {
		if (sol.size() == k && n == 0) { result.push_back(sol); return; }
		if (sol.size() < k) {
			for (int i = sol.empty() ? 1 : sol.back() + 1; i <= 9; ++i) {
				if (n - i < 0) break;
				sol.push_back(i);
				combination(result, sol, k, n - i);
				sol.pop_back();
			}
		}
	}

	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> result;
		vector<int> sol;
		combination(result, sol, k, n);
		return result;
	}
};
int main()
{
	Solution s;
	vector<vector<int> >result=s.combinationSum3(4, 24);
	return 0;
}
