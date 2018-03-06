// Task5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HuffmanCodeTree.h"

int main()
{
	// call HuffmanCodeTree constructor to create a binart huffman tree
	HuffmanCodeTree *myHuffmanTree = new HuffmanCodeTree("ToCompress.txt");
	// print the binary huffman tree
	myHuffmanTree->printHuffTree();
	// create and output the huffman codes generated for each char in ToCompress.txt
	myHuffmanTree->printHuffCodes();

    return 0;
}

