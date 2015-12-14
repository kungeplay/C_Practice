#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
//测试以下创建目录的例子
int main(int argc,char *argv[])
{
	mode_t dirMode=S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP;//创建的目录具有的权限，注意执行权限必须具备
	if(argc!=2)
	{
		printf("Usage:%s DirectoryName\n",argv[0]);
		return -1;
	}
	if(mkdir(argv[1],dirMode)==-1)
	{
		perror("Create directory failed!");
		printf("errno=%d\n",errno);	//若目录存在则errno值为17
		return -1;
	}
	printf("Create directory successfully!\n");
	return 0;	
}
