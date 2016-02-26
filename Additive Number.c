/*
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199

note: long long integer must be used or data will overflow

*/
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
using namespace std;
class Solution {
public:
	bool isAdditiveNumber(string num) {
		int len = num.size();
		if (len < 3) return false;
		int long_len = len / 2;
		for (int i = 1; i <= long_len; ++i)
		{

			for (int j = 1; j <= (len-i)/2; ++j){
				if (check(num.substr(0, i), num.substr(i, j), num.substr(i + j)))
				return true;
			}

		}
		return false;
	}



	bool check(string first, string middle, string last){
		if (first.size()>1&&first[0] == '0'||middle.size()>1&&middle[0] == '0') return false;
	
		first = to_string(atoll(first.c_str())+atoll(middle.c_str()));
		if (first == last) return true;
		if (first != last.substr(0, first.size())) return false;
		return check(middle, first, last.substr(first.size()));

	}

};
int main()
{
	Solution s;
	string str = "121474836472147483648";
	cout<<s.isAdditiveNumber(str);
}