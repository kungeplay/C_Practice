// Remove Duplicates from Sorted List
//  Given a sorted linked list, delete all duplicates such that each element appear only once.
// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3. 

 //Definition for singly-linked list.
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    		ListNode *rehead=nullptr,*relist=nullptr,*p=head;
    		int currentval;
    		while(p!=nullptr)
    		{

    			if (rehead==nullptr)
    			{
    				currentval=p->val;
    				rehead=relist=new ListNode(p->val);
    			}
    			else if(currentval<p->val)
			{
				currentval=p->val;    					
				relist->next=new ListNode(p->val);
				relist=relist->next;
    			}
    			else if(currentval>p->val)//注意此处的判断是否符合条件
    				return nullptr;
    			p=p->next;
    		}
    		return rehead;
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
	ln->next=new ListNode(1);
	ln->next->next=new ListNode(3);
	ln->next->next->next=new ListNode(3);
	ln->next->next->next->next=new ListNode(5);
	ln->next->next->next->next->next=new ListNode(6);
	ListNode * rs=so.deleteDuplicates(ln);
	visitListNode(rs);		
	return 0;
}