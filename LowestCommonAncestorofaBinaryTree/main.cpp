#include <iostream>
#include <stack>
#include <vector>
using namespace std;


/*	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if(!root)
            return NULL;
        if(root == p || root == q)
            return root;
        // Check if left contains p or q
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        // Check if right contains p or q
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // if left and right containsp or q the it'sthe LCA
        if(left && right)
            return root;
        return left ? left : right;        
	}*/


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void findPath(TreeNode* root, TreeNode* target, vector<TreeNode*> tempPath, vector<TreeNode*> &path,bool &isFind){

		tempPath.push_back(root);
		if (root == target){
			isFind = true;
			path = tempPath;
			return;
		}

		if (root->left != NULL&&!isFind)
		{
			findPath(root->left, target, tempPath, path,isFind);

		}
		if (root->right != NULL&&!isFind)
		{
			findPath(root->right, target, tempPath, path, isFind);

		}



	}
	TreeNode* findCommonAncestor(vector<TreeNode*>pPath, vector<TreeNode*>qPath){
		int index = 0;
		for (int i = 0; i < pPath.size() && i < qPath.size(); i++){
			if (pPath[i]->val == qPath[i]->val){
				continue;
			}
			else{
				index = i;
				break;
			}
		}
		return pPath[index];


	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL)return NULL;
		if (!p || !q)return root;
		vector<TreeNode*> pPath, qPath;
		vector<TreeNode*> tempPath;
		bool isFind = false;
		findPath(root, p, tempPath, pPath,isFind);
		isFind = false;
		findPath(root, q, tempPath, qPath,isFind);
		return findCommonAncestor(qPath, pPath);
	}
};
int main()
{
	TreeNode *root = new TreeNode(1);
	TreeNode *left = new TreeNode(2);
	
	TreeNode *right = new TreeNode(1);
	TreeNode *leftleft = new TreeNode(6);
	TreeNode *leftright = new TreeNode(2);
	TreeNode *rightleft = new TreeNode(0);
	TreeNode *rightright = new TreeNode(8);
	TreeNode *leftrightleft = new TreeNode(7);
	TreeNode *leftrightright = new TreeNode(4);
	root->left = left;
	root->right = right;
	left->left = leftleft;
	left->right = leftright;
	right->left = rightleft;
	right->right = rightright;
	leftright->left = leftrightleft;
	leftright->right = leftrightright;
	Solution s;
	TreeNode *common=s.lowestCommonAncestor(root, leftleft,leftrightleft);
	cout << common->val << endl;
	return 0;
}


