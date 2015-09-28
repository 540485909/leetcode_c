#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
//忘记考虑溢出问题！！！How can I forget???!!!
	int divide(int dividend, int divisor)
	{
		long long a = dividend;
		long long b = divisor;
		a = abs(a); b = abs(b);
		int res = 0;
		while (a>=b)
		{
			long long t = b;
			for (int i = 1; a >= t; i <<= 1, t <<= 1)
			{
				a -= t;
				res += i;
			}
		}
		return ((dividend<0)^(divisor<0))? -res:res;
	}

};
int main()
{
    Solution s;
    cout<<s.divide(1,1)<<endl;
    return 0;
}
