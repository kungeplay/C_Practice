#include <iostream>
using namespace std;
//随便写的
template <typename T>
class SquareMatrixBase
{
public:
	SquareMatrixBase(std::size_t* n,T*pMem):size(n),pData(pMem){ cout<<size<<endl;}
	void setDataPtr(T*ptr){pData=ptr;}
	int getDataNum(){ return *size;}
private:
	std::size_t *size;
	T*pData;
};

template<typename T,std::size_t n>
class SquareMatrix:private SquareMatrixBase<T>
{
private:
	T data[n*n];
	std::size_t nn=5;	
public:
	SquareMatrix():SquareMatrixBase<T>(&nn,data){cout<<&nn<<endl;}

	using SquareMatrixBase<T>::getDataNum;

	int getDataNum(int i){ return getDataNum();}
	void setDataNum(const int elem){nn=elem;}

};
int main(int argc, char const *argv[])
{
	SquareMatrix<int,5> Square;
	Square.setDataNum(8);
	std::cout<<Square.getDataNum(5)<<endl;
	return 0;
}