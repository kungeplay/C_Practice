//Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 //For example:
//Given "25525511135",
//return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
//注意这个题中生成的IP地址长度只能等于原来字符串的长度+3(三个点)
//主要是临界条件的判断上
//采用递归的方法,有点像深度递归遍历
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
using std::string;
using std::vector;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        return getAddresses(s,0,0);
    }

private:
    //order为层次从0开始，到3结束，beginnum为字符串中的序号
    std::vector<string> getAddresses(const string &s,int order,int beginnum)
    {
    		std::vector<string> v;
    		if (order==3)
    		{
            if (s.size()-beginnum>3||s.size()-beginnum<=0)
            {
                return v;
            }
            string tempstr=getNum(s,beginnum,s.size()-1);
            if (tempstr.size()==0)
            {
                return v;
            }
            else
            {
                v.push_back("."+tempstr);
                return v;
            }
    		}
    		else
    		{
    			int leavelen=s.size()-beginnum;

    			if (leavelen>(4-order)*3||leavelen<(4-order))
    			{
    				return v;
    			}
    			else
    			{
    				for (int i = 0; i < 3; ++i)
    				{
                        string tempstr=getNum(s,beginnum,beginnum+i);
                        if (tempstr.size()==0)
                        {
                            continue;
                        }
    					std::vector<string> childv=getAddresses(s,order+1,beginnum+i+1);
    					if (childv.size()==0)
    					{				
    						continue;
    					}
    	    				for (std::vector<string>::iterator iter = childv.begin(); iter != childv.end(); ++iter)
    	    				{
    	    					string str="";
    	    					if(order!=0)
    	    						str=".";
    	    					str+=tempstr;
    						v.push_back(str+*iter);
    					}
    				}

    			}
    			return v;
    		}
    }
   	string getNum(const string &s,int beginnum,int endnum)
    {

        int num=0;
        if(endnum>=s.size()) 
        {
            return "";
        }
        for (int i = beginnum; i <=endnum; ++i)
        {
            num=num*10+(s[i]-'0');
        }
        if (num>255)
        {
            return "";
        }
        char tempstr[4];
        snprintf(tempstr,sizeof(tempstr),"%d",num);
        if (strlen(tempstr)!=(endnum+1-beginnum))
        {
            return "";
        }
        return tempstr;
    }
};
int main(int argc, char const *argv[])
{
	Solution s;
	//string str="25525511135";
    //string str="0000";
    string str="010010";
	std::vector<string> v= s.restoreIpAddresses(str);
	std::cout<<v.size()<<std::endl;
	for (std::vector<string>::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		std::cout<<*iter<<std::endl;
	}
	return 0;
}