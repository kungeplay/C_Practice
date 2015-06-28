// Anagrams(由颠倒字母顺序而构成的字)
// Given an array of strings, return all groups of strings that are anagrams.

// Note: All inputs will be in lower-case.

// Anagram（回文构词法）。Anagrams是指由颠倒字母顺序组成的单词，比如“dormitory”颠倒字母顺序会变成“dirty room”，“tea”会变成“eat”。
// 回文构词法有一个特点：单词里的字母的种类和数目没有改变，只是改变了字母的排列顺序。
// For example:
// Input: ["tea","and","ate","eat","dan"]
// Expected Output: ["and","dan","tea","ate","eat"]

//我没有看出Note的用处，可能是我的方法不够高效吧,但是在网上的算法也都和我这差不多额
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
    		map<string,vector<string>> diffAnagram;
		vector<string> temp;
    		if(strs.size()<=1)
    		{
    			return temp;
    		}
    		for(auto iter=strs.begin();iter!=strs.end();++iter)
    		{
    			diffAnagram[quickSort(*iter)].push_back(*iter);
    		}

    		for(auto iter=diffAnagram.begin();iter!=diffAnagram.end();++iter)
    		{
    			if((*iter).second.size()>1)
    			{
    				temp.insert(temp.end(),(*iter).second.begin(),(*iter).second.end());
    			}
    		}
    		return temp;
    }
private:
	string quickSort(string str)
	{	
		string s=str;
		qSort(s,0,s.size()-1);
		return s;
	}
	void qSort(string &s,int low,int high)
	{
		if(low<high)
		{
			int pivotloc=Partition(s,low,high);
			qSort(s,low,pivotloc-1);
			qSort(s,pivotloc+1,high);
		}
	}
	int Partition(string &s,int low,int high)
	{
		int pivotvalue=s[low];
		while(low<high)
		{
			while(low<high&&s[high]>=pivotvalue) --high;
			s[low]=s[high];
			while(low<high&&s[low]<=pivotvalue)	++low;
			s[high]=s[low];
		}
		s[low]=pivotvalue;
		return low;
	}
};
int main(int argc, char const *argv[])
{
	vector<string> v={"tea","and","ate","eat","dan"};
	// vector<string> v={"","b"};

	Solution so;
	std::vector<string> str_v=so.anagrams(v);
	for(auto str : str_v)
		cout<<str<<'\t';
	cout<<endl;
	return 0;
}
