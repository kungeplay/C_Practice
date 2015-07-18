/**
Flatten(变平，使（某物）变平) Binary Tree to Linked List
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
  //这是想到的第一种方法，刚开始理解错了题意，不许要排序，直接把先根遍历的节点重新组合成图中的flatten二叉树即可。
// class Solution {
// public:
//     void flatten(TreeNode* root) {
//     		if(root==NULL)
//     			return;
//     		nodeValue.push_back(root->val);
// 		if(root->left!=NULL)
// 			VisitBinaryTree(root->left);
// 		if(root->right!=NULL)
// 			VisitBinaryTree(root->right);

// 		auto iter=nodeValue.begin();
// 		root->val=*iter;
// 		root->left=NULL;
// 		++iter;
//     		TreeNode *p=root;
//     		for(;iter!=nodeValue.end();++iter)
//     		{
// 			p->right=new TreeNode(*iter);
// 			p=p->right;
//     		}
//     }
// private:
// 	vector<int> nodeValue;
// private:
// 	void VisitBinaryTree(TreeNode *root)
// 	{
// 		nodeValue.push_back(root->val);
// 		if(root->left!=NULL)
// 			VisitBinaryTree(root->left);
// 		if(root->right!=NULL)
// 			VisitBinaryTree(root->right);
// 		delete root;
// 	}
// };


 //第二种算法，真不容易，发现有些算法想来很简单，但写时却是各种繁琐，麻烦，不是很好写。
class Solution {
public:
    void flatten(TreeNode* root) {
    		if(root==NULL)
    			return;
    		flatTree(root);//不能改变root指针指向，因为要返回它。
    }
    TreeNode * flatTree(TreeNode *root)
    {
    		TreeNode * rightChild=root->right;
    		TreeNode *p=root;
    		if(root->left!=NULL)
    		{
    			root->right=root->left;
    			p=flatTree(root->right);
    		}
    		if(rightChild!=NULL)
    		{
    			p->right=rightChild;
    			p=flatTree(p->right);
    		}
    		root->left=NULL;
    		return p;
    }
};



int main(int argc, char const *argv[])
{

	TreeNode *root;
	root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(5);
	root->left->left=new TreeNode(3);
	root->left->right=new TreeNode(4);

	// root->right->left=new TreeNode(4);
	root->right->right=new TreeNode(6);
	Solution so;
	so.flatten(root);
	TreeNode *p=root;
	while(p!=NULL)
	{
		cout<<p->val<<'\t';
		p=p->right;
	}
	return 0;
}