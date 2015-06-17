// Swap Nodes in Pairs
// Given a linked list, swap every two adjacent(相邻; 邻近的，毗邻的; 紧接着的) nodes and return its head.

// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 
/**
 * Definition for singly-linked list.
 */
 #include <iostream>
 using namespace std;
 //注意令指针初值为NULL
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
//1->2->3->4->5->6->7->8 2->1->4->3->6->5->8->7
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
		ListNode *p=NULL,*q=NULL,*r=NULL,*s=NULL,*newhead=NULL;

		if(head==NULL||head->next==NULL)
			return head;
		p=head;
		newhead=p->next;
		while(p->next!=NULL)
		{
			q=p->next;
			r=q->next;

			p->next=r;
			q->next=p;
			if(s!=NULL)
				s->next=q;
			s=p;
			p=r;
			if(p==NULL)
				break;
		}
		return newhead;

    }
};
int main(int argc, char const *argv[])
{
	ListNode *head=NULL,*p=NULL;
	for(int i=1;i<=2;++i)
	{
		if(head==NULL)
		{
			head=new ListNode(i);
			p=head;
		}
		else
		{
			p->next=new ListNode(i);
			p=p->next;
		}

	}

	p=head;
	while(p!=NULL)
	{
		cout<<p->val<<"\t";
		p=p->next;
	}
	cout<<endl;
	Solution so;
	ListNode *newhead=so.swapPairs(head);
	p=newhead;
	while(p!=NULL)
	{
		cout<<p->val<<"\t";
		p=p->next;
	}
	cout<<endl;
	return 0;
}