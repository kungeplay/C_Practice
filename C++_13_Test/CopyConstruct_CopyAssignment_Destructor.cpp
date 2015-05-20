#include <iostream>
#include <string>
//练习拷贝构造，拷贝赋值，拷贝析构，实现行为像值的类
class HasPtr
{
public:
		HasPtr(const std::string &s,int m);
		HasPtr(const HasPtr &p);
		HasPtr &operator=(const HasPtr &p);
		~HasPtr()
		{
			delete ps;
		}
		void show()
		{
			std::cout<<"*ps="<<*ps<<"\t"<<"i="<<i<<std::endl;
		}
private:
	std::string *ps;
	int i;
};

HasPtr::HasPtr(const std::string &s=std::string(),int m=0):ps(new std::string(s)),i(m)
{
	std::cout<<"默认构造函数!"<<std::endl;
}


HasPtr::HasPtr(const HasPtr &p):ps(new std::string(*p.ps)),i(p.i)
{		
	std::cout<<"拷贝构找函数!"<<std::endl;
}

HasPtr & HasPtr::operator=(const HasPtr &p)//拷贝赋值运算符,在这里应考虑自赋值情况，且注意返回值
{
	std::cout<<"拷贝赋值运算符!"<<std::endl;
	auto temp=new std::string();
	*temp=*(p.ps);
	delete ps;
	ps=temp;
	i=2;
	return *this;
}
int main(int argc, char const *argv[])
{
	HasPtr A("Liu Jiakun",6);//调用默认构造函数
	HasPtr B=A;//调用拷贝构造函数
	HasPtr C;//调用默认构造函数，使用默认值
	C=A;//调用赋值运算符函数
	B.show();
	C.show();
	return 0;
}
