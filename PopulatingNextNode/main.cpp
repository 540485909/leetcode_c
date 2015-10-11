#include <iostream>

using namespace std;

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *cur,*head=NULL,*prev=NULL;
        cur=root;
        while(cur!=NULL)
        {
            while(cur!=NULL)
            {
                if(cur->left)
                {
                    if(prev!=NULL)
                    {
                        prev->next=cur->left;
                    }
                    else
                    {
                        head=cur->left;
                    }
                    prev=cur->left;
                }
                if(cur->right)
                {
                    if(prev!=NULL)
                    {
                        prev->next=cur->right;
                    }
                    else{head=cur->right;}
                    prev=cur->right;
                }
                cur=cur->next;
            }
            cur=head;
            prev=NULL;
            head=NULL;
        }
    }
 };
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
