// Valid Palindrome(回文（指顺读和倒读都一样的词语))
// Given a string, determine if it is a palindrome, considering only alphanumeric(文字数字的，包括文字与数字的) characters and ignoring cases.

// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.

// Note:
// Have you consider that the string might be empty? This is a good question to ask during an interview.

// For the purpose of this problem, we define empty string as valid palindrome. 

#include <iostream>

using namespace std;
//不咋难的一个与回文有关的题
class Solution {
public:
    bool isPalindrome(string s) {
    		if(s.size()==0)
    			return true;

    		int high=s.size()-1;
    		int low=0;
    		while(low<=high)
    		{
    			while(low<=high&&!isAlphanumeric(s[low]))	++low;
    			while(low<=high&&!isAlphanumeric(s[high]))	--high;
    			if(low<=high)
			{
	    			if(s[low]==s[high])
	    			{
	    				++low;
	    				--high;
	    			}
	    			else
	    				return false;
	    		}

    		}
    		return true;
    }

private:
	bool isAlphanumeric(char & c)
	{
		if(c>='0'&&c<='9')
			return true;
		else if(c>='A'&&c<='Z')
		{
			c+=32;
			return true;
		}
		else if(c>='a'&&c<='z')
			return true;
		else
			return false;
	}
};

int main(int argc, char const *argv[])
{
	char a=48;
	char b=57;
	char c=97;
	char d=122;
	char e=65;
	char f=90;
	cout<<a<<'\t'<<b<<'\t'<<c<<'\t'<<d<<'\t'<<e<<'\t'<<f<<endl;
	string s="race a -car";
	Solution so;
	cout<<so.isPalindrome(s)<<endl;
	return 0;
}