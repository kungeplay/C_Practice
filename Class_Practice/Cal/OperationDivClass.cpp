
#include "OperationDivClass.h"
double OperationDiv::GetResult()
{
	if (GetNumberB()==0)
	{
		return -1;
	}
	return GetNumberA()/GetNumberB();
}