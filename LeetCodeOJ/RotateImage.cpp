// Rotate Image
// You are given an n x n 2D matrix(矩阵) representing an image.

// Rotate the image by 90 degrees (clockwise(顺时针方向的; 右旋的; 正转的)).

// Follow up:
// Could you do this in-place?
#include <iostream>
#include <vector>
using namespace std;
//这个题主要是寻找到规律，回头可以再看一看
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int start=0;
        int n=matrix.size();
        while(n-1-2*start>0)
        {
        		rotateSide(matrix,start);
        		++start;
        }
    }
private:
	void rotateSide(vector<vector<int>>& matrix,int start)
	{
		int i=start,j=start;
		int n=matrix.size();
		int dist=n-1-start*2;
		int edge=n-1-start;
		int startrow=start; 
		while(startrow!=edge)
		{
			int value=matrix[startrow][start];
			i=startrow;
			j=start;
			int r=i+dist;
			int c=start;
			if(r>edge)
			{
				c=c+r%edge;				
				r=edge;
			}
			matrix[i][j]=matrix[r][c];

			i=r;
			j=c;
			c=j+dist;
			if(c>edge)
			{
				r=r-c%edge;
				c=edge;
			}
			matrix[i][j]=matrix[r][c];

			i=r;
			j=c;
			r=i-edge;
			if(r<=0)
			{
				c=c+r;
				r=start;
			}
			matrix[i][j]=matrix[r][c];

			i=r;
			j=c;
			matrix[i][j]=value;
			++startrow;
		}
	}
};
int main(int argc, char const *argv[])
{
	// std::vector<int> v1={0,1,2,3,4};
	// std::vector<int> v2={5,6,7,8,9};
	// std::vector<int> v3={10,11,12,13,14};
	// std::vector<int> v4={15,16,17,18,19};
	// std::vector<int> v5={20,21,22,23,24};

	std::vector<int> v1={1,2,3,4,5,6};
	std::vector<int> v2={7,8,9,10,11,12};
	std::vector<int> v3={13,14,15,16,17,18};
	std::vector<int> v4={19,20,21,22,23,24};
	std::vector<int> v5={25,26,27,28,29,30};
	std::vector<int> v6={31,32,33,34,35,36};

	vector<vector<int>> matrix={v1,v2,v3,v4,v5,v6};
	Solution so;
	so.rotate(matrix);
	for(size_t i=0;i<matrix.size();++i)
	{
		for(size_t j=0;j<matrix[i].size();++j)
		{
			cout<<matrix[i][j]<<'\t';
		}
		cout<<endl;
	}
	return 0;
}