#include <iostream>

using namespace std;
class Solution {
public:
    int sqrt(int x) {
      unsigned long long right=x/2+1;
      unsigned long long left=0;
      unsigned long long mid;
      while(left<=right)
      {
          mid=(left+right)/2;
          if(mid*mid==x)return mid;
          else if(mid*mid>x)right=mid-1;
          else left=mid+1;
      }
      return right;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
