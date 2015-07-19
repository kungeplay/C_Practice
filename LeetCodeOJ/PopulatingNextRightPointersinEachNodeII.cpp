/*
Populating Next Right Pointers in Each Node II
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

    You may only use constant extra space.

For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/
#include <iostream>
using namespace std;

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 //这个题本打算继续按照上一个题Populating Next Right Pointers in Each Node的大致思路，改一改呢，结果发现有bug，改了几次，
//才发现继续用那个题的思路根本行不通，想着是由于深度遍历，根本上行不通，就往广度遍历上想，想到了这个算法，上一个题若用这个思路就更简单了。
class Solution {
public:
    void connect(TreeLinkNode *root) {
    		if(root==NULL)
    			return ;
    		TreeLinkNode *q=root;//下一层的第一个节点
    		TreeLinkNode *p=NULL;//在当前层上遍历    		
    		TreeLinkNode *currentlink=NULL;//用来链接下一层的节点
    		while(q!=NULL)
		{
			p=q;
			q=NULL;
	    		while(p!=NULL)
	    		{
	    			if(p->left!=NULL)
	    			{
	    				if(q==NULL)
	    				{
	    					q=p->left;
	    					currentlink=q;
	    				}
	    				else
	    				{
	    					currentlink->next=p->left;
	    					currentlink=currentlink->next;
	    				}
	    			}
	    			if(p->right!=NULL)
	    			{
	    				if(q==NULL)
	    				{
	    					q=p->right;
	    					currentlink=q;
	    				}
	    				else
	    				{
	    					currentlink->next=p->right;
	    					currentlink=currentlink->next;
	    				}
	    			}
	    			p=p->next;
	    		}
	    		if(currentlink!=NULL)
		    		currentlink->next=NULL;
	    	}
    }
};

int main(int argc, char const *argv[])
{
	TreeLinkNode * root=new TreeLinkNode(2);
	root->left=new TreeLinkNode(1);
	root->right=new TreeLinkNode(3);
	root->left->left=new TreeLinkNode(0);
	root->left->right=new TreeLinkNode(7);
	root->right->left=new TreeLinkNode(9);
	root->right->right=new TreeLinkNode(1);
	root->left->left->left=new TreeLinkNode(2);
	// root->left->left->right=new TreeLinkNode(19);

	root->left->right->left=new TreeLinkNode(1);
	root->left->right->right=new TreeLinkNode(0);
	root->right->right->left=new TreeLinkNode(8);
	root->right->right->right=new TreeLinkNode(8);
	root->left->right->right->left=new TreeLinkNode(7);

	Solution so;
	so.connect(root);

	TreeLinkNode *p=root,*q;
	while(p!=NULL)
	{
		q=p;
		p=NULL;


		while(q!=NULL)
		{
			cout<<q->val<<'\t';
			if(p==NULL)
			{
				if(q->left!=NULL)
					p=q->left;
				else if(q->right!=NULL)
					p=q->right;			
			}
			q=q->next;
		}
		cout<<endl;
	}
	return 0;
}