// Sqrt(x)(平方根) 
// mplement int sqrt(int x).

// Compute and return the square root of x.

#include <iostream>
using namespace std;
//这个题我不会，从网上找到的二分查找方法，要注意变量类型都定义long类型，尤其是mid和sum;
//也可以转化为一元二次方程，然后求解，用牛顿迭代公式来做，关于牛顿迭代公式见http://blog.csdn.net/doc_sgl/article/details/12404971 网址。
class Solution {
public:
    int mySqrt(int x) {
		long long left=1;
		long long right=x;
		while(left<=right)
		{
			long long mid=(left+right)/2;
			long long sum=mid*mid;
			if(sum<x)
				left=mid+1;
			else if(sum>x)
				right=mid-1;
			else
				return mid;
		}
		return right;
    }
};
int main(int argc, char const *argv[])
{
	Solution so;
	cout<<so.mySqrt(2147395599)<<endl;
	long long a;
	long b;
	cout<<sizeof(a)<<'\t'<<sizeof(b)<<endl;
	return 0;
}
