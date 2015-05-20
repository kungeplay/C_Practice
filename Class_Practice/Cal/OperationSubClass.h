#include "OperationClass.h"
#ifndef OPERATIONSUBCLASS_H
#define OPERATIONSUBCLASS_H

class OperationSub:public Operation
{
	public:
		double GetResult() ;//override;
};
#endif