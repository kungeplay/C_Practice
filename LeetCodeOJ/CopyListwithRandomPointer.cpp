// Copy List with Random Pointer
// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

// Return a deep copy of the list.

#include <iostream>
#include <map>
using namespace std;

 /**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
 //这个题是剑指offer上的一个题，感觉这个题还没有133题Clone Graph难，但是那个却是medium，而这个题是hard
 //下面是其中一种用map表映射的做法，map表结果为136ms,unordered_map表结果为120ms
// class Solution {
// public:
// 	RandomListNode *copyRandomList(RandomListNode *head) {
// 		if(head==NULL)
// 			return NULL;
// 		map<RandomListNode *,RandomListNode*> nodeMap;
// 		RandomListNode* newHead=new RandomListNode(head->label);
// 		nodeMap.insert({head,newHead});
// 		RandomListNode *p=head,*q=newHead;
// 		while(p->next!=NULL)
// 		{
// 			q->next=new RandomListNode(p->next->label);
// 			nodeMap.insert({p->next,q->next});
// 			p=p->next;
// 			q=q->next;
// 		}
// 		p=head;
// 		while(p!=NULL)
// 		{
// 			nodeMap[p]->random=nodeMap[p->random];
// 			p=p->next;
// 		}
// 		return newHead;
// 	}
// };

//下面是第二种方法，先把克隆的节点放到被克隆的节点后面，然后再复制random指针，最后分隔开，耗时112ms，在网上看也都是以上这两种方法
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		CloneNextNode(head);
		CloneRandomNode(head);
		return CutNode(head);
	}
private:
    //克隆节点，并暂时放在被克隆的节点后面
	void CloneNextNode(RandomListNode* head)
	{
		RandomListNode *p=head;
		while(p!=NULL)
		{
			RandomListNode *q=new RandomListNode(p->label);
			q->next=p->next;
			p->next=q;
			p=q->next;	
		}
	}
	//复制节点的random指针
	void CloneRandomNode(RandomListNode *head)
	{
		RandomListNode *p=head;
		while(p!=NULL)
		{
			if(p->random!=NULL)//注意可能存在random指针为空的节点
			{
				p->next->random=p->random->next;
			}
			p=p->next->next;
		}
	}
	//分隔原有节点与克隆出的节点
	RandomListNode * CutNode(RandomListNode *head)
	{
		if(head==NULL)
			return NULL;
		RandomListNode *newHead=NULL;
		RandomListNode *p=head;
		RandomListNode *q=NULL;

		while(p!=NULL)
		{
			if(newHead==NULL)//注意bug
			{
				newHead=p->next;
				q=newHead;
			}
			else
			{
				q->next=p->next;
				q=q->next;
			}
			p->next=p->next->next;
			p=p->next;
		}
		return newHead;
	}
};

int main(int argc, char const *argv[])
{
	RandomListNode *head=new RandomListNode(1);
	// head->next=new RandomListNode(2);
	// head->next->next=new RandomListNode(3);
	// head->next->next->next=new RandomListNode(4);

	// head->random=head->next->next;
	// head->next->random=head->next->next->next;
	// head->next->next->random=head;
	// head->next->next->next->random=head->next;
	Solution so;
	RandomListNode * newHead=so.copyRandomList(head);

	RandomListNode *p=newHead;
	while(p!=NULL)
	{
		cout<<p->label<<'\t';
		if(p->random!=NULL)
			cout<<p->random->label;
		cout<<endl;
		p=p->next;
	}
	return 0;
}
