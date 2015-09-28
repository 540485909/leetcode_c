#include <iostream>
#include <string.h>
using namespace std;
class Solution {
public:

    int countPrimes(int n) {
        if(n<=1)return 0;
        bool *isPrime=new bool[n];
        memset(isPrime,1,sizeof(isPrime));
        for(int i=2;i*i<n;i++){
            if(!isPrime[i]){
                continue;
            }
            for(int j=i*i;j<n;j=j+i){
                isPrime[j]=false;
            }
        }
        int count=0;
        for(int i=2;i<n;i++){
           if(isPrime[i]){
               count++;
           }
        }
        return count;
    }
};
int main()
{
    Solution s;
    cout<<s.countPrimes(5);
    return 0;
}
