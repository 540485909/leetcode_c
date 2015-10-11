#include <iostream>
#include <map>
#include <math.h>
using namespace std;
int cal(int x,int n)
{
    if(n==1)return x;
    if(n%2==1)return x*pow(cal(x,(n-1)/2),2);
    else return pow(cal(x,n/2),2);
}
int macal(int x,int n)
{
    if(x==1)return n;
    int fenmu=1-x;
    return (1-cal(x,n))/fenmu;
}
int normalCal(int x,int n)
{
    int temp=1;
    for(int i=0;i<n;i++)
    {

        temp=x*temp;
    }
    return temp;
}
int main()
{
    cout<<macal(2,100)<<endl;
    cout<<normalCal(2,100);
  /* int a[52]={0};
    string s="RBBbWWBRBw";
    for(int i=0;i<s.length();i++)
    {
        if(65<=s[i]&&s[i]<=91)
           a[(s[i]-65)*2+1]++;
        else a[(s[i]-97)*2]++;
    }
    for(int i=0;i<52;i++)
    {
        while(a[i]>0)
        {
            if(i%2==1)cout<<(char)((i-1)/2+65)<<" ";
            else cout<<(char)(i/2+97)<<" ";
            a[i]--;
        }
    }*/

    return 0;
}
