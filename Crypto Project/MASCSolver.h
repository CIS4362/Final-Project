#pragma once
#include <string>
#include "Dictionary.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


class MASCSolver
{

	Dictionary* dict;

	string decrypt(string s, char* key);

	double* freq;
	
	string sortedF;


	int* countFreq(string s);

	void quicksort(int* array, int first, int last);

	bool checkPartialKey(string s, char* key, char* f, int i);

	bool solveS(string s, char** array, char* key);

	bool solveR(string s, char** array, char* key, int i, int totalKeys);


public:

	void test(string s);

	void solve(string s);


	MASCSolver(Dictionary* dict);
	~MASCSolver();
};

