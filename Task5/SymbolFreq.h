// SymbolFreq.h
// Header file containing class definition for 
// SymbolFreq class

#ifndef SYMBOLFREQ_H
#define SYMBOLFREQ_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;

class SymbolFreq
{
private:
	vector<pair<char, int>> *allSymbols;

public:
	SymbolFreq();
	~SymbolFreq();

	vector<pair<char, int>>* getFrequency(const char* fileName);
	static bool sortOnSecond(const pair<char, int> &a, const pair<char, int> &b);
};

#endif // !SYMBOLFREQ_H