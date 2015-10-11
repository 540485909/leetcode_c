#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum=0;
        int total=0;
        int startIndex=-1;
        for(int i=0;i<gas.size();i++)
        {
            sum+=gas[i]-cost[i];
            total+=gas[i]-cost[i];
            if(sum<0)
            {
                startIndex=i;
                sum=0;
            }
        }
        return total>0?startIndex+1:-1;

    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
