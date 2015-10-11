#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {

public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> m;
        int len = num.size();
        for (int i = 0; i < len; i++) {
            m[num[i]] = false;
        }

        int res = 0;
        for (int i = 0; i < len; i++) {
            if (m[num[i]]) continue;
            int low = num[i], high = num[i];
            while (m.count(low) != 0) m[low] = true, low--;
            while (m.count(high) != 0) m[high] = true, high++;
            int t = high - low - 1;
            if (t > res) res = t;
        }
        return res;
    }
};
};
int main()
{
int a[]={100,200,1 ,3 ,2,4};
vector<int> num(a,a+6);
Solution s;
cout<<s.longestConsecutive(num);
}
