#include <iostream>
//条款34
//pure virtual函数必须在derived classes中重新声明，但它们也可以拥有自己的实现。
using namespace std;

class Airport
{
public:
	Airport(const string &s):airportname(s){};
	// ~Airport();
	const string & getPortName() const
	{
		return airportname;
	}
private:
	string airportname;
	
};

class Airplane
{
public:
	// Airplane();
	// ~Airplane();
	virtual void fly(const Airport & destination)=0;//pure virtual函数
	
};
void Airplane::fly(const Airport & destination)//父类中的pure virtual函数自己的实现
{
	cout<<destination.getPortName()<<endl;
}


class ModelA:public Airplane
{
 public:
	// ModelA();
	// ~ModelA();
	virtual void fly(const Airport &destination);
	
};
void ModelA::fly(const Airport &destination)//子类必须实现父类的pure virtual函数.
{
	cout<<"ModelA::fly to"<<destination.getPortName()<<endl;
}

class ModelB:public Airplane
{
 public:
// 	ModelB();
// 	~ModelB();
 	virtual void fly(const Airport &destination);
};
void ModelB::fly(const Airport &destination)
{
	cout<<"ModelB::fly to"<<destination.getPortName()<<endl;
}

class ModelC:public Airplane
{
public:
	// ModelC();
	// ~ModelC();
	virtual void fly(const Airport &destination);
	
};
void ModelC::fly(const Airport &destination)
{
	Airplane::fly(destination);//子类必须这样才能访问到父类已经实现的pure virtual函数
}


int main(int argc, char const *argv[])
{
	Airport port("Beijing");
	ModelA a;
	ModelB b;
	ModelC c;
	a.Airplane::fly(port);
	a.fly(port);
	b.fly(port);
	c.fly(port);
	return 0;
}
