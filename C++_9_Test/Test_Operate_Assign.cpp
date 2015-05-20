#include <iostream>
#include <list>
#include <deque>
#include <string>
/*
 * 测试一下assign（不支持array）赋值拷贝操作
 *
 */
using std::list;
using std::deque;
using std::cout;
using std::endl;
using std::string;
int main()
{
list<const char *> li={"Hello","World","Liu","Jia","kun","Qianrushi"};//定义list容器,注意类型为const char *
auto lbegin=li.cbegin();
auto lend=li.cend();
while(lbegin!=lend)
{
cout<<*lbegin++<<" ";
}
lbegin=li.cbegin(),lend=li.cend();
cout<<endl;
deque<string> deq;//定义deque容器,//注意类型为string
deq.assign(++lbegin,lend);
cout<<"deq.size()="<<deq.size()<<endl;
for(auto dbegin=deq.begin()+1,dend=deq.end()-1;dbegin!=dend;++dbegin)//迭代器+n或者-n 这些运算只能应用于string,vector,deque和array的迭代器
	cout<<*dbegin<<" ";
cout<<endl;
}
