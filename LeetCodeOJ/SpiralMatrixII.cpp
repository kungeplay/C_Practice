// Spiral(螺旋形的; 盘旋的; 盘旋上升的) Matrix II
// Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

// For example,
// Given n = 3,
// You should return the following matrix:

// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]
#include <iostream>
#include <vector>
using namespace std;
//察，这个题我感觉就是纯粹静下心来找规律，一个方框，一个方框的计算
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    		vector<vector<int>> SquaMatrix;
		if(n==0)
			return SquaMatrix;
		for(int i=0;i<n;++i)
		{
			vector<int> temp;
			SquaMatrix.push_back(temp);
		}
		getMatrix(SquaMatrix,0,n);
		return SquaMatrix;
	}
private:
	void getMatrix(vector<vector<int>> & SquaMatrix,int start,int n)
	{
		if(2*start>=n)
			return;
		else if(start==n-1-start)
			SquaMatrix[start].push_back(n*n);
		else
		{
			for(int i=start;i<=n-1-start;++i)//当前方框的第一行
			{
				if(i==0)
					SquaMatrix[start].push_back(1);
				else
				{
					SquaMatrix[start].push_back(SquaMatrix[start][i-1]+1);
				}
			}
			int a1=SquaMatrix[start][start]+(n-2*start)*4-4-1;
			for(int j=start+1;j<=n-1-start;++j)//当前方框的第一列
			{
				if(j==start+1)
					SquaMatrix[j].push_back(a1);
				else
				{
					SquaMatrix[j].push_back(SquaMatrix[j-1][start]-1);
				}
			}
			for(int c=start+1;c<=n-1-start;++c)//当前方框的最后一行
			{
				SquaMatrix[n-1-start].push_back(SquaMatrix[n-1-start][c-1]-1);
			}
			getMatrix(SquaMatrix,start+1,n);//里边的方框
			for(int d=start+1;d<n-1-start;++d)//当前方框的最后一列
			{
				SquaMatrix[d].push_back(SquaMatrix[d-1][n-1-start]+1);
			}
		}
	}
};
int main(int argc, char const *argv[])
{
	Solution so;
	vector<vector<int>> matrix=so.generateMatrix(5);
	for(size_t i=0;i<matrix.size();++i)
	{
		for(size_t j=0;j<matrix[i].size();++j)
			cout<<matrix[i][j]<<'\t';
		cout<<endl;
	}
	return 0;
}
