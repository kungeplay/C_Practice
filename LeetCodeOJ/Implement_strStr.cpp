// Implement strStr()
//strStr() 函数搜索一个字符串在另一个字符串中的第一次出现。找到所搜索的字符串，则该函数返回第一次匹配的字符串的地址；
// Returns the index of the first occurrence( 发生，出现； 遭遇，事件 ) of needle( 针； 针状物； <口>刺激性言行 ) in haystack(干草堆), or -1 if needle is not part of haystack.

// Update (2014-11-02):
// The signature of the function had been updated to return the index instead of the pointer. 
// If you still see your function signature returns a char * or String, please click the reload button to reset your code definition. 
#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
		if(needle.size()>haystack.size())
			return -1;
		if(needle.size()==0)
			return 0;
		int i=0;
		while(haystack.size()-i>=needle.size())
		{
			if(vertifyStr(haystack,needle,i)==true)
				return i;
			++i;
		}
		return -1;
    }
private:
	bool vertifyStr(const string& haystack,const string & needle,int i)
	{
		for(int j=0;j<needle.size();++j,++i)
		{
			if(haystack[i]==needle[j])
				continue;
			else
				return false;
		}
		return true;
	}

};
int main(int argc, char const *argv[])
{
	string haystack="123434678";
	string needle="345";
	Solution so;
	cout<<so.strStr(haystack,needle)<<endl;	
	return 0;
}