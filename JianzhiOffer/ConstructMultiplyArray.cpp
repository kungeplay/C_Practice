//构建乘积数组
//题目：给定一个数组A[0,1,...n-1],请构建一个数组B[0,1,.,n-1],其中B中的元素B[i]=A[0]*A[1]*...A[i-1]*A[i+1]*...A[n-1].不能使用除法。
//这个题编程之美上有一道类似的题
#include <iostream>
#include <vector>

using namespace std;

//时间复杂度为O(n^2),太大了
vector<int> multiply(const vector<int> &A)
{
	vector<int> B(A.size(),1);
	for(size_t i=0;i<A.size();++i)
	{
		for(size_t j=0;j<B.size();++j)
		{
			if(i!=j)
				B[j]*=A[i];
		}
	}
	return B;
}
//用空间换时间的一种方法
vector<int> multiply1(const vector<int> &A)
{
	size_t len=A.size();
	vector<int> s(len);
	vector<int> t(len);
	s[0]=1,t[0]=1;
	for(size_t i=0;i<len-1;++i)
	{
		s[i+1]=A[i]*s[i];	
	}
	for(size_t i=1;i<len;++i)
	{
		t[i]=A[len-i]*t[i-1];
	}
	vector<int> B(len);
	for(int i=0;i<len;++i)
	{
		B[i]=s[i]*t[len-i-1];
	}
	return B;
}


int main(int argc,char *argv[])
{
	vector<int> A={1,2,3,4,5,6,7,8,9};
	vector<int> B=multiply(A);
	for(auto i : B)
	{
		cout<<i<<'\t';
	}
	cout<<endl;
	vector<int> C=multiply1(A);
	for(auto i:C)
	{
		cout<<i<<'\t';
	}
	cout<<endl;
}
