#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int len=strs.size();
        if(len==0)return "";
      string result="";
        int j,i;
        int record;
        bool flag=false;
       for(j=0;;j++)
        {
           for( i=0;i<len;i++)
           {
               if(j>=strs[i].length()||strs[i][j]!=strs[0][j])break;
           }
            if(i<len)break;
            result+=strs[0][j];
        }
        return result;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
