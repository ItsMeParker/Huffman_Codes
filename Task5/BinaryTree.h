// BinaryTree.h
// Header file containing class definition for 
// BinaryTree class

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

#include "BinaryTreeNode.h"

using namespace std;

class BinaryTree
{
private:
	BinaryTreeNode *root;

public:
	BinaryTree();
	~BinaryTree();

	BinaryTreeNode* merge(BinaryTreeNode *left, BinaryTreeNode *right);
	void setRootNode(BinaryTreeNode *newRoot);
	BinaryTreeNode* getRoot();
	void printTree();
	void printTreeFrom(BinaryTreeNode *from, int indent);
	void destroyTreeFrom(BinaryTreeNode *from);

};

#endif // !BINARYTREE_H