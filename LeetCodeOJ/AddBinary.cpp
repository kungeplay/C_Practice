// Add Binary
// Given two binary strings, return their sum (also a binary string).

// For example,
// a = "11"
// b = "1"
// Return "100". 

#include <iostream>
using namespace std;

//不算难，就是比较杂，有可能是我的方法比较罗嗦吧
class Solution {
public:
    string addBinary(string a, string b) {
    		int alen=a.size();
    		int blen=b.size();

    		if(alen==0)
    			return b;
    		else if(blen==0)
    			return a;

    		string sum;
    		bool lastcarry=false,currentcarry=false;//当前进位和上一次进位
    		int alast=alen-1;
    		int blast=blen-1;
    		while(true)//当a和b都有剩余
    		{
    			char c;
    			currentcarry=addBinary(a[alast],b[blast],c);
    			if(currentcarry&&lastcarry)
    			{
    				char t=c;
    				addBinary(t,'1',c);
    			}
    			else if(!currentcarry&&lastcarry)
    			{
    				char t=c;
    				currentcarry=addBinary(t,'1',c);
    			}
    			sum.insert(sum.begin(),c);
    			lastcarry=currentcarry;
    			--alast;
    			--blast;
    			if(alast<0||blast<0)
    				break;

    		}
    		while(alast>=0)//如果a有剩余
    		{
    			char c;
    			if(lastcarry)
	    		{
	    			currentcarry=addBinary(a[alast],'1',c);
	    			lastcarry=currentcarry;
			}
			else
				c=a[alast];
			sum.insert(sum.begin(),c);
			--alast;
    		}
    		while(blast>=0)//如果b有剩余
    		{
    			char c;
    			if(lastcarry)
	    		{
	    			currentcarry=addBinary(b[blast],'1',c);
	    			lastcarry=currentcarry;
			}
			else
				c=b[blast];
			sum.insert(sum.begin(),c);
			--blast;
    		}
    		if(lastcarry)//当还有进位时
    			sum.insert(sum.begin(),'1');
    		return sum;
    }
private:
	bool addBinary( char a, char b,char &c)
	{
		string temp;
		if(a=='0')
		{
			c=b;
		}
		else if(b=='0')
			c=a;
		else
		{
			c='0';
			return true;
		}
		return false;
	}
};
int main(int argc, char const *argv[])
{
	Solution so;
	cout<<so.addBinary("11","11")<<endl;
	return 0;
}