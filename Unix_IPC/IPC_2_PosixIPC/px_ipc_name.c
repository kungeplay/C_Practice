#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATH_MAX 1024
#define POSIX_IPC_PREFIX "/tmp/"
//此程序为2.2节的一个例子，为定位Posix IPC名字而添加上正确的前缀目录,感觉没有什么用
char * px_ipc_name(const char *name)
{
	char *dir,*dst,*slash;
	if((dst=(char *)malloc(PATH_MAX))==NULL)
		return (NULL);
		/*can override default directory with environment variable*/
	if((dir=getenv("PX_IPC_NAME"))==NULL)
	{
#ifdef POSIX_IPC_PREFIX
		dir=POSIX_IPC_PREFIX;
#else 
		dir="/tmp/";//default
#endif
	}
	//dir must end in a slash
	slash=(dir[strlen(dir)-1]=='/')?"":"/";
	snprintf(dst,PATH_MAX,"%s%s%s",dir,slash,name);
	return (dst);//caller can free() this pointer
}

int main(int argc,char * argv[])
{
	printf("%s\n",px_ipc_name("test"));
}
