#include <iostream>

using namespace std;
/*

ֻ��2��5��˲Ż����0��������ʮҲ���Կ�����2��5��˵Ľ����
���ԣ�������n֮ǰ�����ж��ٸ�2�Լ����ٸ�5�����ˣ�
�ַ���2������һ������5�ĸ�������������ֻ��nǰ���ж��ٸ�5�����ˣ�
����n/5�͵õ���5�ĸ���������һ��Ҫע��ľ���25���֣�5��5��˵Ľ����
���ԣ���Ҫ��n/5�����ж��ٸ�5��Ҳ���൱�ڿ�n�����ж��ٸ�25������125��625.����

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