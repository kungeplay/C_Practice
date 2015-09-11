// Compare Version Numbers
// Compare two version numbers version1 and version2.
// If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

// You may assume that the version strings are non-empty and contain only digits and the . character.
// The . character does not represent a decimal point and is used to separate number sequences.
// For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

// Here is an example of version numbers ordering:

// 0.1 < 1.1 < 1.2 < 13.37
#include <iostream>
#include <string>
using namespace std;
//这个题还不算难，就是要考虑的挺多
class Solution {
public:
	int compareVersion(string version1, string version2) {
		int len1=version1.size();
		int len2=version2.size();
		int i=0,j=0;
		while(true)
		{
			string str1,str2;
			while(i<len1&&version1[i]!='.')
			{
				str1.push_back(version1[i]);
				++i;
			}
			while(j<len2&&version2[j]!='.')
			{
				str2.push_back(version2[j]);
				++j;
			}
			if(str1.empty()||str2.empty())
			{
				if(str1.empty())
				{
					if(str2.empty()||myStoi(str2)==0)
						return 0;
					else
						return -1;

				}
				if(str2.empty())
				{
					if(myStoi(str1)==0)
						return 0;
					else
						return 1;
				}
			}
			int com=stringCompare(str1,str2);
			if(com!=0)
				return com;
			++i;
			++j;
		}
	}
private:
	int stringCompare(const string &str1,const string& str2)
	{
		int t1=myStoi(str1);
		int t2=myStoi(str2);
		if(t1>t2)
			return 1;
		else if(t1==t2)
			return 0;
		else
			return -1;
	}
	int myStoi(const string &s)
	{
		int num=0;
		for(size_t i=0;i<s.size();++i)
		{
			num+=num*10+(s[i]-'0');
		}
		return num;
	}
};

int main(int argc,char *argv[])
{
	string version1="14.2.7";
	string version2="14.2.7.0";
	Solution so;
	cout<<so.compareVersion(version1,version2)<<endl;
}
