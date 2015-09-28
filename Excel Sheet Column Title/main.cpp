#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while(n)
        {
            n--;
            result+=n%26+'A';
            n=n/26;
        }
        reverse(result.begin(),result.end());
        return result;

    }
};
int main()
{
    Solution s;
    int value;
    cin>>value;
    cout<<s.convertToTitle(value);
    cout << "Hello world!" << endl;
    return main();
}
