#include <iostream>

using namespace std;
class Solution {
public:
    double findKValue(int A[],int m,int B[],int n,int k)
    {
        if(m>n)return findKValue(B,n,A,m,k);
        if(m==0)return B[k-1];
        if(k==1)return min(A[0],B[0]);
        //divied k into two parts
        int part1=min(k/2,m);
        int part2=k-part1;
        if(A[part1-1]<B[part2-1])return findKValue(A+part1,m-part1,B,n,k-part1);
        if(A[part1-1]>B[part2-1])return findKValue(A,m,B+part2,n-part2,k-part2);
        else return A[part1-1];
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int k=m+n;
        if(k%2==1)return findKValue(A,m,B,n,k/2+1);
            else return (findKValue(A,m,B,n,k/2+1)+findKValue(A,m,B,n,k/2))/2;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
