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
    /* TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder,int s1,int e1,int s2,int e2) {
        if(s1>e1||s2>e2)return NULL;
        if(s1==e1)return new TreeNode(preorder[s1]);
        TreeNode *root=new TreeNode(preorder[s1]);
        int i;
        for( i=s2;i<=e2;i++)
        {
            if(preorder[s1]==inorder[i])break;
        }
        int leftlength = i - s2;
        int rightlength = e2 - i;
        root->left=buildTree(preorder,inorder,s1+1,s1+leftlength,s2,i-1);
        root->right=buildTree(preorder,inorder,s1 + leftlength + 1, e1, i + 1, e2);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
         if(inorder.size()==0 || preorder.size()==0 || inorder.size() != preorder.size())
            return NULL;
     return buildTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }*/
       TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder,int s1,int e1,int s2,int e2) {
        if(s1>e1||s2>e2)return NULL;
        if(s1==e1)return new TreeNode(preorder[e1]);
        TreeNode *root=new TreeNode(preorder[e1]);
        int i;
        for( i=s2;i<=e2;i++)
        {
            if(preorder[s1]==inorder[i])break;
        }
        int leftlength = i - s2;
        int rightlength = e2 - i;
        root->left=buildTree(preorder,inorder,s1,s1+leftlength-1,s2,i-1);
        root->right=buildTree(preorder,inorder,e1-rightlength , e1-1, i + 1, e2);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
         if(inorder.size()==0 || preorder.size()==0 || inorder.size() != preorder.size())
            return NULL;
     return buildTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
