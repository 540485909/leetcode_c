#include <iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
class Solution {
public:
    int stoi(string s)
    {
        int sum=0;
        for(int i=0;i<s.length();i++)
            sum=10*sum+(s[i]-'0');
        return sum;
    }
    bool isValid(string s )
    {
        if(s[0]=='0')return false;
        int num=stoi(s);
        if(num>=1&&num<=26)
            return true;
        else return false;
    }
    int numDecodings(string s) {
     if(s.length()==0)return 0;
     if(s[0]=='0')return 0;
     int number[s.length()+1];
     memset(number,0,sizeof(number));
     number[0]=1;
     number[1]=1;
     for(int i=2;i<=s.length();i++)
     {

        if(isValid(s.substr(i-1,1)))
            number[i]=number[i-1];
        if(isValid(s.substr(i-2,2)))
            number[i]+=number[i-2];
     }
     return number[s.length()];




    }
};

int main()
{

    Solution s;
    cout<<s.numDecodings("101")<<endl;
    return 0;
}
