// Letter Combinations of a Phone Number
// Given a digit string, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below.

// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

// Note:
// Although the above answer is in lexicographical order, your answer could be in any order you want. 
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//这种类型的解题方法可以参考下
class Solution {
public:
    vector<string> letterCombinations(string digits) {
    		if(digits.size()==0)
    			return string_vector;
    		string letters(digits.size(),'1');//注意别弄反了，先大小，再是值，刚开始弄反了，结果后面有很多空字符，提交会报错
		insertVector(digits,letters,0);
		return string_vector;
    }
private:
	vector<string> string_vector;
private:

	void insertVector(string & digits,string &letters,int sequence)
	{
		if(sequence<digits.size())
		{
			string digitletter=digitToLetter(digits[sequence]);
			for(int i=0;i<digitletter.size();++i)
			{
				letters[sequence]=digitletter[i];
				if(sequence==digits.size()-1)
				{
					string_vector.push_back(letters);
				}
				else
					insertVector(digits,letters,sequence+1);
			}
		}
	}

	string digitToLetter(const char &c)
	{
		switch(c)
		{
			case '2':
			return "abc";
			case '3':
			return "def";
			case '4':
			return "ghi";
			case '5':
			return "jkl";
			case '6':
			return "mno";
			case '7':
			return "pqrs";
			case '8':
			return "tuv";
			case '9':
			return "wxyz";
			default:
			return "A";
		}
	}
};
int main(int argc, char const *argv[])
{
	string s="234";
	Solution so;
	vector<string> vs=so.letterCombinations(s);
	for(auto iter=vs.begin();iter!=vs.end();++iter)
	{
		cout<<*iter<<"\t"<<(*iter).size()<<endl;
	}
	return 0;
}
