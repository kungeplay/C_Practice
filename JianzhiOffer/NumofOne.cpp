#include <iostream>
using namespace std;
//本以为已经看懂了编程之美上这道题的解法，可是直到写时才意识到只是看个大概而已，根本没懂
//求十进制正整数N中从1开始到N的所有整数中其中所有出现"1"的个数
class Solution
{
public:
	int Sum1s(long long n)
	{
		long long iLowerNum=0;
		long long iCurrNum=0;
		long long iHigherNum=0;
		long long iFactor=1;
		long long count=0;
		while(n/iFactor!=0)
		{
			
			iHigherNum=n/(iFactor*10);
			iCurrNum=(n/iFactor)%10;
			iLowerNum=n-(n/iFactor)*iFactor;
			switch(iCurrNum)
			{
				case 0:
					count+=iHigherNum*iFactor;//由更高位决定，等于更高位数字乘以当前位数。
					break;
				case 1:
					count+=iHigherNum*iFactor+iLowerNum+1;//不仅受更高位影响，还受低位影响。
					break;
				default:
					count+=(iHigherNum+1)*iFactor;//仅由高位影响，等于更高位数字加1，再乘以当前位数。
					break;

			}
			iFactor*=10;
		}
		return count;
	}
};

int main(int argc,char *argv[])
{
	Solution so;
	long long n=123;
	cout<<so.Sum1s(n)<<endl;
}
