/*
all right preserved by dc
note: 在递归中 注意加& 会记录所有访问过的值
不加应用记录的是当前栈中记录的数据
可以用bool变量控制递归的分支数 剪枝操作
处理函数的返回值 记得可以把整个函数返回
class Solution {
public:

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root==NULL||p==NULL || q==NULL)  return NULL;
	    if (root==p||root==q) return root;
	    switch ((p->val>root->val) + (q->val>root->val))
	    {
	       case 0: return lowestCommonAncestor(root->left,p,q);
	       case 1: return root;
	       case 2: return lowestCommonAncestor(root->right,p,q);
	    }

	}


};
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void CreateBiTree(TreeNode *&root)
	{
		int ch;
		cin>>ch;
		if (ch!=-1)
		{
			root=new TreeNode(ch);
			CreateBiTree(root->left);
			CreateBiTree(root->right);
		}


	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root==NULL)  return root;
		vector<TreeNode*> pPath;
		vector<TreeNode*> qPath;
		vector<TreeNode*> vec;
		GetTreeNodePath(root,p,vec,pPath);
		GetTreeNodePath(root,q,vec,qPath);
		TreeNode *commonAncestor=GetCommomAncestor(pPath,qPath);
		return commonAncestor;
	}

	TreeNode* GetCommomAncestor(vector<TreeNode*> pPath,vector<TreeNode*> qPath)
	{
		int pLen=pPath.size();
		int qLen=qPath.size();
		if (pLen==0||qLen==0) return NULL;

		for(int i=0,j=0; i<pLen&&j<qLen; i++,j++)
		{
			if (pPath[i]==qPath[j])
			{
				return pPath[i];
			}

		}
		return NULL;

	}

	void GetTreeNodePath(TreeNode* root,  TreeNode* p,  vector<TreeNode*> vec, vector<TreeNode*> &path){
		if (root==NULL)return ;

		vec.push_back(root);
		if (root->val==p->val)
		{
			path=vec;
			return;
		}

		TreeNode *left=root->left;
		if (left!=NULL)
		{
			GetTreeNodePath(left,p,vec,path);
		}

		TreeNode *right=root->right;
		if (right!=NULL)
		{
			GetTreeNodePath(right,p,vec,path);
		}

	}
};
int main()
{
	Solution s;
	TreeNode *root;
	//s.CreateBiTree(root);
	//TreeNode *p=new TreeNode(3);
	//TreeNode *q=new TreeNode(7);
	//s.lowestCommonAncestor(root,p,q);
	cout<<(1>2)+(1>3);

	return 0;
}

