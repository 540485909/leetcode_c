#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);

        for(int i=0;i<n;i++)
        {
            int a=1<<i;
            for(int j=result.size()-1;j>=0;j--)
                result.push_back(result[j]+a);
        }
        return result;

    }
};
int main()
{
   Solution s;
   s.grayCode(3);
}
