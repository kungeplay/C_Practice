#include <iostream>
#include <string>
#include <vector>//使用vector容器
/*
 * 测试一下while(condition)或if(condition)循环中的condition是一
 * 个初始化了的变量声明的验证条件
 */
using std::cout;
using std::cin;
using std::endl;
using std::string;//还有这一个
using std::vector;//这一个别忘了
int main()
{
	int Input=0;
	const vector<string> scores={"F","D","C","B","A","A++"};
	cout<<"请输入成绩:";
	cin>>Input;
	while(int grade=Input)//结果证实循环体是根据grade的值来判断真假的，若grade为0则循环结束
	{
		string lettergrade;
       		if(grade<60)
			lettergrade=scores[0];
		else
			lettergrade=scores[(grade-50)/10];
		cout<<"成绩为:"<<lettergrade<<endl;	
		cout<<"请输入成绩:";
		cin>>Input;
	}
}
