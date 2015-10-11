#include <iostream>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if(n==0)return "";
        if(n==1)return "1";
        string res="1";
        string s;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<res.size();j++)
            {
                int cou=1;
                while(j+1<res.size()&&res[j]==res[j+1])
                {
                    cou++;
                    j++;
                }
                s.push_back(cou+'0');
                s.push_back(res[j]);
            }
            res=s;
            s.clear();

        }
        return res;

    }
};
int main()
{
   Solution s;
   int value;
   cin>>value;
   cout<<s.countAndSay(value);
    return main();
}
