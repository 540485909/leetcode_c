#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:

    int compareVersion(string version1, string version2) {
        vector<int> vervec1;
        vector<int> vervec2;

        splitVersionString(version1, vervec1);
        splitVersionString(version2, vervec2);

        int maxI = max(vervec1.size(), vervec2.size());
        int i;
        for (i=0; i<maxI; ++i)
        {
            int v1 = i<vervec1.size() ? vervec1[i] : 0;
            int v2 = i<vervec2.size() ? vervec2[i] : 0;

            if (v1 < v2)
            {
                return -1;
            }
            else if (v1 > v2)
            {
                return 1;
            }
        }

        return 0;
    }

private:
    static void splitVersionString(string version,
                              vector<int>& vervec)
    {
        int tmp = 0;
        for(size_t i=0; i<version.size(); ++i)
        {
            if (version[i] == '0' && tmp == 0)
            {
                continue;
            }
            else if (version[i] != '.')
            {
                tmp = tmp * 10 + atoi(&version[i]);
            }
            else
            {
                vervec.push_back(tmp);
                tmp = 0;
            }
        }

        vervec.push_back(tmp);
    }

};
int main()
{
   Solution s;
   cout<<s.compareVersion("1.0","1.10")<<endl;
    return 0;
}
