#include <iostream>

using namespace std;
class Solution {
public:
    int addDigits(int num) {
        if(num==0)return 0;
        if (num%9==0)return 9;
        else  return num%9;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
