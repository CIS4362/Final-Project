#pragma once

#include "Node.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

class Dictionary
{
public:


	Node** nodes;

	void addWord(string s);

	bool isWord(string s);

	bool readFromFile(string file);

	vector<int>* getWords(string s);

	vector<int>* getWords(string s, int i);


	vector<int>* addSpaces(string s);

	vector<int>* addSpaces(string s, int i);

	vector<char>* getChoices(string s);

	void getChoices(string s, int i, vector<int>* v);

	vector<char>* getChoicesFromWord(string s, int i);

	Dictionary();
	~Dictionary();
};

