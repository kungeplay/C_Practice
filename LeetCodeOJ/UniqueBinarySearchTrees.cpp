//Unique Binary Search Trees
//Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//思路是通过寻找规律，以根节点为界，左子树小于根节点，右子树大于根节点
#include<iostream>
#include<vector>
class Solution {
public:
    int numTrees(int n) {
    	//下面是我第一次使用递归调用，发现用的时间过大
    //     if (n==0||n==1)
    //     {
    //     	return 1;
    //     }
    //     else if(n==2)
    //     {
    //     	return 2;
    //     }
    //     else
    //     {
    //     	int sum=0;
    //     	for (int i = 0,j=n-1; i < n,j>-1; ++i,--j)
    //     	{
    //     		sum+=numTrees(i)*numTrees(j);
    //     	}
    //     	return sum;
    //     }
		//下面是我用循环迭代，类似于动态规划方法，保留每次的值，因为下一次要用
	    	std::vector<int> v(n+1);
	    	v[0]=1;
	    	v[1]=1;
	    	v[2]=2;
	    	for (int i = 3; i < n+1; ++i)
	    	{
	    		for (int m =0 ,j=i-1; m <i,j>-1; ++m,--j)
	    		{
	    			v[i]+=v[m]*v[j];
	    		}
	    	}
	    	return v[n];
   	}
};
int main(int argc, char const *argv[])
{
	Solution s;
	std::cout<<s.numTrees(5)<<std::endl;
	return 0;
}