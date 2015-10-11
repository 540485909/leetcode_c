#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> re;
        stack <TreeNode*> stk;
        if(root==NULL)return re;
        bool lflag=false;
        bool rflag=false;
        stk.push(root);
        while(!stk.empty())
        {
            while(lflag==false&&stk.top()->left)stk.push(stk.top()->left);
            if(rflag==false&&stk.top()->right)
            {
                stk.push(stk.top()->right);
                lflag=false;
            }
            else
            {
                TreeNode *t=stk.top();
                stk.pop();
                re.push_back(t->val);
                lflag=true;
                if(!stk.empty() && stk.top()->right==t)rflag=true;
                else rflag=false;
            }
        }

        return re;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
