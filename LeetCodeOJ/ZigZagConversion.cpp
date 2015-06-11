// ZigZag Conversion
//  The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R

// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string text, int nRows);

// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
//这个题果然不难，主要是思路，建立模型
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
    		if(numRows<=1)
    			return s;
  		std::vector<vector<char>> vRows(numRows);

		bool isodd=true;
		int rowindex=0;
  		for(auto c : s)
  		{
			vRows[rowindex].push_back(c);
			if (isodd)
			{
				if (++rowindex==numRows)
				{
					rowindex=numRows-2;
					isodd=false;
				}
			}
			else
			{
				if (--rowindex==-1)
				{
					rowindex=1;
					isodd=true;
				}
			}
  		}
  		string res;
  		for (auto v : vRows)
  		{
  			res.insert(res.end(),v.begin(),v.end());
  		}
  		return res;

    }
};
int main(int argc, char const *argv[])
{
	string s1="ABC";//"PAYPALISHIRING";
	Solution so;
	string res=so.convert(s1,2);
	cout<<res<<endl;
	return 0;
}
