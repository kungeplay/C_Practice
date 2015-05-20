//一个简单的函数模板的定义与使用
#ifndef FUNCTION_TEMPLATE_H
#define FUNCTION_TEMPLATE_H 
template <typename T>
int compare(const T &v1,const T &v2)
{
	if(v1<v2) return -1;
	if(v2<v1) return 1;
	return 0;
}
#endif
