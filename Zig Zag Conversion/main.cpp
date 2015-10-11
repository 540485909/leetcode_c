#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    string convert(string s, int nRows) {
        size_t len=s.size();
        if(nRows<=1||nRows>=len)return s;
        string result;
        size_t pos;
        int maxStep=(nRows-1)*2;
        for(int r=0;r<nRows;r++)
        {
            pos=r;
            if(r==0||r==nRows-1)
            {
                while(pos<len)
                {
                    result.push_back(s[pos]);
                    pos=pos+maxStep;
                }

            }
            else{
                int step=2*r;
                while(pos<len)
                {
                    result.push_back(s[pos]);
                    step=maxStep-step;
                    pos+=step;
                }
            }

        }
        return result;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    Solution s;
    cout<<s.convert("PAYPALISHIRING", 3);
    return 0;
}
