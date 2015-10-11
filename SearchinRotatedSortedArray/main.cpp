#include <iostream>

using namespace std;
class Solution {
public:
    int search(int A[], int n, int target) {
        if(n==0)return -1;
        if(n==1) return (target==A[0])?target:-1;
        int left=0,right=n-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(A[mid]==target)return mid;
            if(A[mid]>=A[left])
            {
                if(target>=A[left]&&target<A[mid])
                {
                    right=mid-1;
                }
                else
                {
                    left=mid+1;
                }
            }
             else //(A[mid]<A[left])
             {
                if(target>A[mid]&&target<=A[right])
                {
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }
            }
        }
        return -1;
    }
};
int main()
{
   Solution s;
   int A[]={1};
   cout<<s.search(A,1,0)<<endl;
    return 0;
}
