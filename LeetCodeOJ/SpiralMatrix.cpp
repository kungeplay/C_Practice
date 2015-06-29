// Spiral( 螺旋形的； 盘旋的； 盘旋上升的 ) Matrix
// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

// For example,
// Given the following matrix:

// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]

// You should return [1,2,3,6,9,8,7,4,5]. 

#include <iostream>
#include <vector>

using namespace std;
//剑指offer里也有这个题，我感觉我这个更好理解，哈哈
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {    	
    		vector<int> spiral_v;
    		if(matrix.size()==0)
    			return spiral_v;
		size_t m=matrix.size();//矩阵行
		size_t n=matrix[0].size();//矩阵列
		for(size_t start=0;2*start<=(m-1)&&2*start<=(n-1);++start)
		{
			if(2*start==(m-1)&&2*start==(n-1))//只有/还剩一行一列时
				spiral_v.push_back(matrix[start][start]);
			else if(2*start==(m-1))//只有/还剩一行时
			{
				for(size_t c=start;c<=n-1-start;++c)
					spiral_v.push_back(matrix[start][c]);
			}
			else if(2*start==(n-1))//只有/还剩一列时
			{
				for(size_t r=start;r<=m-1-start;++r)
					spiral_v.push_back(matrix[r][start]);
			}
			else
			{
				for(size_t c=start;c<n-1-start;++c)
					spiral_v.push_back(matrix[start][c]);
				for(size_t r=start;r<m-1-start;++r)
					spiral_v.push_back(matrix[r][n-1-start]);
				for(size_t c=n-1-start;c>start;--c)
					spiral_v.push_back(matrix[m-1-start][c]);
				for(size_t r=m-1-start;r>start;--r)
					spiral_v.push_back(matrix[r][start]);
			}
		}
		return spiral_v;
    }
};
int main(int argc, char const *argv[])
{
	vector<vector<int>> matrix={{1},{2},{3}};
	Solution so;
	vector<int> spiral_v=so.spiralOrder(matrix);
	for(size_t i=0;i<spiral_v.size();++i)
	{
		cout<<spiral_v[i]<<'\t';
	}
	cout<<endl;
	return 0;
}
