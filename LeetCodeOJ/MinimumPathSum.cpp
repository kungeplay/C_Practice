// Minimum Path Sum
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.
#include <iostream>
#include <vector>
using namespace std;
//在Unique Paths和Unique PathsII两道题的基础上这个题不是很难，突然感觉到这个题是阿里实习生问我的题，多么让我伤感呀，一定要再看看Unique Paths算法题
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    		int m=grid.size();
    		if(m==0)
    			return 0;
    		int n=grid[0].size();
    		int f[m][n];
    		for(int i=0;i<m;++i)
    		{
    			for(int j=0;j<n;++j)
    			{
    				if(i==0&&j==0)
    					f[i][j]=grid[i][j];
    				else if(i==0&&j!=0)
    					f[i][j]=grid[i][j]+f[i][j-1];
    				else if(i!=0&&j==0)
    					f[i][j]=grid[i][j]+f[i-1][j];
    				else
    				{
    					f[i][j]=min(f[i][j-1],f[i-1][j])+grid[i][j];
    				}
    			}
    		}
    		return f[m-1][n-1];
    }
private:
	int min(const int& a,const int& b)
	{
		return a<=b?a:b;
	}
};
int main(int argc, char const *argv[])
{
	vector<vector<int>> obstacleGrid;
	vector<int> temp1={1,2,1};
	obstacleGrid.push_back(temp1);
	vector<int> temp2={1,1,1};
	obstacleGrid.push_back(temp2);
	vector<int> temp3={1,0,2};
	obstacleGrid.push_back(temp3);
	Solution so;
	cout<<so.minPathSum(obstacleGrid)<<endl;
	return 0;
}