/*all right preserved by duanchong
从后面读可以充分利用stack的特性
bug: 123 从后面读取的 应该 增加fold 而不是sum=sum*10+varible;
fold=fold*10 应该紧紧跟着前面 不然fold=1 重置会无效
加减后分开考虑会相当简单很多，放在一起考虑 增加复杂性

*/


#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
public:

    int cal(int num1,int num2,char oper){
        if(oper=='+')
        return num1+num2;
        else if(oper=='-')
            return num1-num2;
        else return 0;
    }
    int calculate(string s) {
        stack<int> stknum;
        stack<char> stkoper;
        int len=s.size();
        int number=0,fold=1;

        for(int i=len-1;i>=0;i--)
        {
            if(s[i]==' ')continue;
            if(s[i]-'0'>=0&&s[i]-'0'<=9){
                number=number+(s[i]-'0')*fold;
                  fold=fold*10;
                if(i==0||s[i-1]-'0'<0||s[i-1]-'0'>9){
                   stknum.push(number);
                   number=0;
                   fold=1;

                }

            }
            else if(s[i]=='+'||s[i]=='-'){
               stkoper.push(s[i]);
            }

            else if(s[i]==')'){
                stkoper.push(s[i]);
            }
            else{
                while(true){
                     char oper=stkoper.top();stkoper.pop();
                     if(oper==')'){
                         break;
                     }
                     int num1=stknum.top();stknum.pop();
                     int num2=stknum.top();stknum.pop();
                     stknum.push(cal(num1,num2,oper));
                }


            }

        }
        while(!stkoper.empty()){
            char oper=stkoper.top();stkoper.pop();
            int num1=stknum.top();stknum.pop();
            int num2=stknum.top();stknum.pop();
            stknum.push(cal(num1,num2,oper));
        }
        return stknum.top();

    }

};



int main()
{
    Solution s;
    cout<<s.calculate("(1+(4+5+2)-3)+(6+8)");
    return 0;
}
