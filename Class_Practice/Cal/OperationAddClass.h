#include "OperationClass.h"

#ifndef OPERATIONADDCLASS_H
#define OPERATIONADDCLASS_H
class OperationAdd:public Operation
{
public:
	double Sum();
	double GetResult() ;//override;
};
#endif