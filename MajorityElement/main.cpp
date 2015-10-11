#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:

    int majorityElement(vector<int> &num) {
        int len=num.size();
        if(len==1) return num[0];
        int curCount=1;
        int curNum=num[0];
        for(int i=1;i<len;i++)
        {
            if(curCount==0)
            {
                curNum=num[i];
            }
            else
            {
                if(curNum==num[i]){curCount++;}
                else {curCount--;}

            }

        }
        return curNum;




    }
};
int main()
{
    Solution s;
    vector<int> num(2,2);
    cout<<s.majorityElement(num)<<endl;
    return 0;
}
