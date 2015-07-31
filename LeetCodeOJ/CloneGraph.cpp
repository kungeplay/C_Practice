/*
Clone Graph
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:

Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

    First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
    Second node is labeled as 1. Connect node 1 to node 2.
    Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/**
 * Definition for undirected graph.
 */
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

 //不容易呀，按照剑指offer上的一个复制复杂链表题的思路，在这个题里也是先把复制的链表节点放在后面，
 //看到网上说的大都是用map表做当前节点和复制节点的映射，这样，第二次循环的时候，复制neighbors中的内容，这也是剑指offer里的思路。
 //又看了看这个题和刚做的一个题Copy List with Random Pointer相比，感觉由于题中说了label标志惟一，感觉用map表应该效率更好些，
 //这个网站说的挺好：http://blog.csdn.net/lanxu_yy/article/details/17802415
 //，http://www.cnblogs.com/xinsheng/p/3515119.html。
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    		UndirectedGraphNode * newNode=NULL;
    		if(node==NULL)
    			return newNode;   
    		unordered_set<UndirectedGraphNode *> visitedNode;//统计是否复制过此节点
    		CloneNode(node,visitedNode);//复制链表节点，放在节点后面
    		int len=node->neighbors.size();
    		newNode=node->neighbors[len-1];
    		CutNode(visitedNode);//隔离节点
    		return newNode;
    }
private:
	void CloneNode(UndirectedGraphNode *node,unordered_set<UndirectedGraphNode*> &visitedNode)
	{
		int len=node->neighbors.size();
		UndirectedGraphNode *newNode;
		if(visitedNode.find(node)==visitedNode.end())
		{
			visitedNode.insert(node);
			newNode=new UndirectedGraphNode(node->label);
			node->neighbors.push_back(newNode);
		}
		else
			newNode=node->neighbors[len-1];

		for(int i=0;node->neighbors[i]!=newNode;++i)
		{	
			if(visitedNode.find(node->neighbors[i])==visitedNode.end())
			{	CloneNode(node->neighbors[i],visitedNode);
			}
			int nextLen=node->neighbors[i]->neighbors.size();
			newNode->neighbors.push_back(node->neighbors[i]->neighbors[nextLen-1]);

		}
	}
	void CutNode(unordered_set<UndirectedGraphNode*> visitedNode)
	{
		for(auto iter=visitedNode.begin();iter!=visitedNode.end();++iter)
			(*iter)->neighbors.pop_back();
	}
};
void VisitGraphNode(UndirectedGraphNode * node,unordered_set<UndirectedGraphNode *> &visitedNode)
{
	visitedNode.insert(node);
	int len=node->neighbors.size();		

	cout<<node->label<<",";
	int i=0;
	while(i<len)
	{
		cout<<node->neighbors[i]->label;
		if(i<len-1)
			cout<<',';
		++i;
	}
	i=0;
	while(i<len)
	{
		if(visitedNode.find(node->neighbors[i])==visitedNode.end())
		{
			cout<<"#";
			VisitGraphNode(node->neighbors[i],visitedNode);
		}
		++i;
	}
}
int main(int argc, char const *argv[])
{
	UndirectedGraphNode * node2=new UndirectedGraphNode(2);
	node2->neighbors.push_back(node2);
	UndirectedGraphNode *node1=new UndirectedGraphNode(1);
	node1->neighbors.push_back(node2);
	UndirectedGraphNode * node=new UndirectedGraphNode(0);
	node->neighbors.push_back(node1);
	node->neighbors.push_back(node2);
	Solution so;
	UndirectedGraphNode* newNode=so.cloneGraph(node);
	unordered_set<UndirectedGraphNode*> visitedNode;
	VisitGraphNode(newNode,visitedNode);
	// cout<<newNode->label<<'\t'<<newNode->neighbors[0]->label<<endl;
	return 0;
}
