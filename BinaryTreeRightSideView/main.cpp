#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void bfs(TreeNode* root,vector<int> &val){
		queue<TreeNode*> q1;
		queue<TreeNode*> q2;
		TreeNode* p=root;
		if(root!=NULL)
		{
			q1.push(p);
			val.push_back(p->val);
		}
		while(!q1.empty()||!q2.empty()){
			TreeNode *temp=q1.front();
			q1.pop();
			TreeNode* left=temp->left;
			TreeNode* right=temp->right;
			if(left!=NULL){
				q2.push(left);
			}
			if(right!=NULL){

				q2.push(right);;

			}
			if(q1.empty()){
				q1=q2;
				TreeNode *lastNode=NULL;
				while(!q2.empty()){
					lastNode=q2.front();
					q2.pop();
				}
				if(lastNode!=NULL)
					val.push_back(lastNode->val);

			}

		}

	}
	void dfs(TreeNode* root,vector<int> &val){
		val.push_back(root->val);
		TreeNode *right=root->right;
		TreeNode *left=root->left;
		if(right!=NULL){
			dfs(right,val);
		}else if(left!=NULL){
			dfs(left,val);
		}
	}
	vector<int> rightSideView(TreeNode* root) {
		vector<int> val;
		if(root==NULL) return val;
		bfs(root,val);
		return val;
	}

};
int main()
{
	TreeNode *root=new TreeNode(1);
	TreeNode *left=new TreeNode(2);
	TreeNode *right=new TreeNode(3);
	TreeNode *rightright=new TreeNode(4);
	TreeNode *leftRight=new TreeNode(5);
	root->left=left;
	root->right=right;
	left->right=leftRight;
	right->right=rightright;
	Solution s;
	vector<int> result;
	result=s.rightSideView(root);
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<endl;
	}
}
