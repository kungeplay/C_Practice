#include <iostream>
/*计算不断的读取到的数据的和，直至没有
 * 新的输入为止
*/
int main()
{
	int sum=0,value=0;
	while(std::cin>>value)
		sum+=value;
	std::cout<<"Sum is:"<<sum<<std::endl;
	return 0;
}
