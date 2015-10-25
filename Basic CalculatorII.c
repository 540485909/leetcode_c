#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
	bool isBig(const char &a,const char &b){
		if (a == '*' || a == '/'){
			if (b == '+' || b == '-'){
				return true;
			}
			return false;
		}
		return false;
	}
	int cal(const int &a,const int &b,const char &ch){
		if (ch == '+'){
			return a + b;
		}
		else if (ch == '-'){
			return a - b;
		}
		else if (ch == '*'){
			return a*b;
		}
		else{
			return a / b;
		}
	}
	int calculate(string s) {
		int len = s.size();
		stack<int> operNum;
		stack<char> operFun;
		string subStr="";
		for (auto i = 0; i < len; ++i){
			
			if (s[i] == '+' || s[i] == '-'
				|| s[i] == '*' || s[i] == '/')
			{
				operNum.push(atoi(subStr.c_str()));
				subStr.clear();
				/*deal with operator stack*/
				if (operFun.empty()){
					operFun.push(s[i]);
				}
				else{
					if (isBig(s[i], operFun.top())){
						operFun.push(s[i]);
					}
					else{
						while (!operFun.empty() && !isBig(s[i], operFun.top())){
							int value1 = operNum.top();
							operNum.pop();
							int value2 = operNum.top();
							operNum.pop();
							char ch = operFun.top();
							operFun.pop();
							operNum.push(cal(value2, value1, ch));
						}
						operFun.push(s[i]);
						
					}
					
				}
			}
			else
			{
				subStr.push_back(s[i]);
			}
		}
		if (subStr != "")
			operNum.push(atoi(subStr.c_str()));
		while (!operFun.empty()){
			int value1 = operNum.top();
			operNum.pop();
			int value2 = operNum.top();
			operNum.pop();
			char ch = operFun.top();
			operFun.pop();
			operNum.push(cal(value2,value1,ch));

		}
		return operNum.top();
	}
};

int main()
{

	Solution s;
	string str = "4/2";
	cout<<s.calculate(str);
	
	

	return 0;
}
