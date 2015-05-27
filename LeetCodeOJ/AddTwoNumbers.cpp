// You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
//注意理解题意:342+465=807
//感觉这是我写的最简洁的代码了
#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
  */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    		ListNode *l=nullptr,*p=nullptr;
    		int carry=0;
    		while(l1!=nullptr||l2!=nullptr||carry!=0)//这种方式比较简洁
    		{
    			int temp=carry;
    			if (l1!=nullptr)
    			{
    				temp+=l1->val;
    				l1=l1->next;
    			}
    			if (l2!=nullptr)
    			{
    				temp+=l2->val;
    				l2=l2->next;
    			}
    			carry=temp/10;
    			if (l==nullptr)//不知道这个能简洁不
    			{//若还没有头节点
    				p=new ListNode(temp%10);
    				l=p;
    			}
    			else
    			{
    				p->next=new ListNode(temp%10);
    				p=p->next;
    			}
    		}
    		return l;
    }
};
int main(int argc, char const *argv[])
{
	ListNode *l1=new ListNode(9);
	l1->next=new ListNode(4);
	l1->next->next=new ListNode(3);
	ListNode *l2=new ListNode(5);
	l2->next=new ListNode(6);
	l2->next->next=new ListNode(4);
	Solution so;
	ListNode *rl=so.addTwoNumbers(l1,l2);
	while(rl!=nullptr)
	{
		cout<<rl->val<<"\t";
		rl=rl->next;
	}
	cout<<endl;
	return 0;
}
