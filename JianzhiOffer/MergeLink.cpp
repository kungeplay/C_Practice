#include <iostream>
//合并有序的字符串1和字符串2
struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
	ListNode(int i):m_nValue(i),m_pNext(NULL){}
};

void VisitLink(struct ListNode *p)
{
	while(p!=NULL)
	{
		std::cout<<p->m_nValue<<" ";
		p=p->m_pNext;
	}
	std::cout<<std::endl;
}
int MergeLink(struct ListNode *lhead1,struct ListNode *lhead2,struct ListNode **plhead)
{
	struct ListNode *pnode1,*pnode2;
	struct ListNode *pnode;
	pnode1=lhead1;
	pnode2=lhead2;
	*plhead=NULL;
	while(pnode1!=NULL&&pnode2!=NULL)
	{
		if(pnode1->m_nValue<pnode2->m_nValue)
		{
			if(*plhead==NULL)
				pnode=pnode1;
			else
				pnode->m_pNext=pnode1;
			pnode1=pnode1->m_pNext;
		}
		else
		{
			if(*plhead==NULL)
				pnode=pnode2;
			else
				pnode->m_pNext=pnode2;
			pnode2=pnode2->m_pNext;
		}
		if(*plhead==NULL)
		{
			*plhead=pnode;
		}
		else
			pnode=pnode->m_pNext;
	}
	if(pnode1!=NULL)
	{
		if(*plhead==NULL)
			*plhead=pnode1;
		else
			pnode->m_pNext=pnode1;
	}
	else
	{	
		if(*plhead==NULL)
			*plhead=pnode2;
		else
			pnode->m_pNext=pnode2;
	}
	return 1;
}
int main(int argc,char * argv[])
{
	struct ListNode * p1=new ListNode(1);
	p1->m_pNext=new ListNode(3);
	p1->m_pNext->m_pNext=new ListNode(5);
	struct ListNode *p2=new ListNode(2);
	p2->m_pNext=new ListNode(4);
	p2->m_pNext->m_pNext=new ListNode(6);
	p2->m_pNext->m_pNext->m_pNext=new ListNode(7);
	struct ListNode * p;
	struct ListNode *p3=NULL;
	if(MergeLink(p3,p2,&p))
		VisitLink(p);
	else
		std::cout<<"It is wrong!"<<std::endl;

}
