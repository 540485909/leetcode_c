#include <iostream>
#include <stack>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class BSTIterator {
public:
    stack<TreeNode*> stk;
    BSTIterator(TreeNode *root) {
        if(root!=NULL)
        pushLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
       TreeNode* top=stk.top();
       stk.pop();
       pushLeft(top->right);
       return top->val;
    }
    void pushLeft(TreeNode *root)
    {

        while(root)
        {
            stk.push(root);
            root=root->left;
        }


    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
