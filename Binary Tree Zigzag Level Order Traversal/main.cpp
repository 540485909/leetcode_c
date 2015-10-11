#include <iostream>
#include <vector>
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        queue<TreeNode*> q1;
        vector<vector<int> >result;
        vector<int> curRes;
        enum Dir{L,R};
        Dir dir=L;
        if(root==NULL)return result;
        TreeNode* p=root;
        if(!p)q1.push(p);
        while(!q1.empty())
        {
             queue<TreeNode*> q2;
            while(!q1.empty())
            {
                TreeNode *temp=q1.front();
                q1.pop();
                if(temp->left)q2.push(temp->left);
                if(temp->right)q2.push(temp->right);
                curRes.push_back(temp->val);
            }
            if(dir==R)
            {
                reverse(curRes.begin(),curRes.end());
                dir=L;
            }
            else
            {

                dir=R;
            }
            result.push_back(curRes);
            curRes.clear();
            q1=q2;


        }
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
