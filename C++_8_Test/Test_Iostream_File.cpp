#include <iostream>
#include <fstream>
using std::ofstream;
using std::ends;
using std::string;
using std::cout;
using std::endl;
int main(int argc,char ** argv)
{
string s="./124.txt";
ofstream output(s,ofstream::app);
if(output)
	output<<"来自星星的你"<<ends<<"大结局"<<endl;
else
	cout<<"创建文件流失败"<<endl;
}
