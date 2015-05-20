#include <iostream>
#include <string>
#include <map>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::cin;
/*
 * 此函数来组于书上，主要用来判断书上返回一个局部变量的引用的写法的是否正确
 */
const string & transform(const string &s,const map<string,string > &m)
{
	auto map_it=m.find(s);
	//cout<<map_it->second<<endl;
	if(map_it!=m.cend())
		return map_it->second;
	else	
		return s;
}
int main(int argc,char ** argv)
{
	map<string,string> sname{{"Liu Jiakun","刘佳坤"},{"Jiakun","佳坤"},{"Xingfulema","幸福了吗"}};
	sname.insert({"Kunge","坤哥"});
	string s;
	cout<<"请输入map容器关键字"<<endl;
	getline(cin,s);
	string value=transform(s,sname);
	cout<<value<<endl;
}
