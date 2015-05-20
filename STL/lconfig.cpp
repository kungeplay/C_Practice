//file:lconfig.cpp
//test configurations defined in <stl_config.h>
#include <vector> //which included <stl_algobase.h>, and then <stl_config.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
# if defined(__sgi)
	cout<<"_sgi"<<endl;	//none!
#endif
	
#if defined(__GNUC__)
	cout<<"__GNUC__"<<endl;	//__GNUC__
	cout<< __GNUC__ <<' '<<__GNUC_MINOR__<<endl;
	cout<<__GLIBC__<<endl;	//__GLIBC__ undeclared
#endif

	//case 2
#ifdef __STL_NO_DRAND48
	cout<<"__STL_NO_DRAND48 defined"<<endl;
#else
	cout<<"__STL_NO_DRAND48 undefined"<<endl;
#endif

	//case 3
#ifdef __STL_STATIC_TEMPLATE_MEMBER_BUG
	cout<<"__STL_STATIC_TEMPLATE_MEMBER_BUG defined"<<endl;
#else
	cout<<"__STL_STATIC_TEMPLATE_MEMBER_BUG undefined"<<endl;
#endif
	//case 5
#ifdef __STL_CLASS_PARTIAL_SPECIALIZATION
	cout<<"__STL_CLASS_PARTIAL_SPECIALIZATION defined"<<endl;
#else
	cout<<"__STL_CLASS_PARTIAL_SPECIALIZATION undefined"<<endl;
#endif
	return 0;
}
