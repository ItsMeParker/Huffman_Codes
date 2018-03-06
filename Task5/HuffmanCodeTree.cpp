#include "stdafx.h"
#include "HuffmanCodeTree.h"

HuffmanCodeTree::HuffmanCodeTree(const char* fileName)
{
	// create an instance of SymbolFreq class  
	SymbolFreq SymbolFreq;
	// populate a vector of pairs with all characters appearing in ToCompress.txt along with the number of occurances of each
	vector<pair<char, int>> *allSymbols = SymbolFreq.getFrequency("ToCompress.txt");

	// loop through each member of vector allSymbols and add to priority queue
	for each (auto oneChar in *allSymbols)
	{
		// create a free floating node with a character oneChar.second, and the number of occurences for that char oneChar.first
		BinaryTreeNode *newNode = new BinaryTreeNode(oneChar.second, oneChar.first);
		// add the new node to the priorityQueue
		myQueue->addNode(newNode);
	}

	// while priorityQueue has at least 2 entries 
	while (myQueue->getSize() > 1)
	{
		// reomve the top two nodes in the priority list, merge them into a new node, and add that new node back into the priority queue
		myQueue->addNode(myTree->merge(myQueue->removeNode() , myQueue->removeNode()));

	}

}

HuffmanCodeTree::~HuffmanCodeTree()
{
	delete myFreq;
	delete myTree;
	delete myQueue;
}

void HuffmanCodeTree::printHuffTree()
{
	myTree->printTree();
}

void HuffmanCodeTree::printHuffCodes()
{
	// start a recursive pass through the huffman tree from root to create a map of huffman codes
	buildHuffmanCodes(this->myTree->getRoot() , "", 'F');

	// print all characters in the map and their huffman codes
	for each (auto &entry in huffmanCodes)
	{
		cout << "char: \'" << entry.first << "\' |  " << huffmanCodes[entry.first] << endl;
	}

}

void HuffmanCodeTree::buildHuffmanCodes(BinaryTreeNode *node, string currentCode, char cameFrom)
{
	// append a 0 or 1 to currentCode depending if the previous node was left or right
	if (cameFrom == 'L')
	{
		currentCode += "0";
	}
	else if (cameFrom == 'R')
	{
		currentCode += "1";
	}

	// only make next call if next node isn't null
	if (node->leftBranch != NULL)
	{
		buildHuffmanCodes(node->leftBranch, currentCode, 'L');
	}

	if (node->rightBranch != NULL)
	{
		buildHuffmanCodes(node->rightBranch, currentCode, 'R');
	}

	// if node holds a character add character and its code the the map
	if (node->chara != NULL)
	{
		huffmanCodes[node->chara] = currentCode;
	}
}
