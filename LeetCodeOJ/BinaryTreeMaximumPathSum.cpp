/*
Binary Tree Maximum Path Sum
Given a binary tree, find the maximum path sum.
The path may start and end at any node in the tree.
For example:
Given the below binary tree,

       1
      / \
     2   3

Return 6. 
*/

#include <iostream>
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

 //不算难，注意题中说的是从任意节点开始，到任意节点结束的最大路径和，想了一会用递归。深度优先遍历
class Solution {
public:
    int maxPathSum(TreeNode* root) {
    		if(root==NULL)
    			return 0;
    		maxSum=0;
    		isFirst=true;
    		pathSum(root);
    		return maxSum;
    }
private:
	int maxSum;//保存路径最大和
	bool isFirst;//判断是否第一次求值
private:
	int pathSum(TreeNode *root)
	{
		int leftSum=0;
		int rightSum=0;
		int curSum=0;
		int curMaxPath=0;
		if(root->left==NULL&&root->right==NULL)
		{

			curSum=root->val;
			curMaxPath=curSum;
		}
		else if(root->left!=NULL&&root->right==NULL)
		{
			leftSum=pathSum(root->left);
			if(leftSum<=0)
			{
				curSum=root->val;

			}
			else
			{
				curSum=root->val+leftSum;
			}
			curMaxPath=curSum;
		}
		else if(root->left==NULL&&root->right!=NULL)
		{
			rightSum=pathSum(root->right);
			if(rightSum<=0)
			{
				curSum=root->val;
			}
			else
			{
				curSum=root->val+rightSum;
			}
			curMaxPath=curSum;
		}
		else
		{
			leftSum=pathSum(root->left);
			rightSum=pathSum(root->right);
			curSum+=root->val;
			if(leftSum>0)
				curSum+=leftSum;
			if(rightSum>0)
				curSum+=rightSum;
			int childPath=leftSum>rightSum?leftSum:rightSum;
			if(childPath>0)
				curMaxPath+=childPath;
			curMaxPath+=root->val;
		}
		if(isFirst)
		{
			maxSum=curSum;
			isFirst=false;
		}
		else if(maxSum<curSum)
			maxSum=curSum;
		return curMaxPath;
	}
};

int main(int argc, char const *argv[])
{
	TreeNode *root=new TreeNode(-1);
	root->left=new TreeNode(2);
	root->left->left=new TreeNode(-5);
	root->right=new TreeNode(-3);
	Solution so;
	cout<<so.maxPathSum(root)<<endl;
	return 0;
}