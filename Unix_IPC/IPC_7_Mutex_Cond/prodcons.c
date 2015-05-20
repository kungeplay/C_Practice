#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//一个简单的多个生产者和单个消费者例子，在这里生产者的数目通过命令行指定。生产物品的数量也由命令行参数指定。多个生产者均向buff数组中存放数据,一个消费者来读取
#define MAXNITEMS 1000000
#define MAXNTHREADS 100

int nitems;	/*read-only by producer and consumer*/
int buff[MAXNITEMS];
struct 
{
	pthread_mutex_t mutex;
	int nput;	/*next index to store,buff数组中下一次存放的元素下标*/
	int nval;	/*next value to store下一次在buff数组中存放的值(0,1,2等)*/
}put=
{
	PTHREAD_MUTEX_INITIALIZER
};

struct
{
	pthread_mutex_t mutex;
	pthread_cond_t cond;//互斥锁用于上锁，条件变量则用于等待。
	int nready;	/*number ready for consumer*/
}nready=
{
	PTHREAD_MUTEX_INITIALIZER,PTHREAD_COND_INITIALIZER
};

void * produce(void * arg);
void * consume(void * arg);


int main(int argc,char * argv[])
{
	int i,nthreads,count[MAXNITEMS];
	pthread_t tid_produce[MAXNTHREADS],tid_consume;

	if(argc!=3)
	{
		printf("usage:prodcons <#items> <#threads>\n");
		exit(1);
	}
	nitems=(atoi(argv[1])<MAXNITEMS?atoi(argv[1]):MAXNITEMS);
	nthreads=(atoi(argv[2])<MAXNTHREADS?atoi(argv[2]):MAXNTHREADS);

      /*create all producers and one consumer*/
	for(i=0;i<nthreads;i++)
	{
		count[i]=0;
		pthread_create(&tid_produce[i],NULL,produce,&count[i]);

	}
	pthread_create(&tid_consume,NULL,consume,NULL);

      /*wait for all producers and consumer*/
	for(i=0;i<nthreads;i++)
	{
		pthread_join(tid_produce[i],NULL);
		printf("count[%d]=%d\n",i,count[i]);

	}
	pthread_join(tid_consume,NULL);
	exit(0);
}

void * produce(void * arg)
{
	for(;;)
	{
		pthread_mutex_lock(&put.mutex);
		if(put.nput>=nitems)
		{
			pthread_mutex_unlock(&put.mutex);
			return (NULL);/*array is full,we're done*/
		}
		buff[put.nput]=put.nval;
		put.nput++;
		put.nval++;
		pthread_mutex_unlock(&put.mutex);
		
		int dosignal;
		pthread_mutex_lock(&nready.mutex);
		dosignal=(nready.nready==0);
		nready.nready++;
		pthread_mutex_unlock(&nready.mutex);

		if(dosignal)
			pthread_cond_signal(&nready.cond);//直到释放互斥锁nready.mutex后才给与之关联的条件变量nready.cond发送信号。为了避免上锁冲突。

		*((int*)arg)+=1;
	}
}

void * consume(void * arg)
{
	int i;
	for(i=0;i<nitems;i++)
	{
		pthread_mutex_lock(&nready.mutex);
		while(nready.nready==0)
		{
			pthread_cond_wait(&nready.cond,&nready.mutex);
		}
		nready.nready--;
		pthread_mutex_unlock(&nready.mutex);
		if(buff[i]!=i)
		{
			printf("buff[%d]=%d\n",i,buff[i]);
		}
	}
	return(NULL);
}
