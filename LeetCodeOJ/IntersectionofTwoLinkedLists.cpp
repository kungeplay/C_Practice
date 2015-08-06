/*
Intersection of Two Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:

    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.

Credits:
Special thanks to @stellari for adding this problem and creating all test cases.
*/

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
 //剑指offer上的一个题，记住剑指offer上的方法的话，就不难。
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

		if(headA==NULL||headB==NULL)
			return NULL;

		int nA=0;
		int nB=0;
		ListNode *p=headA;
		ListNode *q=headB;
		while(p!=NULL)
		{
			++nA;
			p=p->next;
		}
		while(q!=NULL)
		{
			++nB;
			q=q->next;
		}
		int dist=nA-nB;
		p=headA;
		q=headB;
		if(dist>0)
		{
			while(dist!=0)
			{
				p=p->next;
				--dist;
			}
		}
		else
		{
			while(dist!=0)
			{
				q=q->next;
				++dist;
			}
		}
		while(p!=NULL&&q!=NULL&&p!=q)
		{
			p=p->next;
			q=q->next;
		}
		if(p==NULL||q==NULL)
			return NULL;
		else
			return p;
	}
};

int main(int argc, char const *argv[])
{
	ListNode *p=new ListNode(4);
	p->next=new ListNode(5);
	p->next->next=new ListNode(6);

	ListNode *headA=new ListNode(1);
	headA->next=new ListNode(2);
	headA->next->next=new ListNode(3);
	headA->next->next->next=p;

	ListNode *headB=new ListNode (8);
	headB->next=new ListNode(9);
	headB->next->next=p;

	Solution so;
	ListNode *q=so.getIntersectionNode(headA,headB);
	cout<<q->val<<endl;
	return 0;
}