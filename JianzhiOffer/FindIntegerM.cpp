//剑指offer上的一个题，任意给定一个正整数N，求一个最小的正整数M(M>1),使得N*M的十进制表示形式里只含有1和0.
//将查找M，使得M*N这个数只含有0,1的问题转化为先找只含有0，1数字的X问题。
#include <iostream>
#include <vector>
using namespace std;
//这个题，肯定是可以求出M的，编程之美上错了。可以根据循环节来证明：由于mod(N)的值有限见网站：http://blog.csdn.net/jcwkyl/article/details/3859155
class Solution
{
public:
	int FindIntegerM(int N)
	{
		vector<vector<int>> bigInt(N);			//bigInt只记录整数中1出现的位置，比如1001,记为(0,3)=10^0+10^3
		bigInt[1].push_back(0);				//余数为1时k为0

		for (int i=1,j=10%N ; ; ++i,j=(j*10)%N)		//j表示10^k与N的模，即10^k与N的余数,注意这里的j是利用上一次循环的j算出来的;i表示其中的k
		{
			if(bigInt[j].size()==0)			//保存10^k与N的余数
				bigInt[j].push_back(i);
			for(int k=1;k<N;++k)
			{
				if((bigInt[k].size()!=0)			//非空余数
					&&(i>bigInt[k][bigInt[k].size()-1])	//与下一层比较
					&&(bigInt[(k+j)%N].size()==0))		//看看会不会 出现新的余数。
				{
					bigInt[(k+j)%N]=bigInt[k];
					bigInt[(k+j)%N].push_back(i);
				}
			}
			if(bigInt[0].size()!=0)
				break;
		}
		long long multiply=0;
		int len=bigInt[0].size();
		for(int i=0;i<len;++i)
		{
			multiply+=powered(10,bigInt[0][i]);
		}
		return multiply/N;
	}
	long long powered(int x,unsigned int expont)
	{
		if(expont==0)
			return 1;
		else if(expont==1)
			return x;
		long long result=powered(x,expont>>1);
		result*=result;
		if((expont&0x01)==1)
			result*=x;
		return result;
	}
};

int main(int argc, char const *argv[])
{
	Solution so;
	cout<<so.FindIntegerM(31);
	return 0;
}
