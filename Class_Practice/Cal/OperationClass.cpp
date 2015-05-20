
#include "OperationClass.h"

Operation::Operation():_numberA(0),_numberB(0)
{}
void Operation::SetNumberA(double A)
{
	_numberA=A;
}
double Operation::GetNumberA() const
{
	return _numberA;
}
void Operation::SetNumberB(double B)
{
	_numberB=B;
}
double Operation::GetNumberB() const
{
	return _numberB;
}
double Operation::GetResult()
{
	return 0;
}