// Cal.cpp : 定义控制台应用程序的入口点。
//这个文件夹内的程序是我根据大话设计模式，用类的各种特性实现出的一个简单计算器
//简单工厂模式，用一个单独的类来做这个创造实例的过程，这就是工厂。在此程序中单独的类是指OperationFactory类
//通过测试，发现这个版本的GCC 对override不支持
#include <iostream>
#include "OperationFactoryClass.h"

int main(int argc, char * argv[])
{
	Operation *oper;
	oper=OperationFactory::createOperate('/');
	oper->SetNumberA(30);
	oper->SetNumberB(20);
	std::cout<<oper->GetResult()<<std::endl;
	return 0;
}

