//测试学习mysql使用的基础知识
#include <iostream>
#include <string>
#include <mysql.h>
#include<iomanip>
//编译时要使用 $(mysql_config --cflags) $(mysql_config --libs)
using namespace std;
int main(int argc,char *argv[])
{
	MYSQL * con;
	MYSQL_RES *res;
	MYSQL_ROW row;
	MYSQL_FIELD * field=NULL;//字段指针
	int fieldcount;//保存行中列的数量
	string temp;

	//database configuartion
	string dbuser="Liujiakun";
	string dbpasswd="132133";
	string dbip="localhost";
	string dbname="FirstExample";
	string tablename="student";
	int rt;//return value
	int t=0;

	con=mysql_init((MYSQL*)0);

	if(con!=NULL&&mysql_real_connect(con,dbip.c_str(),dbuser.c_str(),dbpasswd.c_str(),NULL,3306/*TCP IP端口*/,NULL/*Unix Socket 连接类型*/,0/*运行成ODBC数据库标志*/))
	{
		if(!mysql_select_db(con,dbname.c_str()))
		{
			cout<<"Select successfully the database!"<<endl;
			con->reconnect=1;
			//temp="select * from "+tablename;
			temp="describe student";
			rt=mysql_real_query(con,temp.c_str(),temp.size());
			if(rt)
			{
				cout<<"Error making query: "<<mysql_error(con)<<endl;
			}
			else
			{
				cout<<temp<<" executed!!!"<<endl;
			}
			res=mysql_store_result(con);//将结果保存在res结构体中
			fieldcount=mysql_num_fields(res);

			for(unsigned int i=0;i<fieldcount;i++)//逐个遍历字段指针，打印出列名
			{
				field=mysql_fetch_field_direct(res,i);
				cout<<setiosflags(ios::left)<<setw(11)<<field->name<<"\t";
			}
			cout<<endl;

			while(row=mysql_fetch_row(res))
			{
				unsigned long *lengths=mysql_fetch_lengths(res);//在行中字段值的长度可以通过调用mysql_fetch_lengths()获得。
				for(t=0;t<fieldcount;t++)//mysql_num_fields(res):获取行中列的数量
				{
					if(row[t]==NULL)//在行中列值为的NULL值由NULL指针指出
						cout<<setiosflags(ios::left)<<setw(11)<<"NULL"<<"\t";
					else if(lengths[t]==0)
						cout<<setiosflags(ios::left)<<setw(11)<<"0"<<"\t";
					else
						cout<<setiosflags(ios::left)<<setw(11)<<row[t]<<"\t";
				}
				cout<<endl;
			}
			
			cout<<"number of rows:"<<mysql_num_rows(res)<<endl;//获得行数
			
			temp="insert into "+tablename+" values('','坤哥','男','1989-11-03')";
			rt=mysql_real_query(con,temp.c_str(),temp.size());
			if(rt)
			{
				cout<<"insert failed: "<<mysql_error(con)<<endl;
			}
			else
			{
				cout<<temp<<"executed!!!"<<endl;
			}

			cout<<"mysql_free_result..."<<endl;
			//释放结果集 关闭数据库
			mysql_free_result(res);
			mysql_close(con);
		}
		else
		{
			cout<<"mysql_select_db failed: "<<mysql_error(con)<<endl;
		}
	}
	else
	{
		cout<<"Unable to connect the database,check your configuration!"<<endl;
	}
}
