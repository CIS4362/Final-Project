#pragma once

#include <string>
#include "Dictionary.h"
#include <iostream>
#include <sstream>
#include <vector>

class AffineSolver
{

	Dictionary* dict;

	string decrypt(string s, int a, int b);

	string keyString;


public:

	void test(string s, int a, int b);

	string solve(string s);

	string getKey();


	AffineSolver(Dictionary* dict);
	~AffineSolver();
};

