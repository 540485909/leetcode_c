#include <iostream>
#include <string>
using namespace std;
string binToDec(int n){
    string s;
    for(;n>0;){
        s.push_back('0'+n&1);
       n= n>>1;
    }
    return s;
}
int main()
{
    cout<<binToDec(3);
    cout << "Hello world!" << endl;
    return 0;
}
