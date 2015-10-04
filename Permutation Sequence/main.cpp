#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
bool cmp(string a,string b){
	int len = a.size();
	for (int i = 0; i < len; i++){
		if (a[i] == b[i]){
			continue;
		}
		else if (a[i] < b[i]){
			return true;
		}
		else return false;
	}
	return true;
}

class Solution {
public:
	/*
	void permutation(string per, int index, vector<string >&result){
		if (index == per.size()){

			result.push_back(per);
			return;

		}
		for (int i = index; i < per.size(); ++i){
			swap(per[index], per[i]);
			permutation(per, index + 1, result);
			swap(per[index], per[i]);

		}
	}

	string getPermutation(int n, int k) {
		if (k <= 0)return "";
		string per;
		for (int i = 1; i <= n; ++i){
			per.push_back(i + '0');
		}
	    vector<string > result;
		permutation(per, 0, result);
		sort(result.begin(), result.end(), cmp );
		return result[k - 1];



	}*/
	/* optinal solution [10/4/2015 duanchong]
	left part of s ia partially formed permulation,right part is leftOver char
	refenrence:https://leetcode.com/discuss/11023/most-concise-c-solution-minimal-memory-required
	has the same idea but this code is better

	*/
	string getPermutation(int n, int k) {
		string s(n,'0');
		int f = 1,i,j;
		for ( i = 1; i <= n; i++){
			f = f*i;
			s[i - 1] = s[i - 1] + i;
		}
		for ( i = 0, --k; i < n; ++i){
			f = f / (n - i);
			j = i + k/ f;
			char c = s[j];
			for (; j > i; --j){
				s[j] = s[j - 1];
			}
			k = k%f;
			s[i] = c;
		}
		return s;
	}

};
int main()
{
	Solution s;
	string result=s.getPermutation(9, 100);

	return 0;
}
