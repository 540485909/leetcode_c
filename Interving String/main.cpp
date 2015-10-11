#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length())return false;
        if(s1.length()==0)return (s2==s3);
        if(s2.length()==0)return (s1==s3);
        int len1=s1.length();
        int len2=s2.length();
        int len3=s3.length();
        bool match[len1+1][len2+1];
        match[0][0]=true;
        for(int i=1;i<=len1;i++)
        {
            if(s1[i-1]==s3[i-1])match[i][0]=true;
            else break;
        }
        for(int j=1;j<=len2;j++)
        {
            if(s2[j-1]==s3[j-1])match[0][j]=true;
            else break;
        }
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                match[i][j]=(match[i-1][j]&&(s3[i+j-1]==s1[i-1])||match[i][j-1]&&(s2[j-1]==s3[i+j-1]));
            }
        }
        return match[len1][len2];
    }
};
int main()
{
   string s1 = "a";
string s2 = "b";
string s3 = "ab";
Solution s;
cout<<s.isInterleave(s1,s2,s3);
    return 0;
}
