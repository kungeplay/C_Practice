// Set Matrix Zeroes
// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
// Follow up:
// Did you use extra space?
// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

#include <iostream>
#include <vector>
using namespace std;

// //没有想到常量空间的方法，只是想到了占用m+n空间的方法
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//     		int i=0,j=0;
//     		int rownum=matrix.size();
//     		if(rownum==0)
//     			return ;
//     		int columnnum=matrix[0].size();
//     		vector<int> zeroposit(rownum+columnnum,1);
//     		for(i=0;i<rownum;++i)
//     		{	
//     			for(j=0;j<columnnum;++j)
//     			{
//     				if(matrix[i][j]==0)
//     				{
//     					zeroposit[i]=0;
//     					zeroposit[rownum+j]=0;
//     				}

//     			}
//     		}
// 		for(int m=0;m<rownum;++m)
// 		{
// 			if(zeroposit[m]==0)
// 			{
// 				for(int n=0;n<columnnum;++n)
// 					matrix[m][n]=0;
// 			}
// 		}
// 		for(int n=0;n<columnnum;++n)
// 		{
// 			if(zeroposit[rownum+n]==0)
// 			{
// 				for(int m=0;m<rownum;++m)
// 				{
// 					matrix[m][n]=0;
// 				}
// 			}
// 		}
//     }
// };
//在网上找到的常数空间的算法:
// 常数空间的话，第一可以考虑是不是固定数量的几个变量能搞定；否则可以考虑是不是问题本身已经提供了足够的空间。
// 这道题属于后者，就是利用矩阵的第一行和第一列来作为辅助空间使用。不用开辟新的存储空间。方法就是：
// 1.先确定第一行和第一列是否需要清零
// 即，看看第一行中是否有0，记下来。也同时记下来第一列中有没有0。
// 2.扫描剩下的矩阵元素，如果遇到了0，就将对应的第一行和第一列上的元素赋值为0
// 这里不用担心会将本来第一行或第一列的1改成了0，因为这些值最后注定要成为0的，比如matrix[i][j]==0，那么matrix[i][0]处在第i行，matrix[0][j]处于第j列，最后都要设置为0的。
// 3.根据第一行和第一列的信息，已经可以将剩下的矩阵元素赋值为结果所需的值了即，拿第一行为例，如果扫描到一个0，就将这一列都清0.
// 4.根据1中确定的状态，处理第一行和第一列。
// 如果最开始得到的第一行中有0的话，就整行清零。同理对列进行处理。
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    		int rownum=matrix.size();
    		if(rownum==0)
    			return ;
    		int columnnum=matrix[0].size();
    		bool columnzero=false;
    		bool rowzero=false;
    		int i=0,j=0;
    		for(i=0;i<rownum;++i)
    		{
    			if(matrix[i][0]==0)
    				columnzero=true;
    		}
		for(j=0;j<columnnum;++j)
		{
			if(matrix[0][j]==0)
				rowzero=true;
		}

		for(i=1;i<rownum;++i)
		{
			for(j=1;j<columnnum;++j)
			{
				if(matrix[i][j]==0)
				{
					matrix[i][0]=0;
					matrix[0][j]=0;
				}
			}
		}

		for(i=1;i<rownum;++i)
		{
			if(matrix[i][0]==0)
			{
				for(j=1;j<columnnum;++j)
					matrix[i][j]=0;
			}
		}
		for(j=1;j<columnnum;++j)
		{
			if(matrix[0][j]==0)
			{
				for(i=1;i<rownum;++i)
					matrix[i][j]=0;
			}
		}

		if(rowzero)
		{
			for(j=0;j<columnnum;++j)
				matrix[0][j]=0;
		}
		if(columnzero)
		{
			for(i=0;i<rownum;++i)
				matrix[i][0]=0;
		}
    }
};



int main(int argc, char const *argv[])
{
	vector<vector<int>> matrix;
	vector<int> temp1={-1};
	matrix.push_back(temp1);
	vector<int> temp2={2};
	matrix.push_back(temp2);
	vector<int> temp3={3};
	matrix.push_back(temp3);
	Solution so;
	so.setZeroes(matrix);
	for(size_t i=0;i<matrix.size();++i)
	{
		for(size_t j=0;j<matrix[i].size();++j)
			cout<<matrix[i][j]<<'\t';
		cout<<endl;
	}


	return 0;
}