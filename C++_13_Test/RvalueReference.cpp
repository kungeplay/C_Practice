#include <iostream>
#include <string>
#include <utility>
//右值引用
using std::string;
using std::cout;
using std::endl;
int main(int argc, char const *argv[])
{
	string * pstr=new string("LIjiakun");
	cout<<*pstr<<endl;
	string * &&rpstr=std::move(pstr);//psrt与rpstr共享同一块内存了
	cout<<*rpstr<<endl;
	delete rpstr;
	cout<<rpstr<<endl;
	return 0;
}
