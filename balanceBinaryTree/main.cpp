#include <iostream>
#include <cmath>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    int depth(TreeNode *root)
    {
        if(root==NULL)return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
    bool isBalanced(TreeNode *root) {
        if(root==NULL)return true;
        int left=depth(root->left);
        int right=depth(root->right);
        int differ=left-right;
        if(abs(differ)>1)return false;
        else return isBalanced(root->left)&&isBalanced(root->right);


    }
};
int main()
{

    return 0;
}
