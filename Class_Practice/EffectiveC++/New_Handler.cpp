#include <iostream>
#include <stdlib.h>
// #include <new>
//条款49：了解new-handler的行为
//当operator new无法满足某一内存分配需求时，它会抛出异常.
//set_new_handler的参数是个指针，指向operator new无法分配足够内存时该被调
//用的函数。其返回值也是个指针，指向set_new_handler被调用前正在执行(但马上就要被替换)的那个new-handler函数.
//注意当operator new无法满足内存申请时，它会不断调用new-handler函数，直到找到足够内存。
//因此一个设计良好的new-handler函数必须做以下事情：1.让更多内存可被使用；2.安装另一个new-handler；3.卸除new-handler;4.抛出bad_alloc(或派生自bad_alloc)的异常；
//5. 不返回；
using namespace std;
void OutOfMem()//
{
	std::cerr<<"Unable to satisfy reuest for memory\n";
	//abort();
	throw std::bad_alloc();
}
int main(int argc, char const *argv[])
{
	//下面两部分代码要注释其中一方
	 std::set_new_handler(OutOfMem);
	 int * pBigDataArray1=new int[1000000000000000000];
	
 
	// std::set_new_handler(0);
	// int * pBigDataArray2=new(nothrow) int[1000000000000000000];//默认情况下如果不在new参数中添加加nothrow，则直接抛出异常,退出程序执行.
	// if (pBigDataArray2==0)
	// {
	// 	std::cerr<<"out of memory"<<endl;
	// }
	return 0;
}
