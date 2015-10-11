#include <iostream>
#include <algorithm>
#define red 0
#define white 1
#define blue 2
using namespace std;
class Solution {
public:
    void sortColors(int A[], int n) {
       int i=0,j=n-1;
       while(A[i]==0)i++;
       while(A[j]==2)j--;

       for(int cur=i;cur<=j;)
       {
           if(A[cur]==0)
           {
             swap(A[i],A[cur]);
             i++;
             /*
             this line of code is very important cause i must be in heading of cur;
             */
             if(cur<i)
                cur=i;
           }
           else if(A[cur]==2)
           {
               swap(A[j],A[cur]);
               j--;
           }
           else{cur++;}


       }
    }
};
int main()
{
   Solution s;
   int a[4]={2,1,1,0};//,2,2,1,1,0};
   s.sortColors(a,4);
   for(int i=0;i<4;i++)
    cout<<a[i]<<endl;
    return 0;
}
