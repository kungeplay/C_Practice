// Remove Duplicates from Sorted List II
//  Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3. 
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *disthead=nullptr,*distlist=nullptr,*lastnode=nullptr,*p=head;
        bool lastdup=false;//用来保存lastnode是否碰到重复的元素
        while(p!=nullptr)
        {
            if (lastnode==nullptr)//用lastnode存储上一次遍历时的节点元素
            {
                lastnode=new ListNode(p->val);
                lastdup=false;
            }
            else if (lastnode->val<p->val)
            {
                if (lastdup==false)
                {
                    if (disthead==nullptr)
                    {
                        disthead=distlist=lastnode;
                    }
                    else
                    {
                        distlist->next=lastnode;
                        distlist=distlist->next;
                    }
                }
                else
                {
                    delete lastnode;
                }
                lastnode=new ListNode(p->val);
                lastdup=false;
            }
            else if(lastnode->val==p->val)//碰到重复元素
            {
                lastdup=true;
            }
            else//链表无序，返回nullptr
            {
                return nullptr;
            }
            p=p->next;
        }

        if (lastdup==false)//链表最后的元素还没有存入
        {
            if (disthead==nullptr)//如果链表就只有一个元素
            {
                disthead=lastnode;
            }
            else
                distlist->next=lastnode;
        }
        else
            delete lastnode;
        return disthead;
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
	ln->next->next=new ListNode(1);
	ln->next->next->next=new ListNode(3);
	ln->next->next->next->next=new ListNode(4);
	ln->next->next->next->next->next=new ListNode(4);	
	ln->next->next->next->next->next->next=new ListNode(5);
	ListNode * rs=so.deleteDuplicates(ln);
	visitListNode(rs);		
	return 0;
}
