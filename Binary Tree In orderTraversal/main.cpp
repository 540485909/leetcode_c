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
    void inorder(TreeNode *root,vector<int> &result,stack<TreeNode*> &stk)
    {


          TreeNode *p=root;

        while(!stk.empty()||p)
        {

           if(p){stk.push(p);p=p->left;}
           else
            {
                TreeNode *value=stk.top();
                result.push_back(value->val);
                stk.pop();
                p=value->right;

           }


        }


    }
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> stk;
        if(root==NULL)return result;
        inorder(root,result,stk);
        return result;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
