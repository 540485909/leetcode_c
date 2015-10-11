#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root || !root->left && !root->right) return true;
        TreeNode *t1 = root->left, *t2 = root->right;
        if (t1&&!t2 || !t1&&t2 || t1->val!=t2->val) return false;

        stack<TreeNode *> s1, s2;
        s1.push(t1), s2.push(t2);
        bool flag=false;
        while(!s1.empty()&&!s2.empty())
        {
            if(!flag&&(t1->left||t2->right))
            {

                s1.push(t1), s2.push(t2);
                t1 = t1->left, t2 = t2->right;
                if (t1&&!t2 || !t1&&t2 || t1->val!=t2->val) return false;
                s1.push(t1), s2.push(t2);
            }
            else if(t1->right||t2->left)
            {
                t1 = t1->right, t2 = t2->left;
                if (t1&&!t2 || !t1&&t2 || t1->val!=t2->val) return false;
                flag = false;

            }
            else
                {
                 t1=s1.top();
                 t2=s2.top();
                 s1.pop();
                 s2.pop();
                 flag=true;

                }
        }
        return s1.empty()&&s2.empty();

    }
};
int main()
{

    return 0;
}
