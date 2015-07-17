// Search a 2D Matrix 
// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//     Integers in each row are sorted from left to right.
//     The first integer of each row is greater than the last integer of the previous row.
// For example,
// Consider the following matrix: 
// [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// Given target = 3, return true.
#include <iostream>
#include <vector>
using namespace std;
//这个题不算难，通过两次二分查找。
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    		int right=matrix.size()-1;
    		int result=0;
    		if(matrix[right][0]>=target)
		 {
		 	result=binSearchEdge(matrix,target,0,right);
		 	if(result<0)
		 		return false;
		 	if(matrix[result][0]==target)
		 		return true;
		 	else
		 	{
				return binserachRow(matrix,target,result);		 		
		 	}
		 }
    		else
    		{
    			return binserachRow(matrix,target,right);
    		}
    }
	bool binserachRow(vector<vector<int>> &matrix,int target,int rownum)//在行中查找
	{
		int left=0;
		int right=matrix[rownum].size()-1;
		while(left<=right)
		{
			int mid=(left+right)/2;
			if(matrix[rownum][mid]<target)
				left=mid+1;
			else if(matrix[rownum][mid]>target)
				right=mid-1;
			else
				return true;
		}
		return false;
	}
    int binSearchEdge(vector<vector<int>> &matrix,int target,int left,int right)//先找到行
    {
    		while(left<=right)
    		{
    			int mid=(left+right)/2;
    			if(matrix[mid][0]<target)
    				left=mid+1;
    			else if(matrix[mid][0]>target)
    				right=mid-1;
    			else
    				return mid;
    		}
    		return right;
    }
};

int main(int argc, char const *argv[])
{
	vector<vector<int>> matrix;
	vector<int> temp1={1,3,5,7};
	matrix.push_back(temp1);
	vector<int> temp2={10, 11, 16, 20};
	matrix.push_back(temp2);
	vector<int> temp3={23, 30, 34, 50};
	matrix.push_back(temp3);
	Solution so;
	cout<<so.searchMatrix(matrix,9)<<endl;
	
	return 0;
}
