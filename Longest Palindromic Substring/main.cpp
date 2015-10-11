#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        int prefix,surfix;
        int maxSubStr=-1;
        int j=0;
        if(len==0||len==1)return s;
        for(int i=0;i<len;i++){
                //to deal with the case that the length is odd
            for(j=0;i-j>=0&&i+j<len;j++){
                if(s[i-j]==s[i+j]){

                    if(maxSubStr<2*j+1){
                         prefix=i-j;
                        surfix=i+j;
                        maxSubStr=2*j+1;

                    }

                }
                else break;
            }
            //to deal with the case that the size is even
            for(j=0;i-j>=0&&i+j+1<len;j++){
                if(s[i-j]==s[i+j+1]){
                   if(maxSubStr<2*j+2){
                        prefix=i-j;
                   surfix=i+j+1;
                    maxSubStr=j*2+2;
                   }
                }
            }

        }
          return s.substr(prefix,maxSubStr);
    }
};
int main()
{
    cout << "Hello world!" << endl;
    Solution s;
    string result=s.longestPalindrome("aaabaaaa");
    cout<<result<<endl;
    return 0;
}
