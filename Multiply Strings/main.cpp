#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "" || num2 == "") return NULL;
		vector<int> value1;
		vector<int> value2;
		for (int i = 0; i < num1.size(); ++i)
			value1.push_back(num1[i] - '0');
		for (int i = 0; i < num2.size(); ++i)
			value2.push_back(num2[i] - '0');
		int len1 = value1.size();
		int len2 = value2.size();
		vector<int> addSum(len1+len2,0);
		int index = 0;
		for (int i = len2-1; i >= 0; --i){
			int k=index++;
			for (int j = len1 - 1; j >= 0; --j){
				addSum[k] += value2[i] * value1[j];
				k++;
			}
		}
		for (int i = 0; i < addSum.size(); ++i){
			if (addSum[i] >= 10){
				if (i + 1 < addSum.size()){
					addSum[i + 1] = addSum[i + 1] + addSum[i] / 10;

				}
				addSum[i] = addSum[i] % 10;
			}
		}
		bool flag = false;
		string s = "";
		for (int i = addSum.size() - 1; i >= 0; --i){
			if (!flag&&addSum[i] == 0){
				continue;
			}
			flag = true;
			s.push_back(addSum[i] + '0');
		}
		return s;
	}
};
int main(){
	Solution s;
	string result=s.multiply("01", "10");
	cout << result << endl;
}
