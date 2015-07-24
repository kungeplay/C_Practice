/*
Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:

    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points(奖金，额外津贴; 红利，额外股息) if you could solve it both recursively(递归地) and iteratively(迭代的). 
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
//实习生招聘时，看了好长时间这个题，感觉好难，现在这个时候感觉一点也不难，是进步么 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    		if(root==NULL)
    			return true;
    		return isSymmetric(root->left,root->right);
    }
private:
	bool isSymmetric(TreeNode *leftChild,TreeNode * rightChild)
	{
		if(leftChild==NULL&&rightChild==NULL)
			return true;
		else if(leftChild!=NULL&&rightChild!=NULL&&leftChild->val==rightChild->val)
		{
			if(isSymmetric(leftChild->left,rightChild->right)&&isSymmetric(leftChild->right,rightChild->left))
				return true;
			else
				return false;
		}
		else
			return false;
	}
};

int main(int argc, char const *argv[])
{

	TreeNode * root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(2);
	root->left->left=new TreeNode(3);
	root->left->right=new TreeNode(4);
	root->right->left=new TreeNode(4);
	root->right->right=new TreeNode(3);
	Solution so;
	cout<<so.isSymmetric(root)<<endl;
	return 0;
}