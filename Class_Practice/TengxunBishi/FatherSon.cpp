#include <iostream>
//在默认情况下，派生类中含有继承链上每个类对应的子部分。如果某个类在派生过程中出现了多次，则派生类中将包含该类的多个子对象。
//在C++语言中我们通过虚继承的机制解决这个问题，虚继承的目的是令某个类做出声明，承诺愿意共享它的基类。。其中，共享的基类子对象称为虚基类。在这种机制下，
//不论虚基类在继承体系中出现了多少次，在派生类中都只包含唯一一个共享的虚基类子对象。virtual说明符标明了一种愿望，即在后续的派生类当中共享虚基类的同一份实例
//派生类的构造函数初始值列表将实参分别传递给每个直接基类。其中基类的构造顺序与派生列表中基类的出现顺序保持一致。而与派生类构造函数初始值列表中基类的顺序无关。
class Base
{
public:
	Base(int i)
	{
		std::cout<<i;
	}
	~Base()=default;
};
class Base1:public virtual Base
{
public:
	Base1(int j,int i=8):Base(i)
	{
		std::cout<<j;
	}
	~Base1()=default;
};
class Base2:public virtual Base
{
public:
	Base2(int j,int i=7):Base(i)
	{
		std::cout<<j;
	}
	~Base2()=default;
};
class Drived:public Base1,public Base2
{
public:
	Drived(int a,int b,int c,int d):mem2(1),mem1(2),Base2(3),Base1(4),Base(5)
	{
		std::cout<<6;
	}
private:
	Base1 mem1;
	Base2 mem2;
};
int main(int argc,char *argv[])
{
	Drived f(1,2,3,4);
	std::cout<<std::endl;
	Base1 b1(10);
	std::cout<<std::endl;
	Base b=9;
	std::cout<<std::endl;
}

