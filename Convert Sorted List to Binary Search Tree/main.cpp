#include <iostream>
#include <vector>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
/*As usual, the best solution requires you to think from another perspective.
In other words, we no longer create nodes in the tree using the top-down approach.
We create nodes bottom-up, and assign them to its parents. The bottom-up approach
enables us to access the list in its order while creating nodes.However, you should
prefer top-down instead of bottom-up in general, since the latter is more
difficult to verify in correctness.*/
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *&head,int start,int tail){
        if(start>tail)return NULL;
        int mid=start+(tail-start)/2;
        TreeNode *leftChild=sortedListToBST(head,start,mid-1);
        TreeNode *root=new TreeNode(head->val);
        root->left=leftChild;
        head=head->next;
        TreeNode *rightChild=sortedListToBST(head,mid+1,tail);
        root->right=rightChild;
        return root;

    }
    TreeNode *sortedArrayToBST(vector<int> &num,int start,int tail) {
        if(start>tail)return NULL;
        int mid=start+(tail-start)/2;
        TreeNode *root=new TreeNode(num[mid]);
        TreeNode *leftChild=sortedArrayToBST(num,start,mid-1);
        root->left=leftChild;
        TreeNode *rightChild=sortedArrayToBST(num,mid+1,tail);
        root->right=rightChild;
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
   TreeNode *root=sortedArrayToBST(num,0,num.size()-1);
   return root;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        ListNode *cou=head;
        int n=0;
        while(cou)
        {
           n++;
           cou=cou->next;
        }
     TreeNode *root=sortedListToBST(head,0,n-1);
        return root;
    }

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
