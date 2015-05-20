#include <iostream>
//以作用域为基础的"名称遮掩规则"并没有改变，因此base class内所有名为mf1和mf3的函数都被derived class内的mf1和mf3函数遮掩掉了。
//从名称查找观点来看，Base::mf1和Base::mf3不再被Derived继承！即使base classes和derived classes内的函数有不同的参数类型也适用，而且不论函数是virtual或non-virtual一体适用。
//在Father和Son中，当mf被调用时，任何一个Son对象都可能表现出Father或Son的行为；决定因素不在对象自身，而在于"指向该对象之指针"当初的声明类型。References也会展现和指针一样难以理解的行径。见条款36 P178
using namespace std;
class Base
{
private:
	int x;
public:
	virtual void mf1()=0;
	virtual void mf1(int a)
	{
		cout<<"Base: mf1:a:"<<a<<endl;
	}
	virtual void mf2()
	{
		cout<<"Base:mf2"<<endl;
	}
	void mf3()
	{
		cout<<"Base:mf3"<<endl;
	}
	void mf3(double d)
	{
		cout<<"Base:mf3:d:"<<d<<endl;
	}

};
class Derived:public Base
{
public:
	using Base::mf1;//让Base class 内名为mf1和mf3的所有东西
	using Base::mf3;//在Derived作用域内都可见(并且public)
	virtual void mf1()
	{
		cout<<"Derived:mf1"<<endl;
	}
	void mf3()
	{
		cout<<"Derived:mf3"<<endl;
	}
	void mf4()
	{
		cout<<"Derived:mf4"<<endl;
	}
};
class Father
{
public:
	// Father();
	virtual ~Father(){cout<<"~Father"<<endl;}
	void mf()
	{
		cout<<"Father:mf"<<endl;
	}
};
class Son:public Father
{
public:
	~Son(){cout<<"~Son"<<endl;}
	void mf()
	{
		cout<<"Son:mf"<<endl;
	}
};
int main(int argc,char *argv[])
{
	int x=4;
	Derived d;
	d.mf1();
	d.mf1(x);
	d.mf2();
	d.mf3();
	d.mf3(2);

	Son s1;
	Father *f=&s1;
	f->mf();
	Son *s2=&s1;
	s2->mf();

	Son *ns=new Son();
	Father *nf=ns;
	delete nf;
}
