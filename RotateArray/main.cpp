#include <iostream>

using namespace std;
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if(k>n)k=k%n;
        if(n==0||n==1)return;
        int arr[k];
        int j=0;
        for(int i=n-k;i<n;i++){
            arr[j++]=nums[i];
        }
        for(int i=n-k-1;i>=0;i--){
           nums[i+k]=nums[i];
        }
        for(int i=0;i<k;i++)
            nums[i]=arr[i];
    }
};
int main()
{
    int num[]={1,2,3,4,5,6,7};
    Solution s;
    s.rotate(num,7,3);
    for(int i=0;i<7;i++)
        cout<<num[i]<<" ";
    return 0;
}
