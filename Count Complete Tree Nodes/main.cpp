#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int value) :val(value), left(NULL), right(NULL){}
};
class Solution {
public:
	bool dfs(TreeNode* root, int index, int depth, int &value){
		if (index == depth){
			if (root)
			{
				value++;
				return true;
			}
			else{
				return false;
			}
		}
		if (root->left&&dfs(root->left, index + 1, depth, value)){}
		else{ return false; }


		if (root->right&&dfs(root->right, index + 1, depth, value)){}
		else { return false; }

		return true;
	}
	int bfs(TreeNode* root,  int depth){
		queue<TreeNode*> q1, q2;
		TreeNode* p = root;
		int level = 1,value=0;
		q1.push(p);
		while (!q1.empty()){
			level++;
			while (!q1.empty()){
				p = q1.front(); q1.pop();
				if (p->left){
					if (level == depth){
						value++;
					}
					q2.push(p->left);
				}
				if (p->right){
					if (level == depth){
						value++;
					}
					q2.push(p->right);
				}
			}
			swap(q1, q2);

		}
		return value;
	}
	int getDepth(TreeNode *root){
		if (root == NULL) return 0;
		int c = 0;
		while (root){
			root = root->left;
			c++;
		}
		return c;
	}
	int countNodes(TreeNode* root) {
		if (root == NULL) return 0;
		int leftDepth = getDepth(root->left);
		int rightDepth = getDepth(root->right);
		if (leftDepth == rightDepth){
			return pow(2, leftDepth) + countNodes(root->right);
		}
		else{
			return pow(2, rightDepth) + countNodes(root->left);
		}
	}
};
int main()
{
	TreeNode *root = new TreeNode(1);
	TreeNode *left = new TreeNode(2);
	TreeNode *right = new TreeNode(3);
	TreeNode *leftleft = new TreeNode(4);
	root->left = left;
	root->right = right;
	left->left = leftleft;
	Solution s;
	cout<<s.countNodes(root);
	return 0;
}
