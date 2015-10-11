#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    bool isomorphic(string s,string t)
    {
        int len=s.size();
        map<char,char> st;
        if(len==0)return true;
        map<char,char>::iterator it;
        for(int i=0;i<len;i++)
        {
            it=st.find(s[i]);
            if(it!=st.end())
            {
                continue;
            }
            else
            {
                st[s[i]]=t[i];

            }

        }
        for(int i=0;i<len;i++)
        {
            it=st.find(s[i]);
            if(it!=st.end())
            {
                s[i]=it->second;
            }

        }
        return s==t;

    }
    bool isIsomorphic(string s, string t) {

     return isomorphic(s,t)&&isomorphic(t,s);
    }
};
int main()
{
    Solution s;
    cout<<s.isIsomorphic("ab","aa")<<endl;
    cout<<s.isIsomorphic("foo","bar")<<endl;
    cout<<s.isIsomorphic("paper","title")<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
