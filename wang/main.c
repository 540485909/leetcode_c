#include <iostream>
#include <string>
#include <stack>
using namespace std;
 int atoi(const char *str) {
 assert(str != NULL);
        if (*str == '\0') return 0;

        const char *p = str;
        int minus = 1;

        //skip spaces
        while (*p == ' ') p++;

        //get sign
        if (*p == '-') {
            minus = -1;
            p++;
        } else if (*p == '+') {
            minus = 1;
            p++;
        }

        //convert numbers
        int num = 0;
        while (isdigit(*p)) {
            if ( ((num == 214748364) && (((*p) - '0') > 7)) || (num > 214748364) ) {
                return (minus > 0) ? INT_MAX : INT_MIN;
            }
            num = 10*num + ((*p) - '0');
            p++;
        }

        return (minus > 0) ? num : -num;
    }
int stoi(string s)
{
    int len=s.length();
    int sum=0;
    for(int i=0;i<len;i++)
    {
        sum=10*sum+(s[i]-'0');

    }
    return sum;
}
int cal(int op1,int op2,char opr)
{
    if('+'==opr)return op1+op2;
    else if('-'==opr)return op1-op2;
    else if('*'==opr)return op1*op2;
    else return op1/op2;
}
int evalRPN(vector<string> &tokens)
{
    int len=tokens.size();
    stack<int> s;
    for(int i=0;i<len;i++)
    {
        if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
        {
            int op1=s.top();s.pop();
            int op2=s.top();s.pop();
            int result=cal(op1,op2,tokens[i])
            s.push(result);

        }
        else s.push(stoi(tokens[i]));

    }
}
int main()
{
    int *dynamicArr[]={{1,2,3},{1},{2};
vector<string> sVec;
sVec.push_back("2");
sVec.push_back("1");
sVec.push_back("+");
sVec.push_back("2");
sVec.push_back("*");
cout<<evalRPN(sVec)<<endl;
}
