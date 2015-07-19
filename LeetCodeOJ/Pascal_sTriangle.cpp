/*
Pascal(帕斯卡尔)'s Triangle(三角形; 三人一组)
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
#include <iostream>
#include <vector>
using namespace std;
//不难的一个题
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        for(int i=1;i<=numRows;++i)
        		generateRow(i);
        	return triangle;
    }
private:
	vector<vector<int>> triangle;
private:
	void generateRow(int numRows)
	{
		vector<int> row;		
		row.push_back(1);
		if(numRows!=1)
		{
			auto previousRow=triangle[triangle.size()-1];
			for(size_t i=0;i<previousRow.size();++i)
			{
				if(i+1<previousRow.size())
					row.push_back(previousRow[i]+previousRow[i+1]);
				else
					row.push_back(previousRow[i]);
			}

		}
		triangle.push_back(row);
	}

};
int main(int argc, char const *argv[])
{
	Solution so;
	so.generate(5);
	return 0;
}