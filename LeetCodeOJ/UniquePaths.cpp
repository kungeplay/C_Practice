// Unique Paths
// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right 
//corner of the grid (marked 'Finish' in the diagram below).
// How many possible unique paths are there?
// Note: m and n will be at most 100.
#include <iostream>
using namespace std;
// 动态规划，定义一个二维数组 A[M][N]，从左上开始依次计算每一行的值，最后返回 A[M-1][N-1]即可，递推方程是：
// A[I][J]=A[I-1][J]+A[I][J-1]；
// 还可以继续优化，用一个长度为 n 的一维数组即可，数组元素初始值都设为1，递推方程为：
// A[J] += A[J-1]；
// 也就是从第二行开始更新数组值，每次都存储当前行中当前列的值，经过递增行数到最后一行计算完成后，返回 A[N-1]即可。
//这种类型的题我不会，要再看一看
////从左上角走到右下角，每次只能向下或者向右走一步，不管怎么走都需要m+n-2步才能走到，而这其中有m-1步是向下走，
//有n-1是向右走，只用从这m+n-2个位置中选择m-1个位置，则剩余的位置表示向右走。容易求得值是Cm-1m+n-2,利用杨辉三角即可。
class Solution {
public:
    int uniquePaths(int m, int n) {
    		int f[m][n];
    		for(int i=0;i<m;++i)
    		{
    			for(int j=0;j<n;++j)
    			{
    				if(i==0&&j==0)
    					f[i][j]=1;
    				else if(i==0&&j!=0)
    					f[i][j]=f[i][j-1];
    				else if(i!=0&&j==0)
    					f[i][j]=f[i-1][j];
    				else
    					f[i][j]=f[i-1][j]+f[i][j-1];
    			}
    		}
    		return f[m-1][n-1];
    	}
};
int main(int argc, char const *argv[])
{
	Solution so;
	cout<<so.uniquePaths(3,3)<<endl;
	return 0;
}
