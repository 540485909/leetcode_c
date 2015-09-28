#include <iostream>
#include <queue>
using namespace std;
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution {
public:
    void connect(TreeLinkNode *root) {

        if(root==NULL)return ;

        if(root->left)
        {
            if(root->right)root->left->next=root->right;
			else if(root->next){
             if(root->next->left)root->left->next=root->next->left;
            if(root->next->right)root->left->next=root->next->right;
			}
            else root->left->next=NULL;

        }

        if(root->right)
        {
            if(root->next){
            if(root->next->left)root->right->next=root->next->left;
            if(root->next->right)root->right->next=root->next->right;
            }
            else root->right->next=NULL;
        }
        connect(root->left);
        connect(root->right);
    }
};
int main()
{
  TreeLinkNode *root=new TreeLinkNode(1);
  TreeLinkNode *left=new TreeLinkNode(2);
  root->left=left;
  Solution s;
  s.connect(root);
    return 0;
}
