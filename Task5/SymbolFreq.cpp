// SymbolFreq.cpp
// Member function definitions/implementations

#include "stdafx.h"	
#include "SymbolFreq.h"

SymbolFreq::SymbolFreq()
{
	allSymbols = new vector<pair<char, int>>;
}

SymbolFreq::~SymbolFreq()
{
	delete allSymbols;
}


vector<pair<char, int>>* SymbolFreq::getFrequency(const char* fileName)
{
	// open a file fileName on put its comtents into variavle fullFile
	ifstream ifs(fileName);
	string fullFile;
	getline(ifs, fullFile, (char)ifs.eof());

	// declare an iterator to a vector of pairs 
	vector<pair<char, int>>::iterator it;  
	// initialise variables to determine if this is the first time a char has ocured
	bool isNew = true;
	bool found = false;
	int count = 0;

	// loop throug each char, cha , in the string fullFile
	for (char & cha : fullFile)
	{
		// initialise value of iterator to be the start of the vector
		it = allSymbols->begin();

		// while cha is now found in the vector and not end of vector
		while ((found == false) && (count < allSymbols->size()))
		{
			// if char is found existing in vector
			if (it->first == cha)
			{
				// increment value held in second position
				it->second = (it->second + 1);
				// exit while
				isNew = false;
				found = true;
			}
			// increment count to determin if end of vector
			count++;
			// increment vector iterator
			it++;
		}

		// if char wasnt already found in the vector add new entry with value of 1
		if (isNew == true)
		{
			allSymbols->push_back({cha,1});
		}

		// reset values for next loop
		count = 0;
		isNew = true;
		found = false;
	}

	// sort all memebers of allSymbols vector according to sortOnSecond function
	sort(allSymbols->begin(), allSymbols->end(), this->sortOnSecond );

	return allSymbols;

}

bool SymbolFreq::sortOnSecond(const pair<char, int> &a, const pair<char, int> &b)
{
	return a.second > b.second;
} 