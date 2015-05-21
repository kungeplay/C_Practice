#include <iostream>
using namespace std;
//一般来说，我们不能在类的内部初始化静态成员。相反的，必须在类的外部定义和初始化每个静态成员。和其他对象一样，一个静态数据成员只能定义一次.
class Account
{
public:
	void calculate(){
		amount+=amount*interestRate;
	}
	static int rate(){
		return interestRate;
	}
	static void rate(int);
private:
	std::string owner;
	int amount;
//当在类的外部定义静态成员时，不能重复static关键字，该关键字只出现在类内部的声明语句中。见下面的static的声明语句
//通常C++要求你对你所使用的任何东西提供一个定义式，但如果它是个class专属常量又是static且为整数类型(integral type,例如ints,chars,bools),则需特殊处理。
//只要不取它们的地址，你可以声明并使用它们而无须提供定义式。但如果你取某个class专属常量的地址，或纵使你不取其地址而你的编译器却(不正确地)坚持要看到一个定义式，
//你就必须另外提供定义式。见Effective C++ P14
	static const int interest=5;//class专属常量
	static constexpr int period=30;//class 专属常量
	static int interestRate;
	int scores[interest];//使用常量
	int nums[period];//使用常量
};
//即使一个常量静态数据成员在类内部被初始化了，通常情况下也应该在类的外部定义一下该成员。
//定义静态数据成员的方式和在类的外部定义成员函数差不多，需要指定对象的类型名，然后是类名，作用域运算符以及成员自己的名字
	const int Account::interest; 
 	constexpr int Account::period;
  	int Account::interestRate=8;	

void Account::rate(int newRate)
{
	interestRate=newRate;
}
int main(int argc, char const *argv[])
{
	Account account;
	cout<<account.rate()<<endl;
	return 0;
}
