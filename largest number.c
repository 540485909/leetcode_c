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
/*
const int MaxNumberLength = 10;
char* strCombine1 = new char[2 * MaxNumberLength + 1];
char* strCombine2 = new char[2 * MaxNumberLength + 1];
int compare(const void *strNumber1, const void *strNumber2){
strcpy(strCombine1, *(const char**)strNumber1);
strcat(strCombine1, *(const char **)strNumber2);

strcpy(strCombine2, *(const char**)strNumber2);
strcat(strCombine2, *(const char **)strNumber1);
return strcmp(strCombine2, strCombine1);
}
class Solution {
public:

string largestNumber(vector<int>& nums) {

int len = nums.size();
if (len == 0) return "";
char ** strNumbers = (char **)(new int[len]);
for (int i = 0; i < len; ++i){
strNumbers[i] = new char[MaxNumberLength + 1];
sprintf(strNumbers[i], "%d", nums[i]);
}
qsort(strNumbers, len, sizeof(char*), compare);
string s;
for (int i = 0; i < len; ++i){
s += string(strNumbers[i]);
}
return s;
}
};*/
class Solution {
private:
	static bool compare(const string &a, const string &b){
		string combine1 = a + b;
		string combine2 = b + a;
		return combine1 > combine2;
	}
public:
	string largestNumber(vector<int>& nums) {

		int len = nums.size();
		if (len == 0) return "";
		vector<string> arrString(len);
		for (int i = 0; i < len; ++i){
			arrString[i] = to_string(nums[i]);
		}
		sort(arrString.begin(), arrString.end(), compare);
		string result;
		for (int i = 0; i < arrString.size(); ++i){
			result += arrString[i];
		}
		if (result[0] == '0')
			return "0";
		return result;

	}
};

int main()
{
	
	Solution s;

	int a[] = { 3, 30, 34,  5, 9 };
	vector<int> vec(a,a+5);

	cout<<s.largestNumber(vec);

	return 0;
}
