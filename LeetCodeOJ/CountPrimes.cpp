// Count Primes
// Description:
// Count the number of prime numbers less than a non-negative number, n.

#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		vector<bool> num(n,true);
		int sqrt_n=static_cast<int>(sqrt(n));//由于n内的合数肯定有个因子小于sqrt(n).
		for(int i=2;i<=sqrt_n;++i)
		{
			if(num[i])//为true表示为质数
				for(int j=2;j*i<n;++j)//标志其倍数均不是质数
					num[j*i]=false;
		}
		int count=0;//开始统计
		for(int i=2;i<n;++i)
			if(num[i])
			{
				++count;
			}
		return count;
	}
};

int main(int argc, char const *argv[])
{
	Solution so;
	cout<<so.countPrimes(11)<<endl;
	return 0;
}