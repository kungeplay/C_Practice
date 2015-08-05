// Reverse Words in a String
// Given an input string, reverse the string word by word.

// For example,
// Given s = "the sky is blue",
// return "blue is sky the".

// Update (2015-02-12):
// For C programmers: Try to solve it in-place in O(1) space. 

#include <iostream>

using namespace std;

//剑指offer上有这个题，所以以前看过思路，现在觉得不难。，注意首先要剔除空格,剑指offer上没有提供解决单词间额外空格的问题
//我下面的思路是翻转单词时，把所有额外的空格都翻转到字符串的最后，然后再剔除。
class Solution {
public:
	void reverseWords(string &s) {
		int len=s.size();
		if(len==0)
			return;		
		int  index=-1;
		int  step=0;//记录两个单词间的额外的空格数量
		bool hasWord=false;//记录index和i之间是否已经包含单词了
		for(int i=0;i<=len;++i)
		{
			if(i==len||s[i]==' ')
			{
				if(hasWord)
				{
					reverseString(s,index+1,i-1);
					hasWord=false;
					index=i-step;//index指向i之前的单词后的第一个空格
				}
				else
					++step;
			}
			else
				hasWord=true;//这样，index和i之间就包含单词了，下一次碰到空格时，就可以翻转了	
		}
		while(len>0&&s[len-1]==' ')//剔除所有额外的空格
		{
			s.pop_back();
			--len;
		}
		if(len==0)
			return;
		reverseString(s,0,len-1);//翻转整个字符串
	}
private:
	void reverseString(string & s,int begin,int last)
	{
		while(begin<last)
		{
			swap(s[begin],s[last]);
			++begin;
			--last;
		}
	}
};
int main(int argc, char const *argv[])
{
	string s="the     sky     is    blue  ";
	Solution so;
	so.reverseWords(s);
	cout<<s<<endl;
	return 0;
}