#include <iostream>

struct QueueNode
{
	int s1index;
	int s2index;
	struct QueueNode * pnext;
	QueueNode(int i,int j):s1index(i),s2index(j),pnext(nullptr){};
};
struct Queue
{
	struct QueueNode * qhead;
	struct QueueNode * qlast;
	Queue():qhead(nullptr),qlast(nullptr){};
};
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {	
    		int i;
    		struct QueueNode *pnode;
    		InitQueue();
    		EnQueue(new	QueueNode(-1,-1));
        for(i=0;i<s3.length;i++)
        {
        		if(DeQueue(&pnode))
        		{
        			if (s1[pnode->s1index+1]==s3[i])
        				EnQueue(new QueueNode(pnode->s1index+1,pnode->s2index));
        			if (s2[pnode->s2index+1]==s3[i])
        				EnQueue(new QueueNode(pnode->s1index,pnode->s2index+1));
        		}
        		else
        			break;
        }
        if (i==s3.length)
        	return true;
        else
        	return false;
    }
private:
	void InitQueue()
	{
		pq=new struct Queue();
	}
	void EnQueue(struct QueueNode *pnode)
	{
		if (pq->qlast==nullptr)
		{
			pq->qhead=pq->qlast=pnode;
		}
		else
		{
			pq->qlast->pnext=pnode;
			pq->qlast=pnode;
		}	
	}
	bool DeQueue(struct QueueNode **ppnode)
	{
		if (pq->qhead!=nullptr)
		{
			*pnode=pq->qhead;
			pq->qhead=pq->qhead->pnext;
			return true;
		}
		else
		{
			*pnode=nullptr;
			return false;
		}

	}
	struct Queue *pq;
	string s1;
	string s2;
	string s3;
};

int main(int argc, char const *argv[])
{
	string s1="aabcc";
	string s2="dbbca";
	strign s3="aadbbcbcac";
	Solution s;
	std::cout<<s.isInterleave(s1,s2,s3)?"Yes!":"NO!"<<std::endl;
	return 0;
}