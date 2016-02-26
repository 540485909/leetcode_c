/*
319. Bulb Switcher
*There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. 
On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). 
For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

Example:

Given n = 3. 

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.
*
*/
/*
319. Bulb Switcher
*There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb.
On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on).
For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

Example:

Given n = 3.

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off].

So you should return 1, because there is only one bulb is on.
*
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int bulbSwitch(int n) {
		if (n == 1) return 1;
		vector<int> array(n + 1, 1);
		for (int i = 2; i < n; ++i)//the last round need to consider expecially
		{
			for (int j = i; j <= n; j+=i)
			{
				
				array[j] = -array[j];
		

			}
		}
		array[n] = -array[n];
		int result = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (array[i]==1)
			{
				result++;
			}
		}
		return sqrt(n);
	}
	
};
int main()
{
	Solution s;
	cout << s.bulbSwitch(4) << endl;
}