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




public:

	void test(string s, int a, int b);

	void solve(string s);


	AffineSolver(Dictionary* dict);
	~AffineSolver();
};

