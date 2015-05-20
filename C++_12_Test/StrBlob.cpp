#include <iostream>
#include <vector>
#include <memory>
//智能指针定义StrBlob类
using namespace std;

class StrBlob
{
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	explicit StrBlob(std::initializer_list<std::string> il);
	size_type size() const {return data->size();}
	bool empty() const {return data->empty();}
	//~StrBlob();
	//add and delete elems
	void push_back(const std::string &t){data->push_back(t);}
	void pop_back();
	int shared_num(){return data.use_count();}
	//visit elems
	std::string &front();
	const std::string &front() const;//重载const
	std::string &back();
	const std::string &back() const;//重载const
private:
	std::shared_ptr<std::vector<std::string>> data;

	void check(size_type i,const std::string &msg) const;
};
StrBlob::StrBlob():data(make_shared<vector<string>>()){}
StrBlob::StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)){}
void  StrBlob::check(size_type i,const std::string &msg) const
{
	if (i>=data->size())
	{
		throw out_of_range(msg);
	}
}
string & StrBlob::front()//下面这种方法比较好
{
	return const_cast<string &>(const_cast<const StrBlob &>(*this).front());
}
const string & StrBlob::front() const
{
	check(0,"Error: front on empty StrBlob");
	return data->front();	
}

string & StrBlob::back()
{
	return const_cast<string &>(const_cast<const StrBlob &>(*this).back());
}

const string & StrBlob::back() const
{
	check(0,"Error: back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0,"Error: pop_back on empty StrBlob");
	data->pop_back();
}

int main(int argc, char const *argv[])
{
	StrBlob s({"123","456","789"});
	StrBlob d=s;//d和s在底层共享同样的shared_ptr智能指针,因此s变,d也变
	s.front()="qwe";
	cout<<s.front()<<"\t"<<s.back()<<endl;
	cout<<d.front()<<"\t"<<d.back()<<endl;
	cout<<"共享的智能指针数为:"<<s.shared_num()<<endl;
	StrBlob t;
	try
	{
		cout<<t.front()<<endl;
	}
	catch (exception &myobje)
	{
		cout<<myobje.what()<<endl;
	}
	return 0;
}
