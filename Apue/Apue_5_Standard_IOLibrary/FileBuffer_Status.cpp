#include <stdio.h>
#include <stdlib.h>

//此程序为3个标准流以及一个与普通文件相关联的流打印有关缓冲的状态信息	
void pr_stdio(const char *,FILE *);
int is_unbuffered(FILE *);
int is_linebuffered(FILE *);
int buffer_size(FILE *);

int main(int argc, char const *argv[])
{
	FILE * fp;
	fputs("enter any character\n",stdout);
	if (getchar()==EOF)
	{
		fputs("getchar error\n",stderr);
		exit(1);
	}
	fputs("one line to standard error\n",stderr);

	pr_stdio("stdin",stdin);
	pr_stdio("stdout",stdout);
	pr_stdio("stderr",stderr);

	if ((fp=fopen("/etc/passwd","r"))==NULL)
	{
		fputs("fopen error",stderr);
		exit(1);
	}

	if (getc(fp)==EOF)
	{
		fputs("getc error",stderr);
		exit(1);
	}
	pr_stdio("/etc/passwd",fp);
	return 0;
}

void pr_stdio(const char *name,FILE *fp)
{
	printf("stream = %s, ",name );
	if (is_unbuffered(fp))
	{
		printf("unbuffered");
	}
	else if (is_linebuffered(fp))
	{
		printf("line buffered");
	}
	else
		printf("fully buffered");

	printf(", buffer size =%d\n",buffer_size(fp));
}


int is_unbuffered(FILE *fp)
{
	return(fp->_flags & _IO_UNBUFFERED);
}

int is_linebuffered(FILE *fp)
{
	return (fp->_flags & _IO_LINE_BUF);
}

int buffer_size(FILE *fp)
{
	return(fp->_IO_buf_end-fp->_IO_buf_base);
}
