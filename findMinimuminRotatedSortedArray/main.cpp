#include <iostream>
#include <vector>
using namespace std;
/*
class Solution {
public:
    int findMin(vector<int> &num) {
        int len=num.size();
        if(len<=1)return num[0];
        int low=0,high=len-1;
        while(low<high)
        {
            if(num[low]<num[high])
            return num[low];
            int mid=(low+high)>>1;
            if(num[mid]>num[low])
            {
                low=mid;
            }
            else if(num[mid]<num[low]){
                high=mid;

            }
            else return (num[mid]<num[mid+1])?num[mid]:num[mid+1];
        }


    }
};*/
class Solution {
public:
    int search(int A[], int n, int target) {
        if(n==0)return -1;

        int low=0;
        int high=n-1;
        while(low<high)
        {
            int mid=(low+high)>>1;
            if(target==A[mid])return mid;
            else if(A[mid]>A[low])
            {
                if(target>A[mid])
                    low=mid;
                    else{
                     if(target<A[low])low=mid;
                        else high=mid;


                    }


            }else if(A[mid]<A[low])
            {
                if(target<A[mid])
                high=mid;
                else{
                    if(target>A[low])high=mid;
                    else low=mid;
                }
            }
            else
            {
                if(A[high]==target)return high;
            }
        }
        return -1;

    }
};
int main()
{

    int arr[]={3,4,5,6,1,2};
    vector<int> vec(arr,arr+sizeof(arr)/sizeof(int));
    Solution s;
   cout<<s.search(arr,6,5);
    return 0;
}
