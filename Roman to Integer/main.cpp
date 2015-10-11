#include <iostream>
#include <map>
using namespace std;
int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int length = s.length();
    	if(length <1) return 0;
		map<char,int> m;
		m['I'] = 1;
		m['V'] = 5;
		m['X'] = 10;
		m['L'] = 50;
		m['C'] = 100;
		m['D'] = 500;
		m['M'] = 1000;
		int i = length-1;
		int sum = m[s[i--]];
		while(i>=0)
			if(m[s[i+1]] > m[s[i]])
				sum -= m[s[i--]];
			else
				sum += m[s[i--]];
		return sum;
    }


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
