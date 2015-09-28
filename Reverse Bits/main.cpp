#include <iostream>

using namespace std;

 class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
           uint32_t res=0;
           for(int i=0;i<32;i++)
           {
               res+=(n>>i & 1)*(1<<(31-i));
           }
           return res;
        }
 };
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
