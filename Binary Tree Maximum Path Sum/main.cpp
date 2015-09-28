#include <iostream>
#include <limits>
using namespace std;
const int inf=1>>30;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:

    int maxPathSum(TreeNode *root) {
        int m=-1000;
        if(root==NULL)return 0;
        int result=maxPathSumHelper(root,m);
        if(m<result)m=result;
        return m;

    }
    int maxPathSumHelper(TreeNode *root,int &m)
    {
        if(root==NULL)return -1000;
        int left=maxPathSumHelper(root->left,m);
        int right=maxPathSumHelper(root->right,m);
        if(m<root->val)m=root->val;
        if(m<left)m=left;
        if(m<right)m=right;
        if(m<(right+left+root->val))m=right+left+root->val;
        return max(root->val,max(left,right)+root->val);
    }
};
int main()
{

}
