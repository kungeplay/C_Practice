//Binary Tree Inorder Traversal
//Given a binary tree, return the inorder traversal of its nodes' values.
//Note: Recursive solution is trivial, could you do it iteratively?
//递归方法是无聊的，用迭代方法解决
 //借助栈来解决这个问题，进行中序遍历
 // Definition for binary tree
#include <iostream>
#include <vector>
using std::vector;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
    		std::vector<int> v;
        	std::vector<TreeNode *> vtree;
        	InsertVector(root,&vtree);
        	while(vtree.size()>0)
        	{
        		TreeNode *pt=vtree[vtree.size()-1];
        		v.push_back(pt->val);
        		vtree.pop_back();
        		InsertVector(pt->right,&vtree);
        	}
        	return v;

    }
private:    
    void InsertVector(TreeNode *root,std::vector<TreeNode *> *pv)
    {
    		while(root!=NULL)
    		{
    			pv->push_back(root);
    			root=root->left;
    		}
    }

};
int main(int argc, char const *argv[])
{
	Solution s;
	TreeNode *root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	root->right->left=new TreeNode(6);
	std::vector<int> v=s.inorderTraversal(root);
	std::cout<<v.size()<<std::endl;
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
		std::cout<<*i<<" ";		
	}
	std::cout<<std::endl;
	return 0;
}