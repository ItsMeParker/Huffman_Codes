#include "stdafx.h"
#include "priorityQueue.h"

priorityQueue::priorityQueue()
{
	myQueue = new priority_queue<BinaryTreeNode*, vector<BinaryTreeNode*>, BinaryTreeNode>;
}

priorityQueue::~priorityQueue()
{
	delete myQueue;
}

void priorityQueue::addNode(BinaryTreeNode * newNode)
{
	this->myQueue->push(newNode);
}

BinaryTreeNode* priorityQueue::removeNode(void)
{
	BinaryTreeNode *oldTop = this->myQueue->top();

	this->myQueue->pop();

	return oldTop;
}

int priorityQueue::getSize()
{
	return this->myQueue->size();
}
