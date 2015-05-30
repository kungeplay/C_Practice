#include <iostream>
#include <vector>
#include <algorithm>		//heap algorithms
using namespace std;

int main(int argc, char const *argv[])
{
	int ia[9]={0,1,2,3,4,8,9,3,5};
	std::vector<int> ivec(ia,ia+9);

	for(auto i : ivec)
		cout<<i<<"\t";
	cout<<endl;

	make_heap(ivec.begin(),ivec.end());//将一段现有的数据转化为一个heap。
	for(auto i:ivec)
		cout<<i<<"\t";
	cout<<endl;

	ivec.push_back(7);
	for(auto i:ivec)
		cout<<i<<"\t";
	cout<<endl;

	push_heap(ivec.begin(),ivec.end());//push_heap算法 前提条件：新加入的元素一定要放在最下一层作为叶节点。并填补在由左至右的第一个空格
	for(auto i :ivec)
		cout<<i<<"\t";
	cout<<endl;

	pop_heap(ivec.begin(),ivec.end());//pop_heap算法，取走根节点设置至底部容器的尾端节点后，割舍最下层最右边的叶节点，并将其值重新安插至max-heap.
	cout<<ivec.back()<<endl;
	ivec.pop_back();

	for(auto i: ivec)
		cout<<i<<"\t";
	cout<<endl;

	sort_heap(ivec.begin(),ivec.end());//对堆排序算法，实现由小到大的序列，排序后，原来的heap就不再是一个合法的heap了。
	for(auto i:ivec)
		cout<<i<<"\t";
	cout<<endl;

	return 0;
}
