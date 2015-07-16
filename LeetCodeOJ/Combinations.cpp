// Combinations
// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// For example,
// If n = 4 and k = 2, a solution is:

// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

#include <iostream>
#include <vector>
using namespace std;
//以前做过类似的题，有点繁琐
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
    		if(n<k)
    			return combinations;
    		vector<int> temp(k);
		getCombine(n,k,1,0,temp);
    		return combinations;	
    }
private:
	vector<vector<int>> combinations;
private:
	void getCombine(const int& n,const int& k,int i,int len,vector<int> &temp)
	{
		if(len==k)
		{
			combinations.push_back(temp);
		}
		else if(i<=n-k+1+len)
		{
			for(int j=i;j<=n-k+1+len;++j)
			{
				temp[len]=j;
				getCombine(n,k,j+1,len+1,temp);
			}
		}
	}
};
int main(int argc, char const *argv[])
{
	Solution so;
	vector<vector<int>> combinations=so.combine(5,3);
	for(size_t i=0;i<combinations.size();++i)
	{
		for(size_t j=0;j<combinations[i].size();++j)
		{
			cout<<combinations[i][j]<<'\t';
		}
		cout<<endl;
	}
	return 0;
}