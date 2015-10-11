#include <iostream>

using namespace std;
/*解题的关键在于把右边的一一次去掉一个*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
    while(m<n){
          n=n&(n-1);
      }
      return n;

    }
};
int main()
{
    Solution s;
    cout<<s.rangeBitwiseAnd(5,7);
    cout << "Hello world!" << endl;
    return 0;
}
