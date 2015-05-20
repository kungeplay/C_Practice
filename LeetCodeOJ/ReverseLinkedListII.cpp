 //Reverse a linked list from position m to n. Do it in-place and in one-pass.
//For example:
//Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//return 1->4->3->2->5->NULL.
//Note:
//Given m, n satisfy the following condition:
//1 ≤ m ≤ n ≤ length of list. 
 //感觉这个题的主要难点是临界条件的判断
#include <iostream>


 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
		ListNode * q,*t,*p;
		q=t=head;
		p=NULL;
		if (m>=n||m<1)
		{
			return head;
		}
		//找到第m和第n个元素的位置		
		for (int i = 1,j=1; i < n; ++i)
   		{
   			if (j<m)
   			{
   				p=q;
   				q=q->next;
   			}
   			t=t->next;
   			if(t==NULL)
   				return head;   			
		   	j++;		
   		}
   		ListNode *r,*f;
   		r=t->next;
   		while(q->next!=t)
   		{
   			f=q->next;
   			q->next=r;
   			r=q;
   			q=f;
   		}   		
   		q->next=r;
   		t->next=q;
   		if (p==NULL)//若m=1，则p此时为空，链表头元素应为t；
   		{
   			head=t;
   		}
   		else
   			p->next=t;   		
   		return head;
    }
};
int main(int argc, char const *argv[])
{
	ListNode * head=new ListNode(1);
	ListNode * t=head;
	for (int i = 2; i < 3; ++i)
	{
		ListNode * m=new ListNode(i);
		t->next=m;
		t=m;
	}
	Solution s;
	head=s.reverseBetween(head,1,2);
	for (ListNode *ph=head; ph!=NULL; ph=ph->next)
	{
		std::cout<<ph->val<<"\t";
	}
	std::cout<<std::endl;
	return 0;
}