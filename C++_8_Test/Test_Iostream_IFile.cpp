#include <iostream>
#include <fstream>
#include <string>
using std::string;
using std::ifstream;
using std::cout;
using std::ends;
using std::endl;
int main(int argc,char ** argv)
{
ifstream ifile;
string s1;
string s2;
ifile.open("./125",ifstream::in);
if(!ifile)//判断文件是否打开
{
cout<<"打开文件失败!"<<endl;
return 1;
}
while(getline(ifile,s1))//每次读取一行
{
cout<<s1<<"-------"<<endl;
}
cout<<"-----------------------"<<endl;
if(ifile.is_open())//判断文件是否打开
{
cout<<"文件已经打开!"<<endl;
ifile.close();//若文件已经打开，则关闭
}
ifile.open("./125",ifstream::binary);//，以二进制格式重新打开文件
while(ifile>>s2)
{
cout<<s2<<endl;
}
}

