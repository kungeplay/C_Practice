// Merge Two Sorted Lists
// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
/**
 * Definition for singly-linked list.
 */
 #include <iostream>
 using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

 		if(l1==NULL)
 			return l2;
 		else if(l2==NULL)
 			return l1;
 		ListNode *head,*p,*q,*r;
 		if(l1->val<l2->val)
 		{
 			p=l1;
 			q=l2;
 		}
 		else
 		{
 			p=l2;
 			q=l1;
 		}
 		head=p;
		while(p->next!=NULL&&q!=NULL)
		{
			if(p->next->val>q->val)
			{
				r=p->next;
				p->next=q;
				p=p->next;
				q=r;
			}
			else
				p=p->next;
		}
		if(q!=NULL)
			p->next=q;

		return head;
    }
};
int main(int argc, char const *argv[])
{
	ListNode *head1=NULL,*head2=NULL,*p,*q;
	for(int i=1;i<=4;i=i+1)
	{
		if(head1==NULL)
		{
			head1=new ListNode(i);
			p=head1;
		}
		else
		{
			p->next=new ListNode(i);
			p=p->next;
		}

	}
	for(int i=2;i<=10;i=i+2)
	{
		if(head2==NULL)
		{
			head2=new ListNode(i);
			p=head2;
		}
		else
		{
			p->next=new ListNode(i);
			p=p->next;
		}

	}
	Solution so;
	ListNode *head=so.mergeTwoLists(head1,head2);
	for(q=head;q!=NULL;)
	{

		cout<<q->val<<"\t";
		ListNode *r=q;
		q=q->next;
		delete r;
	}
	cout<<endl;
	return 0;
}