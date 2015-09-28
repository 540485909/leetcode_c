#include <iostream>

using namespace std;
class Solution {
public:
    int titleToNumber(string s) {
        int sum=0;
        int temp=0;
        for(int i=0;i<s.size();i++)
        {
            temp=s[i]-'A'+1;
            sum=26*sum+temp;
        }
        return sum;

    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
