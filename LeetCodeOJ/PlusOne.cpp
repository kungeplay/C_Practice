// Plus One
// Given a non-negative number represented as an array of digits, plus one to the number.
// The digits are stored such that the most significant(重要的; 有意义的; 有重大意义的; 值得注意的) digit is at the head of the list.
#include <iostream>
#include <vector>

using namespace std;
//不难的题
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    		bool isdecimal=true;
    		vector<int> result_v(digits.size()+1);
    		int len=digits.size();
    		int digits_len=len;
    		for(size_t i=0;i<digits.size();++i)//先判断下是否可能会有进位
    		{
    			if(digits[i]<9)
    				isdecimal=false;
    		}
    		if(!isdecimal)//无进位
    		{
    			result_v.pop_back();
    			len-=1;
    		}
    		int decimal=0;
    		for(int j=digits_len-1;j>-1;--j)
    		{
    			if(j==digits_len-1)
    			{
    				result_v[len--]=(digits[j]+1)%10;
    				decimal=(digits[j]+1)/10;
    			}
    			else
    			{
    				result_v[len--]=(digits[j]+decimal)%10;
    				decimal=(digits[j]+decimal)/10;;

    			}
    		}
    		if(decimal!=0)
    			result_v[0]=decimal;
    		return result_v;
    }
};
int main(int argc, char const *argv[])
{
	vector<int> digits={9,9,9,9,9};
	Solution so;
	vector<int> result_v=so.plusOne(digits);
	for(auto iter=result_v.begin();iter!=result_v.end();++iter)
		cout<<*iter<<'\t';
	cout<<endl;
	return 0;
}
