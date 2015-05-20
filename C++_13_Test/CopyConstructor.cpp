//测试默认构造函数，拷贝构造函数，拷贝赋值运算符的使用方法
#include <iostream>

using namespace std;

class CExample
{
private:
	char * a;
public:
	CExample(char c)//默认构造函数
	{
		a=new char(c);;
		cout<<"默认构造函数"<<endl;
	}
	CExample(const CExample& C)//拷贝构造函数
	{
		a=new char(*(C.a));
		cout<<a<<"---拷贝构造函数"<<endl;
	}
	CExample& operator =(const CExample &C)//拷贝赋值运算符,在这里应考虑自赋值情况
	{
		char * temp=new char(*(C.a));
		delete a;
		a=nullptr;
		a=temp;
		cout<<a<<"---拷贝赋值运算符"<<endl;
		return *this;
	}
	void Show()
	{
		cout<<a<<endl;
	}
	~CExample()
	{
		delete a;
		cout<<"调用析构函数"<<endl;
	}
};
int main()
{
	CExample A('a');//直接初始化
	CExample B('b');//直接初始化 
	CExample C=A;//拷贝初始化
	CExample D(A);//也是拷贝初始化
	B.Show();
	C.Show();
	D.Show();
	D=D;//在这里调用拷贝赋值运算符
	return 0;
}
