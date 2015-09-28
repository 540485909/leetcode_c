#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int> &num) {
      if(num.size()<=1) return;
    int i=num.size()-1,j;
    for(j=num.size()-2; j>=0; j--){
        if(num[j]<num[j+1]) break;
    }
    if(j>=0){
        while(num[i]<=num[j]) i--;
        swap(num[i], num[j]);
    }
    reverse(num.begin()+j+1, num.end());
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
