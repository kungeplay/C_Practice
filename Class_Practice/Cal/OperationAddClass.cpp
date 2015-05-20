#include "OperationAddClass.h"
double OperationAdd::GetResult() 
{
	double result;
	result=GetNumberA()+GetNumberB();
	return result;
}
double OperationAdd::Sum()
{
	return 2.0;
}