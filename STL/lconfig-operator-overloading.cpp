#include <iostream>
using namespace std;
class INT
{
	friend ostream& operator<<(ostream& os,const INT& i);
public:
	INT(int i):m_i(i){};
	//prefix:increment and then fetch
	INT& operator++()
	{
		++(this->m_i);//随着class的不同，该行应该有不同的操作
		return *this;
	}

	//postfix:fetch and then increment
	const INT operator++(int)
	{
		INT temp=*this;
		++(*this);
		return temp;
	}

	//prefix:decrement and then fetch
	INT& operator--()
	{
		--(this->m_i);	//随着class的不同，该行应该有不同的操作
		return *this;
	}

	//postfix: fetch and then decrement
	const INT operator--(int)
	{
		INT temp=*this;
		--(*this);
		return temp;
	}

	//dereference
	int & operator*() const
	{
		return (int&)m_i;
		//以上转换操作告诉编译器，你确实要将const int 转non-const lvalue.
		//如果没有这样明白地转型，有些编译器会给你警告，有些更严格的编译器会视为错误
	}
private:
	int m_i;
};


ostream & operator<<(ostream& os,const INT& i)
{
	os<<'['<<i.m_i<<']';
	return os;
}
int main()
{
	INT I(5);
	cout<<I++<<endl;
	cout<<++I<<endl;
	cout<<I--<<endl;
	cout<<--I<<endl;
	cout<<*I<<endl;
}
