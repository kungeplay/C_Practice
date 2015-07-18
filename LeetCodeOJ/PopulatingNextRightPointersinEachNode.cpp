/**
Populating( 居住于； 生活于； 移民于； 落户于 ) Next Right Pointers in Each Node
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

    You may only use constant extra space.
    You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
**/


/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 

 //察，这个题我想出了算法写出后，没写main函数，试一试，竟然直接运行通过了。！
 //常数空间的话，第一可以考虑是不是固定数量的几个变量能搞定；否则可以考虑是不是问题本身已经提供了足够的空间。
 //利用树中那个多余的next指针存放额外信息。这就是占用常量空间的思路。！
class Solution {
public:
    void connect(TreeLinkNode *root) {
    		if(root==NULL)
    			return;

    		if(root->next!=NULL)
    		{
    			if(root->next->right==root)//如果这个节点是父孩子的右节点
    			{
    				if(root->next->next!=NULL)//父节点的next指针不为空，说明此节点不是一行中最后一个节点
	    				root->next=root->next->next->left;//
	    			else
	    				root->next=NULL;//一行中最后一个节点
    			}
    		}

    		if(root->left==NULL)
    			return;
    		root->left->next=root->right;//左孩子的next指针指向右孩子
    		root->right->next=root;//右孩子的指针先指向父节点

    		connect(root->left);
    		connect(root->right);
    }
};
