#include <iostream>
#include <climits>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };



class Solution {
    TreeNode *record;
public:

    bool isValidBST(TreeNode *root) {

        return checkValidBST(root, INT_MIN, INT_MAX);
    }

    bool checkValidBST(TreeNode *root, int min_val, int max_val) {
        if (root == NULL) {
            return true;
        }
        record=root;
        bool valid = false;
        if (root->val >= min_val && root->val <= max_val) {
            valid = checkValidBST(root->left, min_val, root->val - 1);
            if (valid) {
                valid = checkValidBST(root->right, root->val + 1, max_val);
            }
        }

        return valid;
    }

};


int main()
{


}
