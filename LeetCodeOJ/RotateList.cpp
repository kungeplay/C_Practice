// Rotate List
// Given a list, rotate the list to the right by k places, where k is non-negative.

// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

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
 //这个题不算难，STL源码剖析上有类似的算法，嘿嘿，我好像没有用
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    		if(k==0||head==NULL||head->next==NULL)
    			return head;
    		ListNode * p=head,*q=head;
    		int i=0;
    		while(q->next!=NULL)
    		{
    			if(i>=k)
    			{
    				p=p->next;
    			}
    			++i;
    			q=q->next;
    		}
    		if(i<k)
    		{
    			if(k%(i+1)==0)
    				return head;
    			else
    				return rotateRight(head,k%(i+1));
    		}
    		ListNode *newhead=p->next;
    		q->next=head;
    		p->next=NULL;
    		return newhead;
    }
};
int main(int argc, char const *argv[])
{
	ListNode *head=NULL,*p=NULL;
	for(int i=1;i<6;++i)
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
	Solution so;
	ListNode *newhead=so.rotateRight(head,11);
	for(ListNode *p=newhead;p!=NULL;p=p->next)
	{
		cout<<p->val<<'\t';
	}
	cout<<endl;
	return 0;
}