/**
Path Sum II
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

[
   [5,4,11,2],
   [5,8,4,5]
]
**/

#include <iostream>
#include <vector>

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
//在上个题Path Sum的基础上，这个题比较简单只是用vector记住一下遍历的节点
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    		if(root==NULL)
    			return allPath;

    		vector<int> singlePath;
    		this->sum=sum;
    		visitBinaryTree(root,0,singlePath);
    		return allPath;
    }
private:
	vector<vector<int>> allPath;
	int sum;
private:
	void visitBinaryTree(TreeNode *root,int target,vector<int> &singlePath)
	{
		target+=root->val;
		singlePath.push_back(root->val);
		if(root->left==NULL&&root->right==NULL)
		{
			if(target==sum)
				allPath.push_back(singlePath);
		}
		else
		{
			if(root->left!=NULL)
				visitBinaryTree(root->left,target,singlePath);
			if(root->right!=NULL)
				visitBinaryTree(root->right,target,singlePath);
		}
		singlePath.pop_back();//这样只用一个vector就可以实现了
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
	thead->right->right->left=new TreeNode(5);
	thead->right->right->right=new TreeNode(1);
	Solution so;
	vector<vector<int>> allPath=so.pathSum(thead,22);
	for(auto iter=allPath.begin();iter!=allPath.end();++iter)
	{
		for(auto jiter=iter->begin();jiter!=iter->end();++jiter)
			cout<<*jiter<<'\t';
		cout<<endl;
	}
	return 0;
}