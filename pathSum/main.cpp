#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:

    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL)return false;
        if(root->val==sum&&root->left==NULL&&root->right==NULL)return true;
        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);

    }
    void dfs(TreeNode *root,int sum,vector<vector<int> > &result,vector<int> &cur)
    {
        if(root->val==sum&&root->left==NULL&&root->right==NULL)
        {
            result.push_back(cur);
            return ;
        }
        if(root->left)
        {
            cur.push_back(root->left->val);
            dfs(root->left,sum-root->val,result,cur);
            cur.pop_back();
        }
        if(root->right)
        {
            cur.push_back(root->right->val);
            dfs(root->right,sum-root->val,result,cur);
            cur.pop_back();
        }

    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
       vector<vector<int> > result;
       vector<int> cur;
       if(root==NULL)return result;
       cur.push_back(root->val);
       dfs(root,sum,result,cur);

        return result;

    }

};
int main()
{
    Solution s;
    TreeNode *root=new TreeNode(-2);
    TreeNode *right=new TreeNode(-3);
    root->right=right;
    cout<<s.hasPathSum(root,-5)<<endl;
    return 0;
}
