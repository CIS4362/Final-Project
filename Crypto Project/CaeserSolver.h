#pragma once

#include <string>
#include "Dictionary.h"
#include <iostream>
#include <sstream>
#include <vector>

class CaeserSolver
{

	Dictionary* dict;

	string decrypt(string s, int key);


	

public:

	void test(string s, int key);

	string solve(string s);


	CaeserSolver(Dictionary* dict);
	~CaeserSolver();
};

