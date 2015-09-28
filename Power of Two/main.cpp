#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0&&(!(n&n-1));
    }
};
int main()
{
    int n=4;
    cout<<(n&n-1)<<endl;
    cout<<(!(n&n-1))<<endl;
}
