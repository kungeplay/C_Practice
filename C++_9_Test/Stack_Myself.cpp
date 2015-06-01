#include <iostream>
#include <vector>
#include <list>
//利用模板知识，和在STL源码剖析中看到的stack底层默认是由deque实现的，突发想用vector默认实现一个。于是下面的Mystack中是按照stack的对外接口保持一致
//其中还涉及到友元函数模板
using namespace std;
//注意友元函数使用前必须声明，注意声明方式
template <typename T,typename Sequence> class MyStack;
template <typename T,typename Sequence> bool operator==(const MyStack<T,Sequence>& s1,const MyStack<T,Sequence>&s2);
template <typename T,typename Sequence> bool operator<(const MyStack<T,Sequence>& s1,const MyStack<T,Sequence>&s2);

template <typename T,typename Sequence=vector<T>>
class MyStack
{
	typedef typename Sequence::value_type value_type;//注意加上typename，不是template
	typedef typename Sequence::difference_type difference_type;
	typedef typename Sequence::pointer pointer;
	typedef typename Sequence::reference reference;
	typedef typename Sequence::const_reference const_reference;	
	typedef typename Sequence::size_type size_type;
	friend bool operator== <>(const MyStack &,const MyStack &);//友元函数模板与类模板一对一匹配，注意使用方式
	friend bool operator< <>(const MyStack &s1,const MyStack &s2);	
protected:
	Sequence c;//底层容器
public:
	MyStack()=default;
	template <typename InputIterator> MyStack(InputIterator first,InputIterator last):c(first,last){}
	//以下操作完全利用Sequence c的操作，完成stack的操作
	bool empty()const {return c.empty();}
	size_type size()const {return c.size();}
	reference top() {return c.back();}
	const_reference top() const {return c.back();}
	void push(const value_type& elem){c.push_back(elem);}
	void pop(){c.pop_back();}

};
template <typename T,typename Sequence>
bool operator==(const MyStack<T,Sequence>& s1,const MyStack<T,Sequence>&s2)
{
	return s1.c==s2.c;
}

template <typename T,typename Sequence>
bool operator<(const MyStack<T,Sequence>& s1,const MyStack<T,Sequence>&s2)
{
	return s1.c<s2.c;
}

int main(int argc, char const *argv[])
{
	MyStack<int> ms1;
	MyStack<int> ms2;
	MyStack<int,list<int>>ms3;

	int a[9]={1,2,3,4,5,6,7,8,9};
	MyStack<int> ms4(a,a+9);


	ms1.push(1);
	ms1.push(2);
	ms1.push(3);
	ms1.push(4);
	ms1.push(5);
	ms1.push(8);
	ms1.push(10);
	cout<<"ms1.size():"<<ms1.size()<<endl;
	ms1.pop();
	cout<<"ms1.top():"<<ms1.top()<<endl;
	ms2.push(-1);
	ms3.push(9);
	if (ms1==ms2)
	{
		cout<<"ms1 and ms2 equality"<<endl;
	}
	else
	{
		cout<<"ms1 and ms2 not equality"<<endl;
	}
	return 0;
}
