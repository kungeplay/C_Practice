// Pascal's Triangle II 
// Given an index k, return the kth row of the Pascal's triangle.

// For example, given k = 3,
// Return [1,3,3,1].

// Note:
// Could you optimize your algorithm to use only O(k) extra space?

#include <iostream>
#include <vector>

using namespace std;

//不咋难的题，好像我用的思路不是最简便的思路，在网上查到：
//当我们需要改变数组的值时，如果从前往后遍历，有时会带来很多麻烦，比如需要插入值，导致数组平移，或者新的值覆盖了旧有的值，但旧有的值依然需要被使用。
//这种情况下，有时仅仅改变一下数组的遍历方向，就会避免这些困难。

class Solution {
public:
    vector<int> getRow(int rowIndex) {

    		vector<int> currentRow(rowIndex+1);
    		currentRow[0]=1;
    		currentRow[1]=1;
    		if(rowIndex==1)
    			return currentRow;
    		vector<int> lastRow;
    		for(int i=2;i<=rowIndex;++i)
    		{
    			lastRow=currentRow;
    			for(int j=0;j<i;++j)
    			{
    				currentRow[j+1]=lastRow[j]+lastRow[j+1];
    			}
    			currentRow[i]=1;
    		}
    		return currentRow;
    }
};

int main(int argc, char const *argv[])
{
	Solution so;
	vector<int> currentRow=so.getRow(7);
	for(auto iter=currentRow.begin();iter!=currentRow.end();++iter)
	{
		cout<<*iter<<'\t';
	}
	cout<<endl;
	return 0;
}