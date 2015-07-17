// Path Sum
// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
// For example:
// Given the below binary tree and sum = 22,
/***
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
**/

#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//注意当本节点是叶子节点才判断和，否则节点为空时返回false
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
    		if(root==NULL)
    			return false;
    		int target=0;
    		return visitBinaryTree(root,target,sum);
    }
    bool visitBinaryTree(TreeNode *root,int target,const int& sum)
    {

    		if(root->left==NULL&&root->right==NULL)
    		{
    			if(target==sum)
    				return true;
    			else
    				return false;
    		}

    		target+=root->val;
 
		if(root->left!=NULL&&visitBinaryTree(root->left,target,sum))
			return true;
		if(root->right!=NULL&&visitBinaryTree(root->right,target,sum))
			return true;
		return false;
    }
};
int main(int argc, char const *argv[])
{
	TreeNode * thead=new	TreeNode(5);
	thead->left=new TreeNode(4);
	thead->right=new TreeNode(8);
	thead->left->left=new TreeNode(11);
	thead->right->left=new TreeNode(13);
	thead->right->right=new TreeNode(4);
	thead->left->left->left=new TreeNode(7);
	thead->left->left->right=new TreeNode(2);
	thead->right->right->right=new TreeNode(1);
	Solution so;

	cout<<so.hasPathSum(thead,23)<<endl;
	return 0;
}