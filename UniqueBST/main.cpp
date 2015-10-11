#include <iostream>

using namespace std;
class Solution {
public:
    int numTrees(int start,int tail)
    {
        if(start>=tail)
            return 1;
        int total=0;
        for(int i=start;i<=tail;i++)
            total+=numTrees(start,i-1)*numTrees(i+1,tail);
            return total;
    }
    int numTrees(int n) {
        return numTrees(1,n);
    }
};
int main()
{
    Solution s;
   cout<< s.numTrees(2);
    return 0;
}
