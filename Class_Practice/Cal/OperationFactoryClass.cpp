
#include "OperationFactoryClass.h"
  Operation* OperationFactory::createOperate(char operate)
{
	Operation * oper=NULL;
	switch (operate)
	{
	case '+':
		oper=new OperationAdd();
		break;
	case '-':
		oper=new OperationSub();
		break;
	case '*':
		oper=new OperationMul();
		break;
	case '/':
		oper=new OperationDiv();
		break;
	}
	return oper;
}