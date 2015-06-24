// Count and Say
// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...

// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.

// Given an integer n, generate the nth sequence.

// Note: The sequence of integers will be represented as a string. 
#include <iostream>
#include <vector>
#include <cstdio>
//除了题有点没有读懂之外，感觉没啥意思
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
  		vector<string> v;
  		v.push_back("1");
  		for(int i=1;i<=n;++i)
  		{
  			string s=getSay(v[i-1]);
  			v.push_back(s);
  		}
  		return v[n-1];
    }
private:
	string getSay(string lastsay)
	{
		string s;
		char last='c';
		int count=0;
		char temp[20];

		for(size_t i=0;i<lastsay.size();++i)
		{
			if(last=='c'||last==lastsay[i])
			{
				++count;
			}
			else
			{
				snprintf(temp,20,"%d",count);
				s+=temp;
				s.push_back(last);
				count=1;
			}
			last=lastsay[i];
		}
		snprintf(temp,20,"%d",count);
		s+=temp;
		s.push_back(last);
		return s;		
	}
};

int main(int argc, char const *argv[])
{

	Solution so;
	cout<<so.countAndSay(18)<<endl;
	return 0;
}