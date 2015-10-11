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
    vector<TreeNode *> createTree(int left,int right)
    {
        if(left>right)return vector<TreeNode *>(1,nullptr);
        vector<TreeNode *> rs;

        int k;
        for( k=left;k<=right;k++)
        {
            vector<TreeNode *> lt=createTree(left,k-1);
            vector<TreeNode *> rt=createTree(k+1,right);

        for(int i=0;i<lt.size();i++)
        {
            for(int j=0;j<rt.size();j++)
            {
                TreeNode *root=new TreeNode(k);
                root->left=it[i];
                root->right=it[j];
                rs.push_back(root);
            }
        }
        }
        return rs;

    }
    vector<TreeNode *> generateTrees(int n) {
  return createTree(1,n);
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
