#include <iostream>

using namespace std;

void heapAdjust(int a[],int start,int m)
    {
        int rc=a[start];
        for(int j=2*start;j<=m;j*=2)
        {
            if(j<m&&a[j]<a[j+1])++j;
            if(rc>a[j])break;
            a[start]=a[j];
            start=j;
        }
        a[start]=rc;
    }
    void heapSort(int a[],int length)
    {
        /*strat from 1*/
        for(int i=length/2;i>0;i--)
        heapAdjust(a,i,length-1);
        for(int i=length-1;i>1;i--)
        {
            int temp=a[i];
            a[i]=a[1];
            a[1]=temp;
            heapAdjust(a,1,i-1);
        }
    }
    void print(int a[],int length)
    {
        for(int i=1;i<length-1;i++)
            cout<<a[i]<<endl;
    }
int main()
{
    int a[10]={15,23,45,43,23,78,90,56,34,87};
    heapSort(a,10);
    print(a,10);
}
