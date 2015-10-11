#include <iostream>

using namespace std;
/*

只有2和5相乘才会出现0，其中整十也可以看做是2和5相乘的结果，
所以，可以在n之前看看有多少个2以及多少个5就行了，
又发现2的数量一定多于5的个数，于是我们只看n前面有多少个5就行了，
于是n/5就得到了5的个数，还有一点要注意的就是25这种，5和5相乘的结果，
所以，还要看n/5里面有多少个5，也就相当于看n里面有多少个25，还有125，625.。。

*/

class Solution {
public:
    int trailingZeroes(int n) {
      int res=0;
      while(n)
      {
          res=res+n/5;
          n=n/5;
      }
      return res;
    }
};
int main()
{
    int n;
    cin>>n;

    cout << "Hello world!" << endl;
    return main();
}
