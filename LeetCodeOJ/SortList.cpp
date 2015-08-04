// Sort List
// Sort a linked list in O(n log n) time using constant space complexity.

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

 //哎，对我自己都没话说，第一次下归并排序的算法，用了好长时间，在程序员面试宝典上看到：对链表这一特定数据结构而言，最好使用归并排序算法。
 //而堆排序，快速排序这些在数组排序时性能非常好的算法，用在只能顺序访问的链表中却不尽人意，但是归并排序却可以，它不仅保持了O(nlogn)的时间复杂度，
 //而且它的空间复杂度也从O(n)降到了O(1)(在数组中是O(n))，除此之外，归并排序是分治法的实现。
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if(head==NULL)
			return head;
		return mergeSort(head);;
	}
private:
	ListNode *mergeSort(ListNode *head)
	{
		if(head->next!=NULL)
		{
			ListNode *p=head,*q=head,*mid;
			while(q->next!=NULL&&q->next->next!=NULL)//利用fast-slow指针找到中间节点
			{
				p=p->next;
				q=q->next->next;
			}
			mid=p->next;//mid即为中间节点
			p->next=NULL;//将两个一个链表按照中间节点划分为两个链表，每个链表最后节点均指向null
			ListNode * newhead1=mergeSort(head);//递归调用，直到链表就只包含一个节点
			ListNode * newhead2=mergeSort(mid);
			return merge(newhead1,newhead2);//合并两个链表为一个新的链表

		}
		else
			return head;
	}
	ListNode * merge(ListNode* head1,ListNode *head2)
	{
		ListNode *newhead=NULL;
		ListNode *p=head1;
		ListNode *q=head2;
		ListNode *t=NULL;
		while(p!=NULL&&q!=NULL)
		{
			if(p->val<=q->val)
			{
				if(newhead==NULL)
				{
					newhead=p;
					t=newhead;
				}
				else
				{
					t->next=p;
					t=t->next;
				}
				p=p->next;
			}
			else
			{
				if(newhead==NULL)
				{
					newhead=q;
					t=newhead;
				}
				else
				{
					t->next=q;
					t=t->next;
				}
				q=q->next;
			}
		}
		if(p!=NULL)
			t->next=p;
		if(q!=NULL)
			t->next=q;

		return newhead;
	}
};


int main(int argc, char const *argv[])
{
	ListNode *head=new ListNode(3);
	head->next=new ListNode(2);
	head->next->next=new ListNode(5);
	head->next->next->next=new ListNode(8);
	head->next->next->next->next=new ListNode(1);
	head->next->next->next->next->next=new ListNode(7);	
	Solution so;
	ListNode *newhead=so.sortList(head);
	ListNode *p=newhead;
	while(p!=NULL)
	{
		cout<<p->val<<'\t';
		p=p->next;
	}
	cout<<endl;

	return 0;
}