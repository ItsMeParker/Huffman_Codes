// BinaryTreeNode.h
// Header file containing struct definition for 
// BinaryTreeNode struct

#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

struct BinaryTreeNode
{
	// variable to hold branch values for binary tree
	BinaryTreeNode *leftBranch;
	BinaryTreeNode *rightBranch;
	// number holds the number of occurances of chara or the weight of the current node if no character is present
	int number;
	char chara;

	// comparator to be used by priority queue object. will ensure lower values are at the top of the queue
	bool operator()(const BinaryTreeNode *a, const BinaryTreeNode *b)
	{
		return a->number > b->number;
	}

	// constructor used by HuffmanCodeTree constructor to create a floating node
	BinaryTreeNode(int number,char chara) :leftBranch(0), rightBranch(0), number(number), chara(chara) {}
	// constructor used by BinaryTree.cpp's merge function to create a new node that becomes root, has a number but no chara
	BinaryTreeNode(BinaryTreeNode *left, BinaryTreeNode *right, int number) :leftBranch(left), rightBranch(right), number(number), chara(NULL) {}
	// constructor used by line 229 of the queue standard header to construct with empty container, default comparator
	BinaryTreeNode() :leftBranch(0), rightBranch(0) {}

	// destructor. recursively deletes all nodes in the tree
	~BinaryTreeNode()
	{
		if (leftBranch) delete leftBranch;
		if (rightBranch) delete rightBranch;
	}
};

#endif // !BINARYTREENODE_H