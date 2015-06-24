// Multiply Strings
// Given two numbers represented as strings, return multiplication of the numbers as a string.

// Note: The numbers can be arbitrarily(任意，恣意的) large and are non-negative.
#include <iostream>
#include <vector>
//不算难，就是比较杂
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
	       if(num1=="0"||num2=="0")
	       	return "0"; 
	       len1=num1.size();
	       len2=num2.size();
	       int last=0;
	       string s;
	       for(int i=len1+len2-2;i>=0;--i)
	       {
	       	int add=0;
	       	int decimal=0;
	       	vector<vector<int>> v=getCombination(i);
	       	for(size_t j=0;j<v.size();++j)
	       	{	
	       		add=getAdd(add,charToNum(num1[v[j][0]])*charToNum(num2[v[j][1]]),decimal);
	       	}
	       	add=getAdd(add,last,decimal);
	       	add=getAdd(add,0,decimal);
	       	s.push_back(numToChar(add));
	       	last=decimal;
	       }
	       if(last!=0)
	       	s.push_back(numToChar(last));

	       int s1=0,s2=s.size()-1;
	       while(s1<s2)
	       {
	       	char c=s[s1];
	       	s[s1]=s[s2];
	       	s[s2]=c;
	       	++s1;
	       	--s2;
	       }
	       return s;
    }
private:
	size_t len1;
	size_t len2;
private:
	vector<vector<int>> getCombination(size_t sum)
	{
		vector<vector<int>> rest_value;
		for(size_t i=0;i<len1;++i)
		{
			if(i>sum)
				break;
			for(size_t j=0;j<len2;++j)
			{
				if(j>sum)
					continue;
				if(i+j==sum)
				{
					vector<int> iv;
					iv.push_back(i);
					iv.push_back(j);
					rest_value.push_back(iv);
				}
			}
		}
		return rest_value;

	}
	int getAdd(int i,int j,int &decimal)
	{
		int add=i+j;
		decimal+=add/10;
		return add%10;
	}
	int charToNum(char c)
	{
		switch(c)
		{
			case '0':
			return 0;
			case '1':
			return 1;
			case '2':
			return 2;
			case '3':
			return 3;
			case '4':
			return 4;
			case '5':
			return 5;
			case '6':
			return 6;
			case '7':
			return 7;
			case '8':
			return 8;
			case '9':
			return 9;
			default:
			return -1;
		}
	}
	char numToChar(int num)
	{
		switch(num)
		{
			case 0:
			return '0';
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
	string num1="300";
	string num2="200";
	Solution so;
	cout<<so.multiply(num1,num2);
	return 0;
}