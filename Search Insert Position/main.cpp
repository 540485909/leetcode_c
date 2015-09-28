#include <iostream>

using namespace std;
class Solution {
public:
    int searchInsert(int A[], int n, int target) {

      if(n<=0)return 0;
      int i=0;
      int j=n-1;
      while(i<=j)
      {
          int mid=(i+j)/2;
          if(A[mid]==target)return mid;
          else if(A[mid]<target) i=mid+1;
          else j=mid-1;
      }
      return i;

    }
};
int main()
{


}
