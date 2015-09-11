// Ugly Number II
// Write a program to find the n-th ugly number.
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
// For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
// Note that 1 is typically treated as an ugly number. 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> uglyArray(n);
		uglyArray[0]=1;
		int multiply2Index=0;
		int multiply3Index=0;
		int multiply5Index=0;

		int nextIndex=1;
		while(nextIndex<n)
		{
			int minUgly=min(uglyArray[multiply2Index]*2,uglyArray[multiply3Index]*3,uglyArray[multiply5Index]*5);

			uglyArray[nextIndex]=minUgly;

			while(uglyArray[multiply2Index]*2<=minUgly)
				++multiply2Index;
			while(uglyArray[multiply3Index]*3<=minUgly)
				++multiply3Index;
			while(uglyArray[multiply5Index]*5<=minUgly)
				++multiply5Index;

			++nextIndex;
		}
		return uglyArray[n-1];
	}
private:
	int min(int a,int b,int c)
	{
		int curmin=a<b?a:b;
		return curmin<c?curmin:c;
	}
};

int main(int argc, char const *argv[])
{
	Solution so;
	cout<<so.nthUglyNumber(1500)<<endl;
	return 0;
}