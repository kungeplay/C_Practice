#include <iostream>
using namespace std;
//条款49，在类中重载了new操作符。但在这里并没有完全重载,可以看P249和P253页重载方法
//这个代码其实写的并不完整，可以参见条款50，51部分.
//类NewHandlerHolder的作用是保存旧的new_handler，然后在析构函数中恢复,比较方便
class NewHandlerHolder
{
public:
	explicit NewHandlerHolder(std::new_handler nh):handler(nh)
	{
		std::cout<<"NewHandlerHolder"<<std::endl;
	}
	~NewHandlerHolder()
	{
		std::cout<<"~NewHandlerHolder"<<std::endl;
		std::set_new_handler(handler);
	}
private:
	std::new_handler handler;
	NewHandlerHolder(const NewHandlerHolder &)=delete;
	NewHandlerHolder & operator =(const NewHandlerHolder &)=delete;
};

//CRTP技术,用以支持class专属的set_new_handler
template <typename T>
class NewHandlerSupport
{
public:
	NewHandlerSupport()
	{ 	
		std::cout<<"NewHandlerSupport"<<std::endl;
	}
	virtual ~NewHandlerSupport()
	{
		std::cout<<"~NewHandlerSupport"<<std::endl;
	}
	static std::new_handler set_new_handler(std::new_handler p) throw();
	static void * operator new(std::size_t size) throw(std::bad_alloc);
	
private:
	static std::new_handler currentHandler;
};
template<typename T> std::new_handler NewHandlerSupport<T>::set_new_handler(std::new_handler p) throw()
{
	std::new_handler oldHandler=currentHandler;
	currentHandler=p;
	return oldHandler;
}
template<typename T> void * NewHandlerSupport<T>::operator new(std::size_t size) throw(std::bad_alloc)
{
	std::cout<<"NewHandlerSupport<T> new \tsize="<<size<<"\tsizeof(NewHandlerSupport<T>)="<<sizeof(NewHandlerSupport<T>)<<std::endl;
	NewHandlerHolder h(std::set_new_handler(currentHandler));
	void *p= ::operator new(size);//这种方式new并不调用构找函数
	cout<<"---"<<endl;
	return p;
}
template <typename T> std::new_handler NewHandlerSupport<T>::currentHandler=0;


class Widget:public NewHandlerSupport<Widget>
{
public:
	Widget()
	{

		std::cout<<"Widget\t"<<sizeof(Widget)<<std::endl;
	}
	~Widget()
	{
		std::cout<<"~Widget"<<std::endl;
	}
	int w;
};


void outOfMem()
{
	std::cerr<<"Unable to satisfy request for memory\n"<<std::endl;
	std::abort();
}


int main(int argc, char const *argv[])
{
	NewHandlerSupport<Widget>::set_new_handler(outOfMem);
	Widget *p=new Widget;
	delete p;
	return 0;
}
