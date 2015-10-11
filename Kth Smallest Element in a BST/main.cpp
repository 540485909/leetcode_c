#include <iostream>
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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode *p=root;
        stack<TreeNode*> stk;
        while(p||!stk.empty()){
           if(p)
           {
               stk.push(p);
               p=p->left;

           }
           else
           {
               p=stk.top();
               stk.pop();
               if(--k==0)
               {
                   return p->val;
               }
               p=p->right;

           }

        }
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
