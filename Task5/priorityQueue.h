// BinaryTree.h
// Header file containing class definition for 
// BinaryTree class

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "BinaryTreeNode.h"

#include <queue>
#include <vector>

using namespace std;

class priorityQueue
{
private:
	priority_queue<BinaryTreeNode*, vector<BinaryTreeNode*>, BinaryTreeNode> *myQueue;

public:
	priorityQueue();
	~priorityQueue();

	void addNode(BinaryTreeNode *newNode);
	BinaryTreeNode* removeNode(void);
	int getSize();
};

#endif // !PRIORITY_QUEUE_H