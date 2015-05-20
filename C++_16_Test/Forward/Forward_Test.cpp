#include <iostream>
#include <utility>//forward
using namespace std;
//某些函数需要将其一个或多个实参连同类型不变地转发给其他函数。在此情况下，我们需要保持被转发实参的所有性质，包括实参类型是否是const的以及实参是左值还是右值。
//1.当我们将一个左值(如i)传递给函数的右值引用参数，且此右值引用指向模板类型参数(如T&&)时，编译器推断模板类型参数为实参的左值引用类型。
//2. 如果我们间接创建一个引用的引用，则这些引用形成了"折叠"。在所有情况下(除了一个例外)，引用会折叠成一个普通的左值引用类型。在新标准中，折叠规则扩展到右值引用。只在一种特殊情况下引用会折叠成右值引用：右值引用的右值引用。
template<typename F,typename T1,typename T2>	void flip(F f,T1 &&t1, T2 &&t2)
{
	f(std::forward<T2>(t2),std::forward<T1>(t1));
}

template<typename T> void tf(T && a)
{
	cout<<a<<endl;
}
void g(int m,int n)
{
	cout<<m<<"\t"<<n<<endl;
	//++n;
}
int main(int argc, char const *argv[])
{
	const int i=1,j=4;
	flip(g,i,j);
	cout<<"i="<<i<<endl;
	int m=8;
	tf(m);//见上面注释第一条
	return 0;
}
