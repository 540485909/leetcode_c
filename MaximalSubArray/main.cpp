/*
分治法（divide and conquer）

注意到A[1...n]的最大子串A[i..j]可能来自于以下三种情况中的一种：

1 ≤ i ≤ j ≤ n/2，也即最大子串出现在原串的左半部分
n/2 ≤ i ≤ j ≤ n，也即最大子串出现在原串的右半部分
1 ≤ i ≤ n/2 ≤ j ≤ n，也即最大子串部分来自原串的最半部分，部分来自原串的右半部分
因此我们可以分别计算这三种情况下的解，然后将这三个解中最好的一个选出作为整个问题的解。

针对前两种情况，其实就相当于把问题的规模缩小了（divide）。把求长度为n的数组的最大子串变为求长度最n/2的数组的最大子串。这个规模变小了的问题的解同样可能有三种情况。对其中的前两种情况，我们依然采取细分的方法。可是，这样的细分会有头吗？当然会的，到了最后，我们会得到一个个长度为1的数组，在这种极限情况下，我们就不必考虑三种情况，因为此时的最大子串显然就是这个长度为1的子串自己（conquer）。

而针对第三种情况，我们采取另一种策略，即不是将问题化为相同的更小规模的问题，而是直接求解。我们首先求出A[i...n/2]使其为A[1...n/2]的最大子串，这里，进行一次遍历即可，时间复杂度为O(n)。同理，我们也可以求出A[n/2...j]使其为A[n/2...n]的最大子串。将这2个最大子串合在一起，就得到了所有会跨越串的中部的子串中的最大子串。

总结起来，假如使用T(n)代表使用此方法求解大小为n的数组的最大子串问题所消耗的时间，则有：

T(n) = 2T(n/2) + O(n)，n>1
T(1) = O(1)，n=1
不难发现，此时求解整个问题的时间复杂度为O(nlogn)。

http://blog.csdn.net/mitkook/article/details/7431951

*/

#include <iostream>

using namespace std;
class Solution {
public:
    int solve(int A[],int low,int high)
    {
        if(low==high)return A[low];
        int mid=(low+high)/2;
        int leftSum=solve(A,0,mid);
        int rightSum=solve(A,mid+1,high);
        int left=A[mid];
        int  sum=A[mid];
        for(int i=mid-1;i>=low;i--)
        {
            sum=sum+A[i];
            left=max(sum,left);
        }
        sum=A[mid];
        int right=A[mid];
        for(int i=mid+1;i<high;i++)
        {
            sum=sum+A[i];
            right=max(right,sum);
        }
        return max(max(leftSum,rightSum),left+right);

    }
    int maxSubArray(int A[], int n) {
        return solve(A,0,n-1);
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
