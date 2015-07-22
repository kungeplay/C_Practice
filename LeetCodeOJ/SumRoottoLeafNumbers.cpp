/**
Sum Root to Leaf Numbers
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
//这题不难
class Solution {
public:
    int sumNumbers(TreeNode* root) {
    		sum=0;
    		if(root==NULL)
    			return sum;
    		VisitBinaryRoot(root,0);
    		return sum;
    }
private:
	int sum;
private:
	void VisitBinaryRoot(TreeNode *root,int currentSum)
	{
		currentSum*=10;
		currentSum+=root->val;
		if(root->left==NULL&&root->right==NULL)
		{
			sum+=currentSum;
			return;
		}
		if(root->left!=NULL)
			VisitBinaryRoot(root->left,currentSum);
		if(root->right!=NULL)
			VisitBinaryRoot(root->right,currentSum);

	}
};
int main(int argc, char const *argv[])
{
	TreeNode *root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	Solution so;
	cout<<so.sumNumbers(root)<<endl;
	return 0;
}