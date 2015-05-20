#include <pwd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//使用getpwent函数打印出/etc/passwd文件中各个用户的信息

//getpwnam函数的一个实现,我在main函数中并没有调用这个函数
struct passwd *getpwnam(const char *name)
{
	struct passwd *ptr;
	setpwent();//反绕它所使用的文件
	while((ptr=getpwent())!=NULL)
		if(strcmp(name,ptr->pw_name)==0)//found a match
			break;
	endpwent();//关闭文件,在getpwent查看完口令文件后，一定要调用endpwent关闭这些文件。getpwent知道什么时间应当打开它所使用的文件(第一次被调用时),但是它并不知道何时关闭这些文件。
	return (ptr);//ptr is NULL if no match found
}
//循环打印信息
void printpasswd()
{
	struct passwd * ptr;
	setpwent();
	while((ptr=getpwent())!=NULL)
		printf("name: %-20s\tdir: %-20s\tuid:%-20ld\tgid:%-20ld\n",ptr->pw_name,ptr->pw_dir,ptr->pw_uid,ptr->pw_gid);
	endpwent();
}
int main(int argc,char *argv[])
{
	printpasswd();
}
