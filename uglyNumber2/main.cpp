#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int nthUglyNumber(int n) {
     int id2=0,id3=0,id5=0,res=1;
     int v2,v3,v5;
     vector<int> result;
     while(--n){
        result.push_back(res);
        v2=2*result[id2],v3=3*result[id3],v5=5*result[id5];
        res=min(v2,min(v3,v5));
        id2+=(res==v2),id3+=(res==v3),id5+=(res==v5);

     }
     return res;
    }


};
using namespace std;

int main()
{
    Solution s;
    cout<<s.nthUglyNumber(8);
    return 0;
}
