#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::string;
using std::ifstream;
using std::cout;
using std::endl;
//将主体型值点（一半）.txt中的每行3个浮点数取出并存在vector中
int main(int argc,char ** argv)
{
	ifstream ifile;
	string str;
	std::vector<float> vfloat;
	int index=0;

	ifile.open("./主体型值点（一半）.txt",ifstream::in);
	if(!ifile)//判断文件是否打开
	{
		cout<<"打开文件失败!"<<endl;
		return 1;
	}


	while(getline(ifile,str))//每次读取一行
	{
		for (int i = 0; i < 2; ++i)
		{
			index=str.find_first_of(' ');//找到第一个空格
			while (index==0)//若第一个空格的索引位置为0，则删除重新查找
			{
				str.erase(0,1);
				index=str.find_first_of(' ');
			}
			//截取第一个浮点数并插入Vector
			vfloat.push_back(stof(str.substr(0,index)));
			str.erase(0,index);//删除已经截取过得字串浮点数
		}
		vfloat.push_back(stof(str));//将第三个浮点数插入Vector
	}


	if(ifile.is_open())//判断文件是否打开
	{
		ifile.close();//若文件已经打开，则关闭
	}

	//打印显示Vector内容
	 for (auto viter = vfloat.begin(); viter != vfloat.end(); ++viter)
	 {
	 	cout<<*viter<<endl;
	 }

}
