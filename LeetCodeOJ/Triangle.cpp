// Triangle
// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adindexElemacent numbers on the row below.
//给定一个三角形，求得和最小的路径。每层只能选一个整数，上一层和下一层的整数必须是相邻的。
// For example, given the following triangle

// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]

// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

// Note:
// Bonus point(加分) if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

#include <iostream>
#include <vector>
using namespace std;
//察，这个题，题意就没讲明白，说是相邻的，只是当前索引所在节点和前一个节点两个比较，取出较小值，当索引是0时，也不用比较。
//害我费了好久。
//不过我用的方法是对的。从后往前更新
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

    		int rowNum=triangle.size();
    		vector<int> ExtraSpace(rowNum);
    		ExtraSpace[0]=triangle[0][0];
    		int minSum=triangle[0][0];
    		for(int i=1;i<rowNum;++i)
    		{
    			int indexElem=i;
    			while(indexElem>=0)
    			{
    				if(indexElem==i)
    				{
	    				ExtraSpace[indexElem]=ExtraSpace[indexElem-1]+triangle[i][indexElem];
	    				if(i==rowNum-1)
	    				{
	    					minSum=ExtraSpace[indexElem];
	    				}
    				}
	    			else if(indexElem==0)
	    			{
	    				ExtraSpace[indexElem]=ExtraSpace[indexElem]+triangle[i][indexElem];
	    				if(i==rowNum-1&&minSum>ExtraSpace[indexElem])
	    					minSum=ExtraSpace[indexElem];
	    			}    				
	    			else if(indexElem==i-1)
	    			{
	    				ExtraSpace[indexElem]=min(ExtraSpace[indexElem],ExtraSpace[indexElem-1])+triangle[i][indexElem];
	    				if(i==rowNum-1&&minSum>ExtraSpace[indexElem])
	    					minSum=ExtraSpace[indexElem];
	    			}
	    			else
	    			{
	    				ExtraSpace[indexElem]=min(ExtraSpace[indexElem-1],ExtraSpace[indexElem])+triangle[i][indexElem];
	    				if(i==rowNum-1&&minSum>ExtraSpace[indexElem])
	    					minSum=ExtraSpace[indexElem];

	    			}
	    			--indexElem;
    			}
			// for(int t=0;t<=i;++t)
			// 	cout<<ExtraSpace[t]<<'\t';
			// cout<<endl;    			
    		}
    		return minSum;
    }
private:
	int min(int a,int b)
	{
		return a<b?a:b;
	}
	// int min(int a,int b,int c)
	// {
	// 	return min(a,b)<c?min(a,b):c;
	// }
};

int main(int argc, char const *argv[])
{
	vector<vector<int>> triangle={{-7},{-2,1},{-5,-5,9},{-4,-5,4,4},{-6,-6,2,-1,-5},{3,7,8,-3,7,-9},{-9,-1,-9,6,9,0,7},{-7,0,-6,-8,7,1,-4,9},{-3,2,-6,-9,-7,-6,-9,4,0},{-8,-6,-3,-9,-2,-6,7,-5,0,7},{-9,-1,-2,4,-2,4,4,-1,2,-5,5},{1,1,-6,1,-2,-4,4,-2,6,-6,0,6},{-3,-3,-6,-2,-6,-2,7,-9,-5,-7,-5,5,1}};
	Solution so;
	cout<<so.minimumTotal(triangle)<<endl;
	return 0;
}