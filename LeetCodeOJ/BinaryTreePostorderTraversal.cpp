/*
Binary Tree Postorder Traversal
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
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

 //迭代后根遍历二叉树，和上一个迭代先根遍历二叉树相比的主要难点在于要记住是否是第一次走到此节点，若是第一次，则应把其左右孩子加入到栈中，
 //否则，则可以访问其值。所以这里用了两个栈。
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> visitPost;
		if(root==NULL)
			return visitPost;
		stack<TreeNode *> nodes;
		stack<TreeNode *> status;//判断是否是第一次访问此节点
		nodes.push(root);
		while(!nodes.empty())
		{
			TreeNode * p=nodes.top();
			if(!status.empty()&&status.top()==p)
			{
				nodes.pop();
				status.pop();
				visitPost.push_back(p->val);
			}
			else
			{
				status.push(p);
				if(p->right!=NULL)
					nodes.push(p->right);
				if(p->left!=NULL)
					nodes.push(p->left);
			}
		}
		return visitPost;
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
	vector<int> visitPost=so.postorderTraversal(root);

	for(auto iter : visitPost)
	{
		cout<<iter<<'\t';
	}
	cout<<endl;	
	return 0;
}