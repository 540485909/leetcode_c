#include <iostream>

using namespace std;
class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int i=0,j=0;
        while(haystack[i]!='\0'&&needle[j]!='\0')
        {
            if(haystack[i]==needle[j]){
                i++;j++;
            }
            else {
                i=i-j+1;
                j=0;
            }
        }
        return needle[j]?-1:i-j;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
