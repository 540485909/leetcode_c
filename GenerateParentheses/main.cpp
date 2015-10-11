#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n>0)helper(result,"",n,n);
        return result;
    }
    void helper(vector<string>&result,string cur,int left,int right)
    {

       if(left==0&&right==0){
            result.push_back(cur);
            return;

       }
       if(left!=0)helper(result,cur+'(',left-1,right);
       if(right!=0)helper(result,cur+')',left,right-1);







    }
};
int main()
{
    Solution s;
    vector<string> result=s.generateParenthesis(3);

    return 0;
}
