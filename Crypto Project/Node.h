#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:

	bool empty = true;

	int a = 1;

	Node** nodes;

	bool end;

	bool isWord(string s, int i);


	void addWord(string s, int i);

	void speak();

	void setupNodes();

	void getWords(string s, int i, vector<int>* vec);



	Node();
	~Node();
};

