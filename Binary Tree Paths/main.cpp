#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}

};
class Solution{
public :
    vector<string> binaryTreePaths(TreeNode* root){
      vector<vector<int> > result;
      vector<int> vec;
      vector<string> finalResult;
      if (root==NULL) return finalResult;
      bfs(result,vec,root);
      vec.clear();
      for( int i=0;i<result.size();i++){
            string tempStr;
            int j=0;
        for(;j<result[i].size()-1;j++){


           tempStr+=to_string(result[i][j]);
           tempStr+="->";
        }

        tempStr+=to_string(result[i][j]);
        finalResult.push_back(tempStr);
        tempStr.clear();
      }
      return finalResult;

    }
    void bfs(vector<vector<int> > &result,vector<int> vec,TreeNode *root){
         TreeNode *left=root->left;
         TreeNode *right=root->right;
         vec.push_back(root->val);

         if (left==NULL&&right==NULL){
            result.push_back(vec);
            vec.clear();
         }
         if(left!=NULL){
            bfs(result,vec,left);
         }
         if(right!=NULL){
            bfs(result,vec,right);
         }

    }



};
int main()
{
    Solution s;
    TreeNode *root=new TreeNode(1);
    TreeNode *left=new TreeNode(2);
    TreeNode *right=new TreeNode(3);
    TreeNode *leftRight=new TreeNode(5);
    root->left=left;
    root->right=right;
    left->right=leftRight;
    vector<string> result=s.binaryTreePaths(root);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"  ";
    }
    return 0;
}
