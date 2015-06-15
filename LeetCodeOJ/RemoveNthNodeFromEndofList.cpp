// Remove Nth Node From End of List
// Given a linked list, remove the nth node from the end of list and return its head.

// For example,

//    Given linked list: 1->2->3->4->5, and n = 2.

//    After removing the second node from the end, the linked list becomes 1->2->3->5.

// Note:
// Given n will always be valid.
// Try to do this in one pass. 
/**
 * Definition for singly-linked list.
 */
 #include <iostream>
 using namespace std;
//应该是以前碰到过类似这种的题吧，但是这个题是有诀窍的，也要仔细看一看，令一个指针指向要删除的节点，一个指针指向之前的那个节点，感觉这个题不算难
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * p=head,*q=head,*t=NULL;
        int i=1;
        if(head==NULL)
            	return NULL;
        while(q->next!=NULL)
        {
            q=q->next;
            ++i;
            if(i>=n+1)
            {
                if(t==NULL)
                    t=p;
                else
                    t=t->next;
                p=p->next;
            }
        }
        if(i<=n)
        {
            	ListNode *d=head;
            	head=head->next;
            	delete d;
        }
        else
        {
            t->next=p->next;
            delete p;
        }
        return head;
    }
};
int main(int argc, char const *argv[])
{
	ListNode *head=new ListNode(1);
	int len=3;
	ListNode * q=head;
	for(int i=2;i<=len;++i)
	{
		ListNode * p=new ListNode(i);
		q->next=p;
		q=p;
	}
	Solution so;
	q=so.removeNthFromEnd(head,3);
	// q=head;
	while(q!=NULL)
	{
		cout<<q->val<<"\t";
		q=q->next;
	}
	cout<<endl;
	return 0;
}
