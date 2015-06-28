// Divide Two Integers
// Divide two integers without using multiplication( 乘法，乘法运算), division(除法) and mod operator.

// If it is overflow(溢出，淹没), return MAX_INT. 
//dividend(被除数),
//divisor(除数)   被除数÷除数=商
#include <iostream>
#include <limits>	//(numeric_limits<int>::max)()
#include <cstdlib>

using namespace std;

//这个题，挺好，正好戳中我不会的点，网上有很多低效的或者错误的方法，要多看一看,要多看一看，耗了我两天的时间
class Solution {
public:
    int divide(int dividend, int divisor) {
    		if(isZero(divisor))
    			return (numeric_limits<int>::max)();//处理溢出
    		if(isZero(dividend))
    			return 0;

    		if(dividend==(numeric_limits<int>::min)()&&divisor==-1)//处理溢出，负数最大值除以-1，所得的值，无法用正数正确地表示出来
    			return (numeric_limits<int>::max)();

    		int flag=-1;
    		if((isNeg(dividend)&&isNeg(divisor))||(!isNeg(dividend)&&!isNeg(divisor)))
    			flag=1;

    		unsigned int x=(unsigned int)abs(dividend);
    		unsigned int y=(unsigned int)abs(divisor);
    		unsigned int re=0;
    		for(int k=31;k>=0;--k)
    		{
    			if((x>>k)>=y)
    			{
    				re+=1<<k;
    				x-=y<<k;
    			}
    		}
    		if(re>(numeric_limits<int>::max)()&&flag==-1)
    			return (numeric_limits<int>::min)();
    		else
    			return flag*re;
    }

public:
	int add(int a,int b)
	{
		if(a==(numeric_limits<int>::max)())
			return a;
		return b?add(a^b,(a&b)<<1):a;
	}
	int negative(int a)//这里有个问题无法求取负数最大值的相反数
	{
		return add(~a,1);//注意通过~取反,
	}
	//减法
	int minus(int a,int b)
	{
		return add(a,negative(b));
	}
	//判断是否是负数
	bool isNeg(int a)
	{
		return a&0x80000000;//注意此处是0x80000000因为int为4个字节,网上有些地方是0x8000，结果会得出错误的结果
	}
	//判断是否是0
	bool isZero(int a)
	{
		return !(a&0xFFFFFFFF);//注意此处是0xFFFFFFFF,网上有些地方是0xFFFF，结果会得出错误的结果
	}
	//判断是否是正数
	bool isPos(int a)
	{
		return (a&0xFFFFFFFF)&&!(a&0x80000000);
	}
};
int main(int argc, char const *argv[])
{
	int a=1029109062;
	int b=2147483647;
	int c=-2147483648;
	int d=-1;
	int e=-2147483648;
	int f=1;
	Solution so;
	// cout<<so.posDivide(a,2)<<endl;
	// cout<<~e+1<<endl;
	// cout<<(unsigned int)abs(e)<<endl;
	// cout<<so.negative(256)<<endl;
	cout<<so.divide(e,f)<<endl;


}
