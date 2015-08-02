// Linked List Cycle II

// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

// Follow up:
// Can you solve it without using extra space? 
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
//第一次碰到求有环链表的环起始节点，察，这个题竟然有个公式，若两链表有环，则设一次走一步的指针stepOne与一次走两步的指针stepTwo相遇，此时stepOne
//跳过了x+y个节点，stepTwo跳过了x+y+z+y个节点(y和z是环内的节点个数)，则有2(x+y)=x+y+z+y ===>x=z,
//若快指针绕环走了好几圈的具体解释见http://www.cnblogs.com/x1957/p/3406448.html
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if(head==NULL||head->next==NULL||head->next->next==NULL)
			return NULL;
		ListNode *stepOne=head->next;
		ListNode *stepTwo=head->next->next;
		while(stepTwo->next!=NULL&&stepTwo->next->next!=NULL)
		{
			if(stepTwo==stepOne)//若链表有环，则两个指针一定有机会指向同一个节点
			{
				stepOne=head;//此时，将其中一个指针指向链表头节点，然后两个指针，每次各走一步，一定能相遇，相遇节点即为链表开始处。
				while(stepOne!=stepTwo)
				{
					stepOne=stepOne->next;
					stepTwo=stepTwo->next;
				}
				return stepOne;
			}
			stepTwo=stepTwo->next->next;
			stepOne=stepOne->next;
		}
		return NULL;		
	}
};
int main(int argc, char const *argv[])
{
	ListNode * head=new ListNode(1);
	head->next=new ListNode(2);
	// head->next->next=new ListNode(3);
	// head->next->next->next=new ListNode(4);
	// head->next->next->next->next=new ListNode(5);
	// head->next->next->next->next->next=head;
	Solution so;
	ListNode *node=so.detectCycle(head);
	if(node!=NULL)
		cout<<node->val<<endl;
	else
		cout<<"no cycle!"<<endl;
	return 0;
}
