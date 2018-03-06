// BinaryTree.cpp
// Member function definitions/implementations

#include "stdafx.h"	
#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::~BinaryTree()
{
	this->destroyTreeFrom(root);
}

BinaryTreeNode* BinaryTree::merge(BinaryTreeNode *left, BinaryTreeNode *right)
{
	// create newNumber by adding the number values of the two nodes being merged
	int newNumber = (left->number+right->number);
	// create a new node to become root with one of BinaryTreeNodes constructors, set newNumber as the number of the new node
	BinaryTreeNode* growth = new BinaryTreeNode(left,right, newNumber);
	// set newnode as root
	setRootNode(growth);

	return growth;
}

void BinaryTree::setRootNode(BinaryTreeNode *newRoot)
{
	root = newRoot;
}

BinaryTreeNode* BinaryTree::getRoot()
{
	return this->root;
}

// print the tree from the root
void BinaryTree::printTree()
{
	int indent = 0;

	this->printTreeFrom(root,indent);
}

// recursive call to print the whole tree
void BinaryTree::printTreeFrom(BinaryTreeNode *from, int indent)
{
	// if value passed in is null, i.e. not a node, return
	if (from == NULL)
	{
		return;
	}
	// increase indent for pretty print
	indent++;

	printTreeFrom(from->leftBranch, indent);
	
	// output indent for pretty print
	for (size_t i = 0; i < indent; i++)
	{
		cout << "	";
	}

	// output for nodes with no character
	if (from->chara == NULL)
	{
		cout << "*:" << from->number << endl;
	}
	// output for nodes that have a character value
	else
	{
		cout << "\'"<< from->chara << "\':" << from->number << endl;
	}

	printTreeFrom(from->rightBranch, indent);

}

void BinaryTree::destroyTreeFrom(BinaryTreeNode *from)
{
	// delete in the BinaryTreeNode struct recursively deletes all nodes from the one called
	delete from;
}
