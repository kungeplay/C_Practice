//OperationClass.h
#ifndef OPERATIONCLASS_H
#define OPERATIONCLASS_H

class Operation
{
private:
	double _numberA;
	double _numberB;
public:
	Operation();
	void SetNumberA(double A);
	double GetNumberA() const;
	void SetNumberB(double B);
	double GetNumberB() const;
	virtual double GetResult();
};
#endif