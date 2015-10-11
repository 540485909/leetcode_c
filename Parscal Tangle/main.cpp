#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        result.push_back(1);
        for(int i=1;i<=rowIndex;i++)
        {
            int p=1;
            int temp;
            for(int j=1;j<i;j++)
            {
                temp=p;
                p=result[j];
                result[j]=temp+result[j];

            }
            result.push_back(1);
        }

        return result;
    }
};
int main()
{
    Solution s;
    vector<int> result=s.getRow(3);

    cout <<result[1]<< endl;
    return 0;
}
