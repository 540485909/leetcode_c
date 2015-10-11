#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int reve(int x)
    {
     int result=0;
     do
     {
         result=(x%10)+result*10;
         x=x/10;
     } while(x);
     return result;
    }

    }
    int reverse(int x) {
        if(x<0)return -1*reve(-x);
        else return reve(x);
    }

};
int main()
{
    int x=-765;
    cout <<reverse(x)<< endl;
    return 0;
}
