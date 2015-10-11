#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
        int i=-1,j=-1;
        if(n==0|| n==1&&A[0]!=target){result.push_back(i);result.push_back(j);return result;}
        int low=0,high=n-1;
        int mid;
        while(low<=high)
        {
            mid=(high+low)>>1;
            if(target==A[mid])
            {
                i=mid;
                j=mid;
                while(i-1>=0&&A[i-1]==A[mid])i--;
                while(j+1<n&&A[j+1]==A[mid])j++;
                break;
            }
            else if(target<A[mid])
            {
                high=mid-1;
            }
            else low=mid+1;
        }
        result.push_back(i);
        result.push_back(j);
        return result;
    }
};
int main()
{
   Solution s;
   int arr[]={5, 7, 7, 8, 8, 10};
   vector<int>result=s.searchRange(arr,6,8);
   cout<<result[0]<<result[1]<<endl;

    return 0;
}
