// SymbolFreq.h
// Header file containing class definition for 
// SymbolFreq class

#ifndef HUFFMANCODETREE_H
#define HUFFMANCODETREE_H

#include "SymbolFreq.h"
#include "BinaryTree.h"
#include "BinaryTreeNode.h"
#include "priorityQueue.h"

#include <map>
#include <string>

using namespace std;

class HuffmanCodeTree
{
private:
	SymbolFreq *myFreq = new SymbolFreq;
	BinaryTree *myTree = new BinaryTree;
	priorityQueue *myQueue = new priorityQueue;
	map<char, string> huffmanCodes;


public:
	HuffmanCodeTree(const char *fileName);
	~HuffmanCodeTree();

	void printHuffTree();
	void printHuffCodes();
	void buildHuffmanCodes(BinaryTreeNode *node, string currentCode, char cameFrom);
};

#endif // !HUFFMANCODETREE_H