#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {

      vector<vector<int> > ret;
      if(root == NULL) return ret;

        vector<int> vec;
        queue<TreeNode *> Q;
        queue<TreeNode *> Q2;   // extra space
      Q.push(root);


      while(!Q.empty())
      {
          TreeNode *temp=Q.front();
          Q.pop();
          if(temp)
          {

          vec.push_back(temp->val);
          if(temp->left)
          {
              Q2.push(temp->left);

          }
          if(temp->right)
          {
              Q2.push(temp->right);

          }
          }
          if(Q.empty())
          {
              ret.push_back(vec);
              vec.clear();
              swap(Q,Q2);

          }
      }
      reverse(ret.begin(),ret.end());
      return ret;

    }
      vector<vector<int> > levelOrderBottom(TreeNode *root) {
          vector<vector<int> > ret;
          vector<int> val;
          queue<TreeNode*> Q;
          if(root==NULL)return ret;
          Q.push(root);
          int c=1;
          while(!Q.empty())
          {
              int nextC=0;
              for(int i=0;i<c;i++)
              {
                  TreeNode* temp=Q.front();
                  Q.pop();
                  if(temp)
                  {
                      val.push_back(temp->val);
                      if(temp->left)
                      {
                          Q.push(temp->left);
                          nextC++;
                      }
                      if(temp->right)
                      {
                          Q.push(temp->right);
                          nextC++;
                      }
                  }
              }
              ret.push_back(val);
              val.clear();
              c=nextC;
          }
          reverse(ret.begin(),ret.end());
          return ret;
      }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
