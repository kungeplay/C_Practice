#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::ends;
int main(int argc,char ** argv)
{
string temp;
ofstream outfs("./Out_Test_Vector.txt",ofstream::out);
ifstream infs("./In_Test_Vector.txt",ifstream::in);
vector<string> svect{"123","234","345","456","567","Hello","Liu Jiakun"};
outfs<<"svect[6]="<<svect[6]<<"	svect.size()="<<svect.size()<<"	svect.capacity()="<<svect.capacity()<<endl;
while(infs>>temp)
	svect.push_back(temp);
infs.close();
outfs<<"来自于./In_Test_Vector.txt插入到容器svect的元素为: "<<endl;
temp="Liu Jiakun";
auto tempmid=find(svect.cbegin(),svect.cend(),temp);
tempmid++;
while(tempmid!=svect.end())
{
outfs<<*tempmid++<<"	"<<ends;
}
outfs<<endl;
auto sum=stoi(*svect.cbegin())+123;
outfs<<"stoi(*svect.cbegin())+123="<<sum<<endl;
outfs<<*(--svect.end())<<"	svect.size()="<<svect.size()<<"	svect.capacity()="<<svect.capacity()<<endl;
outfs.close();
cout<<"所有输出结果已经写入到Out_Test_Vector.txt中"<<endl;

}
