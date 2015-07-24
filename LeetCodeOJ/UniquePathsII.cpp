// Unique Paths II
// Follow up for "Unique Paths":

// Now consider if some obstacles are added to the grids. How many unique paths would there be?

// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

// For example,

// There is one obstacle in the middle of a 3x3 grid as illustrated below.

// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]

// The total number of unique paths is 2.

// Note: m and n will be at most 100.
#include <iostream>
#include <vector>
using namespace std;
//如果上一个题会了，这个题就不算难了
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    		int m=obstacleGrid.size();
    		if(m==0)
    			return 0;
    		int n=obstacleGrid[0].size();

    		int f[m][n]={0};

    		for(int i=0;i<m;++i)
    		{
    			for(int j=0;j<n;++j)
    			{
    				if(obstacleGrid[i][j]!=0)
    					f[i][j]=0;
    				else
    				{
	    				if(i==0&&j==0)
	    					f[i][j]=1;
	    				else if(i==0&&j!=0)
	    				{
    						f[i][j]=f[i][j-1];
	    				}
	    				else if(i!=0&&j==0)
	    				{
    						f[i][j]=f[i-1][j];
	    				}
	    				else
	    				{
	    					f[i][j]=f[i-1][j]+f[i][j-1];
	    				}
	    			}
    			}
    		}
    		return f[m-1][n-1];

    }
};
int main(int argc, char const *argv[])
{
	vector<vector<int>> obstacleGrid;
	vector<int> temp1={0,0,0};
	obstacleGrid.push_back(temp1);
	vector<int> temp2={0,1,0};
	obstacleGrid.push_back(temp2);
	vector<int> temp3={0,0,0};
	obstacleGrid.push_back(temp3);
	Solution so;
	cout<<so.uniquePathsWithObstacles(obstacleGrid)<<endl;
	return 0;
}