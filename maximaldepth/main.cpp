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
    int minDepth(TreeNode *root) {
        if(root==NULL)return 0;
        int a=minDepth(root->left);
        int b=minDepth(root->right);
        if(a*b!=0)return 1+min(a,b);
        if(a==0)return b+1;
        if(b==0)return a+1;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
