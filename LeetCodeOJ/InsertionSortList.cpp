// Insertion Sort List
// Sort a linked list using insertion sort.

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

 //好吧，这题我做的有点失误了，以为没有返回值呢，直到后来才知道。链表的插入排序，与顺序表的插入排序相反，从头指针所指节点开始向后比
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if(head==NULL||head->next==NULL)
			return head;
		ListNode *p=head->next;
		ListNode *q=head;
		while(p!=NULL)
		{
			if(p->val<head->val)//如果比第一个节点还小，则交换，我失误了，以为只能通过函数参数返回值呢，所以如果比头节点还小，就交换了。
			{
				int tmp=head->val;
				head->val=p->val;
				p->val=tmp;
			}
			ListNode *t=head;
			while(t->next!=p&&t->next->val<=p->val)//从第二个节点开始可以插入排序
			{
				t=t->next;
			}
			if(t->next!=p)
			{
				q->next=p->next;
				p->next=t->next;
				t->next=p;
				p=q->next;
			}
			else
			{
				q=p;
				p=p->next;
			}
		}
		return head;
	}
};

int main(int argc, char const *argv[])
{
	ListNode *head=new ListNode(3);
	head->next=new ListNode(2);
	head->next->next=new ListNode(5);
	head->next->next->next=new ListNode(8);
	head->next->next->next->next=new ListNode(1);
	Solution so;
	so.insertionSortList(head);
	ListNode *p=head;
	while(p!=NULL)
	{
		cout<<p->val<<'\t';
		p=p->next;
	}
	cout<<endl;
	return 0;
}