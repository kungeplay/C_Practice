//Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 //这个题看了好长时间，感觉与Unique Binary Search Trees有点类似，后来通过”这道题是求解所有可行的二叉查找树，从Unique Binary Search Trees中我们已经知道，
 //可行的二叉查找树的数量是相应的卡特兰数，不是一个多项式时间的数量级，所以我们要求解所有的树，自然是不能多项式时间内完成的了。算法上还是用求解NP问题的方法来求解，也就是N-Queens中介绍的在循环中调用递归函数求解子问题。思路是每次一次选取一个结点为根，然后递归求解左右子树的所有结果，最后根据左右子树的返回的
 //所有子树，依次选取然后接上（每个左边的子树跟所有右边的子树匹配，而每个右边的子树也要跟所有的左边子树匹配，总共有左右子树数量的乘积种情况），构造好之后作为当前树的结果返回。
#include <iostream>
#include <vector>
using std::vector;
 //Definition for binary tree
 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n==0)
        {
            std::vector<TreeNode *> v;
            TreeNode * tn=NULL;
            v.push_back(tn);
            return v;
        }
        return generateChildTrees(1,n);
    }
 private:   
    std::vector<TreeNode *> generateChildTrees(int numbegin,int numend)
    {
        std::vector<TreeNode *> treevector;
        if (numbegin==numend)
        {
            std::vector<TreeNode *> v;
            v.push_back(new TreeNode(numbegin));
            return v;
        }
        for (int numroot = numbegin; numroot <=numend; ++numroot)
        {
            if (numroot==numbegin)
            {
                std::vector<TreeNode *> v=generateChildTrees(numbegin+1,numend);
                for (std::vector<TreeNode *>::iterator i = v.begin(); i != v.end(); ++i)
                {
                    TreeNode * treenode=new TreeNode(numroot);
                    treenode->right=*i;
                    treevector.push_back(treenode);
                }           
            }
            else if(numroot<numend)
            {
                std::vector<TreeNode *> v1=generateChildTrees(numbegin,numroot-1);
                std::vector<TreeNode*> v2=generateChildTrees(numroot+1,numend);
                for (std::vector<TreeNode *>::iterator i = v1.begin(); i != v1.end(); ++i)
                {

                    for (std::vector<TreeNode *>::iterator j = v2.begin(); j != v2.end(); ++j)
                    {
                        TreeNode * treenode=new TreeNode(numroot);
                        treenode->left=*i;
                        treenode->right=*j;
                        treevector.push_back(treenode);
                    }
                }  
            }
            else
            {
                 std::vector<TreeNode *> v=generateChildTrees(numbegin,numend-1);
                 for (std::vector<TreeNode *>::iterator i = v.begin(); i != v.end(); ++i)
                 {
                    TreeNode * treenode=new TreeNode(numroot);
                    treenode->left=*i;
                    treevector.push_back(treenode);                                                
                }
            }


        }
        return treevector;
    }
};
int main(int argc, char const *argv[])
{
	Solution s;
    std::vector<TreeNode *> v=s.generateTrees(10);
    std::cout<<v.size()<<std::endl;
	return 0;
}