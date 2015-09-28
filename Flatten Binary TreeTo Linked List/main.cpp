#include <iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    TreeNode* findLeftRight(TreeNode *root,bool &flag)
    {
        if(root->left==NULL){flag=true;return root ;}
        root=root->left;
        while(root->right)
        {

            root=root->right;
        }
        return root;
    }
    void flatten(TreeNode *root) {
      if(root==NULL)return ;
      bool flag=false;
      TreeNode* last=findLeftRight(root,flag);
      if(!flag)
      {
          last->right=root->right;
          root->right=root->left;
          root->left=NULL;
      }
      flatten(root->right);
    }
};
int main()
{

    cout << "Hello world!" << endl;
    return 0;
}
