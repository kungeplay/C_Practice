// Ugly Number
// Write a program to check whether a given number is an ugly number.
// Ugly numbers are positive numbers whose prime factors only include 
// 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
// Note that 1 is typically treated as an ugly number.

#include <iostream>

using namespace std;

class Solution {
public:
	bool isUgly(int num) {
		if(num==0)
			return false;
		while((num&1)==0)
			num>>=1;
		while(num%3==0)
			num/=3;
		while(num%5==0)
			num/=5;
		if(num==1)
			return true;
		else
		return false;		
	}
};

int main(int argc, char const *argv[])
{
	Solution so;
	cout<<so.isUgly(0)<<endl;
	return 0;
}