// Climbing Stairs
// You are climbing a stair case. It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 
#include <iostream>

using namespace std;
//这个题比较经典，在剑指offer，编程之美上也有，回头再看一看
class Solution {
public:
	int climbStairs(int n){
		int result[3]={0,1,2};
		if(n<3)
			return result[n];

		int ways=0;
		for(int i=3;i<=n;++i)
		{
			ways=result[1]+result[2];
			result[1]=result[2];
			result[2]=ways;
		}
		return ways;
	}
};
int main(int argc, char const *argv[])
{
	Solution so;
	cout<<so.climbStairs(5)<<endl;
	return 0;
}