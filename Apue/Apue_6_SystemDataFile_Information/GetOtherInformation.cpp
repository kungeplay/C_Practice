#include <stdio.h>
#include <sys/utsname.h>
#include <stdlib.h>//malloc,free
#include <time.h>
//通过uname函数获取系统标识,然后通过几个时间函数，获取本地的时间，并按照格式打印在字符串里
int main(int argc,char * argv[])
{
	struct utsname * nameptr;
	time_t timeseconds;
	struct tm * nowtm;
	char timebuf[60];


	nameptr=(struct utsname *)malloc(sizeof(struct utsname));
	if(uname(nameptr)!=-1)//获取与主机和操作系统有关的信息
		printf("sysname: %s\tnodename: %s\trelease: %s\tversion: %s\t machine: %s\n",nameptr->sysname,nameptr->nodename,nameptr->release,nameptr->version,nameptr->machine);
	else
		perror("uname failed");

	if(time(&timeseconds)!=-1)
		printf("now time:自公元1970年1月1日00:00:00已经过的秒数--%ld\n",(long)timeseconds);

	//注意struct tm结构体中的tm_year表示的是years since 1900,tm_mon表示的是months since January:[0-11]
	if((nowtm=gmtime(&timeseconds))!=NULL)
		printf("tm_year:%d\ttm_mon:%d\ttm_mday:%d\ttm_hour:%d\ttm_min:%d\ttm_sec:%d\ttm_wday:%d\ttm_yday:%d\ttm_isdst:%d\n",nowtm->tm_year,nowtm->tm_mon,nowtm->tm_mday,nowtm->tm_hour,nowtm->tm_min,nowtm->tm_sec,nowtm->tm_wday,nowtm->tm_yday,nowtm->tm_isdst);
	else
		perror("gmtime failed");

	if((nowtm=localtime(&timeseconds))!=NULL)
		printf("tm_year:%d\ttm_mon:%d\ttm_mday:%d\ttm_hour:%d\ttm_min:%d\ttm_sec:%d\ttm_wday:%d\ttm_yday:%d\ttm_isdst:%d\n",nowtm->tm_year+1900,nowtm->tm_mon+1,nowtm->tm_mday,nowtm->tm_hour,nowtm->tm_min,nowtm->tm_sec,nowtm->tm_wday,nowtm->tm_yday,nowtm->tm_isdst);
	else
		perror("localtime failed");
	
	//把时间按照指定格式打印在字符串里
	if(strftime(timebuf,sizeof(timebuf),"%G年 %m月 %d日 %A %T %Z",nowtm)!=0)
		printf("%s\n",timebuf);
	else
		perror("strftime failed");


	free(nameptr);
	return 0;

}
