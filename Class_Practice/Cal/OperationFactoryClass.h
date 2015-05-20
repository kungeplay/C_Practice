#ifndef OPERATIONFACTORYCLASS_H
#define OPERATIONFACTORYCLASS_H
#include <string>
#include "OperationClass.h"
#include "OperationAddClass.h"
#include "OperationSubClass.h"
#include "OperationMulClass.h"
#include "OperationDivClass.h"
class OperationFactory
{
	public:
		 static Operation*  createOperate(char Operation);
};
#endif