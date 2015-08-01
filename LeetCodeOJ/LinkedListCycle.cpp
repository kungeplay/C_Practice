// Linked List Cycle
// Given a linked list, determine if it has a cycle in it.

// Follow up:
// Can you solve it without using extra space? 

#include <iostream>
using namespace std;

/*
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
  //这个判断单链表中是否存在环的题不难
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if(head==NULL)
			return false;
		ListNode *stepOne=head,*stepTwo=head;
		while(stepTwo->next!=NULL&&stepTwo->next->next!=NULL)
		{
			if(stepTwo->next==stepOne||stepTwo->next->next==stepOne)
				return true;
			stepTwo=stepTwo->next->next;
			stepOne=stepOne->next;
		}
		return false;
	}
};

int main(int argc, char const *argv[])
{
	ListNode * head=new ListNode(1);
	head->next=new ListNode(2);
	head->next->next=new ListNode(3);
	head->next->next->next=new ListNode(4);
	head->next->next->next->next=new ListNode(5);
	head->next->next->next->next->next=head->next->next->next->next;
	Solution so;
	cout<<so.hasCycle(head)<<endl;
	return 0;
}