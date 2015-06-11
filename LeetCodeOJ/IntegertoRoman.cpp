// Integer to Roman
// Given an integer, convert it to a roman numeral.
// Input is guaranteed to be within the range from 1 to 3999.
#include <iostream>
using namespace std;

// 个位数举例
// Ⅰ,1 】Ⅱ，2】 Ⅲ，3】 Ⅳ，4 】Ⅴ，5 】Ⅵ，6】Ⅶ，7】 Ⅷ，8 】Ⅸ，9 】
// 十位数举例
// Ⅹ，10】 Ⅺ，11 】Ⅻ，12】 XIII,13】 XIV,14】 XV,15 】XVI,16 】XVII,17 】XVIII,18】 XIX,19】 XX,20】 XXI,21 】XXII,22 】XXIX,29】 XXX,30】 XXXIV,34】 XXXV,35 】XXXIX,39】 XL,40】 L,50 】LI,51】 LV,55】 LX,60】 LXV,65】 LXXX,80】 XC,90 】XCIII,93】 XCV,95 】XCVIII,98】 XCIX,99 】
// 百位数举例
// C,100】 CC,200 】CCC,300 】CD,400】 D,500 】DC,600 】DCC,700】 DCCC,800 】CM,900】 CMXCIX,999】
// 千位数举例
// M,1000】 MC,1100 】MCD,1400 】MD,1500 】MDC,1600 】MDCLXVI,1666】 MDCCCLXXXVIII,1888 】MDCCCXCIX,1899 】MCM,1900 】MCMLXXVI,1976】 MCMLXXXIV,1984】 MCMXC,1990 】MM,2000 】MMMCMXCIX,3999】

class Solution {
public:
    string intToRoman(int num) {
		string Roman;
		for (int i = 1000; i >0 ; i/=10)
    		{
    			if (num/i!=0)
    			{
    				int current=(num/i)*i;
    				if(current==i*5)//当前数是5的倍数
    				{
    					Roman.push_back(getRomanChar(i*5));
    					num-=i*5;
    				}
    				else if(current+i==i*5)//当前数是类似4，40，400这样的情况
    				{
    					Roman.push_back(getRomanChar(i));
    					Roman.push_back(getRomanChar(i*5));
    					num-=i*4;
    				}
    				else if (current+i==i*10)//当前数是类似9,90,900
    				{
    					Roman.push_back(getRomanChar(i));
    					Roman.push_back(getRomanChar(i*10));
    					num-=i*9;
    				}
    				else if(current>i*5)//当前数大于50，小于90，或大于500，小于900这样的情况
    				{
    					Roman.push_back(getRomanChar(i*5));
    					num-=i*5;
    				}
    				while(num>=i)//下面接着处理
    				{
    					Roman.push_back(getRomanChar(i));
    					num-=i;
    				}
    			}
    		}
    		return Roman;
    }
private:
	char getRomanChar(const int& num)
	{
		switch(num)
		{
			case 1:
				return 'I';
			case  5:
				return 'V';
			case 10:
				return 'X';
			case 50:
				return 'L';
			case 100:
				return 'C';
			case 500:
				return 'D';
			case 1000:
				return 'M';
			default:
				return 'A';
		}
	}
};
int main(int argc, char const *argv[])
{
	Solution so;
	cout<<so.intToRoman(4)<<endl;

	return 0;
}
