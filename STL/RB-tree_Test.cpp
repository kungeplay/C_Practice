#include <iostream>
#include <bits/stl_tree.h>
//自己硬是找到了gcc自带的RB-tree，并测试了下成员函数
using namespace std;

template <typename T> T Identity(T t1)
{
	return t1;
}

int main(int argc, char const *argv[])
{
	_Rb_tree<int,int,_Identity<int>,less<int>> itree;
	itree._M_insert_unique(10);
	itree._M_insert_unique(7);
	itree._M_insert_unique(8);
	itree._M_insert_unique(15);
	itree._M_insert_unique(5);
	itree._M_insert_unique(6);
	itree._M_insert_unique(11);
	itree._M_insert_unique(13);
	itree._M_insert_unique(12);
	itree._M_insert_unique(19);
	itree._M_insert_unique(21);
	itree._M_insert_equal(22);
	itree._M_insert_equal(22);
	itree._M_insert_equal(22);
	itree._M_insert_equal(22);
	itree._M_insert_equal(22);
	itree._M_insert_equal(23);	
	_Rb_tree<int,int,_Identity<int>,less<int>>::iterator ite1=itree.begin();	
	_Rb_tree<int,int,_Identity<int>,less<int>>::iterator ite2=itree.end();
	for(;ite1!=ite2;++ite1)
	{
		cout<<*ite1<<"\t";
	}		
	cout<<endl;
	_Rb_tree<int,int,_Identity<int>,less<int>>::iterator ite3=itree.lower_bound(17);
	if (ite3!=itree.end())
	{
		cout<<"lower_bound(17): "<<*ite3<<endl;

	}
	else
		cout<<"no lower_bound(17)"<<endl;

	_Rb_tree<int,int,_Identity<int>,less<int>>::iterator ite4=itree.upper_bound(15);
	if (ite4!=itree.end())
	{
		cout<<"upper_bound(15): "<<*ite4<<endl;

	}
	else
		cout<<"no upper_bound(15)"<<endl;

	auto itepair=itree.equal_range(15);
	cout<<*(itepair.first)<<"\t"<<*(itepair.second)<<endl;

	cout<<"begin() "<<*(itree.begin())<<endl;
	
	_Rb_tree_node_base * baseptr=(ite2._M_node->_M_parent);//我通过这种方式找到了rbtree的根节点。由于root()函数是受保护的，我无法使用
	_Rb_tree_node<int> * ptr=(_Rb_tree_node<int> *)baseptr;
	int * i1= ptr->_M_valptr();
	cout<<"root(): "<<*i1<<endl;
	cout<<*ite2<<endl;//我发现这个值与size()相同,不知道是否巧合，还有待于细究

	_Rb_tree<int,int,_Identity<int>,less<int>>::iterator ite5=--itree.end();	
	cout<<"--end(): "<<*ite5<<endl;
	_Rb_tree_node_base *ptr_current=ite5._M_node;
	
	//下面开始从根节点的右子树中倒着打印节点信息，直到根节点
	for(; ptr_current!=(itree.end())._M_node; ptr_current=ptr_current->_M_parent)
	{
		cout<<"current: "<<*(((_Rb_tree_node<int>*)ptr_current)->_M_valptr())<<"\t";
		 _Rb_tree_node_base *ptr_current_left=ptr_current->_M_left;
		 _Rb_tree_node_base *ptr_current_right=ptr_current->_M_right;
		 if (ptr_current_left!=NULL)
		 {
			 cout<<"left child: "<<*(((_Rb_tree_node<int>*)ptr_current_left)->_M_valptr())<<"\t";		 	
		 }
		 if(ptr_current_right!=NULL)
		 {
		 	cout<<"right child: "<<*(((_Rb_tree_node<int>*)ptr_current_right)->_M_valptr());
		 }
		 cout<<endl;
	}

	cout<<"size: "<<itree.size()<<endl;
	return 0;
}



