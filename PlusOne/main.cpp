#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len=digits.size();
        reverse(digits.begin(),digits.end());
        digits[0]=digits[0]+1;
        int carry=0;
        for(int i=0;i<len;i++)
        {
            if(digits[i]+carry>=10)
            {
                digits[i]=digits[i]%10+carry;
                carry=1;
            }
            else break;

        }
        if(digits[len-1]==0)
        digits.push_back(1);
        reverse(digits.begin(),digits.end());
        return digits;


    }
};
int main()
{
    Solution s;
    vector<int> result;
    result.push_back(9);
    result.push_back(9);
    result=s.plusOne(result);
    cout << "Hello world!" << endl;
    return 0;
}
