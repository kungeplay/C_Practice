/*
Binary Tree Preorder Traversal
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,2,3].

Note: Recursive(回归的，递归的) solution is trivial, could you do it iteratively(迭代的)?
*/


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//迭代先序遍历二叉树还不算难，用一个栈来实现
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> visitPre;
		if(root==NULL)
			return visitPre;
		stack<TreeNode *> nodes;
		nodes.push(root);
		while(!nodes.empty())
		{
			TreeNode *p=nodes.top();
			nodes.pop();
			visitPre.push_back(p->val);
			if(p->right!=NULL)
				nodes.push(p->right);
			if(p->left!=NULL)
				nodes.push(p->left);
		}
		return visitPre;
	}
};

int main(int argc, char const *argv[])
{
	TreeNode * root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	root->right->left=new TreeNode(6);
	root->right->right=new TreeNode(7);
	Solution so;
	vector<int> visitPre=so.preorderTraversal(root);
	for(auto iter : visitPre)
	{
		cout<<iter<<'\t';
	}
	cout<<endl;
	return 0;
}