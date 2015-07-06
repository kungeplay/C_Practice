// Length of Last Word
// Given a string s consists of upper/lower-case alphabets(字母表) and empty space characters ' ', return the length of last word in the string.

// If the last word does not exist, return 0.

// Note: A word is defined as a character sequence consists of non-space characters only.

// For example,
// Given s = "Hello World",
// return 5. 
#include <iostream>
using namespace std;
//察，这么简单
class Solution {
public:
    int lengthOfLastWord(string s) {
    		if(s.size()==0)
    			return 0;
    		int len=0;
    		int last=s.size()-1;
    		while(last>=0&&s[last]==' ') --last;
    		for(;last>=0&&s[last]!=' ';--last,++len);
    		return len;
    }
};
int main(int argc, char const *argv[])
{
	string s=" ";
	Solution so;
	cout<<so.lengthOfLastWord(s)<<endl;
	return 0;
}
