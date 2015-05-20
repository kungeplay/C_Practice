#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
//#include <list>
using std::cout;
using std::string;
using std::vector;
//using std::list;
using std::endl;
using std::ends;
using std::fstream;
using std::ofstream;
using std::stringstream;

bool ReverseSort(const string &,const string &);
int print(ofstream &,const vector<string> &);

int main(int argc,char ** argv)
{
fstream Infile("./In_Test",fstream::in);
ofstream Outfile("./Out_Test_Sort",ofstream::out);
string strline;
string temp;
vector<string> svector;
//list<string> svector;
while(getline(Infile,strline))
{
	if(strline.size()>5&&strline.substr(0,5).compare("Month")==0)//substr()的参数为可选的开始位置和计数值
	{
	stringstream strstream(strline.erase(0,6));//str.erase(pos,len)删除从位置pos开始的len个字符，len可被省略。返回一个指向str的引用
	while(strstream>>temp)
		svector.push_back(temp);
	break;
	}
}
if(svector.size()==0)
{
	Outfile<<"请仔细检查In_Test文件是否含有Month标志的一行字符串";
}
else
{
	Outfile<<"读取In_Test成功! 容器svector.size()="<<svector.size()<<" svector.capacity()="<<svector.capacity()<<endl;
        print(Outfile,svector);
	Outfile<<"常规排序操作:"<<endl;
	sort(svector.begin(),svector.end());
        print(Outfile,svector);
	Outfile<<"反向排序操作:"<<endl;
	sort(svector.begin(),svector.end(),ReverseSort);//sort的第二个版本，此版本是重载过的，它接受第三个参数，此参数是一个谓词
        print(Outfile,svector);
	Outfile<<"排序后把重复值移到最后,此时最后几个值已经成为无任何价值的废值:"<<endl;
	auto unbegin=unique(svector.begin(),svector.end());//unique函数必须配合sort函数先排序
 	print(Outfile,svector);
	Outfile<<"使用向量操作erase删除重复单词:"<<endl;
	svector.erase(unbegin,svector.end());//删除重复的废值
        print(Outfile,svector);
}
cout<<"所有输出信息均输出倒Out_Test_Sort中!"<<endl;
}
//谓词
bool ReverseSort(const string & str1,const string & str2)
{
return str1<str2?false:true;
}
//打印函数出到指定流中
int print(ofstream & Outfile,const vector<string> & svector)
{
auto svbegin=svector.cbegin();
while(svbegin!=svector.cend())
	Outfile<<*svbegin++<<"	"<<ends;
Outfile<<endl;

}
