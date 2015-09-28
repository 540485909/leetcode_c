#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Solution {
public:
    int add(char a,char b,int in,int &out)
    {
        int t1=a-'0';
        int t2=b-'0';
        if(t1+t2+in>1)
        out=1;
        return (t1+t2+in)%2;



    }
    string addBinary(string a, string b) {
        if(a=="")return b;
        if(b=="")return a;
        string c;
        if(a.length()>b.length())
        c.resize(a.length()+1,'0');
        else c.resize(b.length()+1,'0');
        for(int i=0;i<c.length();i++)
            c[i]='0';
        int i=a.length()-1;
        int j=b.length()-1;
        int temp=max(i,j);
        int mi=min(i,j);
        int ma=temp+1;
        int prev=0;
        int carry=0;


        while(ma>=0&&mi>=0)
        {

            c[ma]=(add(a[i],b[j],prev,carry))+'0';
            prev=carry;
            carry=0;
            ma--;
            mi--;
            i--;
            j--;


        }
        while(i>=0)
        {
            c[ma--]=(add(a[i],'0',prev,carry))+'0';
            i--;
            prev=carry;
            carry=0;
        }
        while(j>=0)
        {
            c[ma--]=(add('0',b[j],prev,carry))+'0';
            j--;
            prev=carry;
            carry=0;
        }
        if(prev!=0)
        c[ma]=prev+'0';
        int k=0;
        for(;k<c.length()-1;k++)
        {
            if(c[k]=='0')continue;
            else break;
        }
        return c.substr(k);

    }
};
int main()
{
   Solution s;
   string result=s.addBinary("11","1");
   cout<<result<<endl;
    return 0;
}
