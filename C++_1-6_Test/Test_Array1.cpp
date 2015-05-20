#include <iostream>
#include <iterator>
using namespace std;
int main()
{
int j[5]={0,1,2,3,4};
int *beg=begin(j);
int *fin=end(j);
while(beg!=fin)
	cout<<*beg++<<endl;
return 0;
}
