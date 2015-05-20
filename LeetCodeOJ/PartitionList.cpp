// Given a linked list and a value x, partition(分开，隔开) it such that all nodes less than x come before nodes greater than or equal to x.
// You should preserve(保鲜;保持原状) the original relative order of the nodes in each of the two partitions.
// For example,
// Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5. 

 // Definition for singly-linked list.

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}; 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *shead=nullptr,*slist=nullptr,*bhead=nullptr,*blist=nullptr, *p=head;
        while(p!=nullptr)
        {
        		if(p->val<x)
        		{
        			if (shead==nullptr)//建立链表的这个地方指针总出现问题，以后要加强练习额
        			{
        				shead=slist=new ListNode(p->val);
        			}
        			else{
        				slist->next=new ListNode(p->val);//我总是不小心建立了断开的链表
        				slist=slist->next;
        			}         			
        		}
        		else
        		{
        			if (bhead==nullptr)
        			{
        				bhead=blist=new ListNode(p->val);
        			}
        			else{
        				blist->next=new ListNode(p->val);
        				blist=blist->next;
        			}
        		}
        		p=p->next;
        }       
        if (shead!=nullptr)
        {
        		slist->next=bhead;
        		return shead;
        }
        else
        {
        		return bhead;
        }
    }
};

void visitListNode(ListNode *rs)
{
	for (ListNode *p=rs;p!=nullptr;p=p->next)
	{
		cout<<p->val<<"\t";
	}
	cout<<endl;	
}

int main(int argc, char const *argv[])
{
	Solution so;
	ListNode  *ln=new ListNode(1);
	ln->next=new ListNode(4);
	ln->next->next=new ListNode(3);
	ln->next->next->next=new ListNode(2);
	ln->next->next->next->next=new ListNode(5);
	ln->next->next->next->next->next=new ListNode(2);
	ListNode * rs=so.partition(ln,4);
	visitListNode(rs);
	return 0;
}
