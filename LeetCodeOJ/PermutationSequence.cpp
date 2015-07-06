// Permutation Sequence
// The set [1,2,3,…,n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3):

//     "123"
//     "132"
//     "213"
//     "231"
//     "312"
//     "321"

// Given n and k, return the kth permutation sequence.

// Note: Given n will be between 1 and 9 inclusive(包括的，包罗广泛的； 包括…的).

#include <vector>
#include <iostream>
using namespace std;
//这个题折磨了我好几天，后来在这个网上看到了方法http://blog.csdn.net/doc_sgl/article/details/12840715
class Solution {
public:
    string getPermutation(int n, int k) {

		string permSueq;
		if(n>9)
			return permSueq;
		int factor=getFactorial(n);
		vector<char> char_v;
		for(int i=1;i<=n;++i)
		{
			char_v.push_back(getChar(i));
		}
		--k;//别忘了首先减一下，由于数组索引是从0开始的
		while(n>0)
		{
			factor/=n;
			int pos=(k/factor)%char_v.size();
			vector<char>::iterator iter=char_v.begin()+pos;
			permSueq.push_back(*iter);
			char_v.erase(iter);//删除已经使用了的数字,这样不会影响下次循环
			k%=factor;
			--n;
		}
		return permSueq;
	}
private:
	//阶乘
	int getFactorial(int n)
	{
		if(n==1||n==0)
			return 1;
		else
			return n*getFactorial(n-1);
	}

	char getChar(int n)
	{
		switch(n)
		{
			case 1:
			return '1';
			case 2:
			return '2';
			case 3:
			return '3';
			case 4:
			return '4';
			case 5:
			return '5';
			case 6:
			return '6';
			case 7:
			return '7';
			case 8:
			return '8';
			case 9:
			return '9';
			default:
			return 'a';
		}
	}
};
int main(int argc, char const *argv[])
{
	Solution so;
	cout<<so.getPermutation(3,7)<<endl;
	return 0;
}
