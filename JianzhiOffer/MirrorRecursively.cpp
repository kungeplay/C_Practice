#include <iostream>
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};
void MirrorRecursively(BinaryTreeNode *pNode)
{
	if(pNode==NULL)
		return;
	if(pNode->m_pLeft==NULL&&pNode->m_pRight==NULL)
		return;

	BinaryTreeNode *temp=pNode->m_pLeft;
	pNode->m_pLeft=pNode->m_pRight;
	pNode->m_pRight=temp;

	std::cout<<"11"<<std::endl;
	if(pNode->m_pLeft)
		MirrorRecursively(pNode->m_pLeft);
	if(pNode->m_pRight)
		MirrorRecursively(pNode->m_pRight);
}
void VisitTree(BinaryTreeNode * p)
{
	if(p!=NULL)
		std::cout<<p->m_nValue<<" ";
	VisitTree(p->m_pLeft);
	VisitTree(p->m_pRight);
}

int main(int argc,char* argv[])
{
	BinaryTreeNode bthead,btnode1,btnode2;
	bthead.m_nValue=1;
	btnode1.m_nValue=2;
	btnode2.m_nValue=3;
	bthead.m_pLeft=&btnode1;
	bthead.m_pRight=&btnode2;
	MirrorRecursively(&bthead);
	VisitTree(&bthead);
}
