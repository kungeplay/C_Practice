#include <iostream>
#include <stdlib.h>
//条款49：了解new-handler的行为
//当operator new无法满足某一内存分配需求时，它会抛出异常.
//set_new_handler的参数是个指针，指向operator new无法分配足够内存时该被调
//用的函数。其返回值也是个指针，指向set_new_handler被调用前正在执行(但马上就要被替换)的那个new-handler函数.
using namespace std;
void OutOfMem()
{
	std::cerr<<"Unable to satisfy reuest for memory\n";
	abort();
}
int main(int argc, char const *argv[])
{
	std::set_new_handler(OutOfMem);
	int * pBigDataArray=new int[1000000000000000000];
	return 0;
}
