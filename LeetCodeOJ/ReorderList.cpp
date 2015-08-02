// Reorder List
// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

// You must do this in-place without altering the nodes' values.

// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}. 
#include <deque>
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
 //我想到这个用STL中的双端队列来解决这个问题，不过这样就简化了这个问题。
 //后来在我网上看看别人，用的思路也和这相似，有的是将链表从中间分成两个链表(可以用两个快慢指针，快指针一次走两步，慢指针一次走1步，
 //这样当快指针指向最后一个节点时，慢指针指向中间节点)，然后，将第二个链表倒序翻转(比如放入栈中)，再合并两个链表。也可得到结果。
class Solution {
public:
	void reorderList(ListNode* head) {
		if(head==NULL)
			return;
		deque<ListNode *> nodeQueue;
		ListNode *p=head->next;
		while(p!=NULL)
		{
			nodeQueue.push_back(p);
			p=p->next;
		}
		p=head;
		while(true)
		{
			if(nodeQueue.size()>0)
			{
				p->next=nodeQueue.back();
				nodeQueue.pop_back();
				p=p->next;
			}
			else
				break;
			if(nodeQueue.size()>0)
			{
				p->next=nodeQueue.front();
				nodeQueue.pop_front();
				p=p->next;
			}
			else
				break;
		}
		p->next=NULL;
	}
};
int main(int argc, char const *argv[])
{
	ListNode *head=new ListNode(1);
	ListNode *q=head;
	for(int i=2;i<=10;++i)
	{
		q->next=new ListNode(i);
		q=q->next;
	}
	q=head;
	while(q!=NULL)
	{
		cout<<q->val<<'\t';
		q=q->next;
	}
	cout<<endl;

	Solution so;
	so.reorderList(head);
	ListNode *p=head;
	while(p!=NULL)
	{
		cout<<p->val<<'\t';
		p=p->next;
	}
	cout<<endl;
	return 0;
}