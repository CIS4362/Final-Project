#include "stdafx.h"
#include "CaeserSolver.h"


CaeserSolver::CaeserSolver(Dictionary* dict)
{
	this->dict = dict;
}


string CaeserSolver::solve(string s) {



	for (int i = 0; i < 25; i++) {
		string a = decrypt(s, i);

			if (dict->addSpaces(a) != NULL) {
				//	cout << "Key: " << i << endl;
				//cout << a << endl;

				return a;
			}

	}

	return "Couldn't solve";

}


void CaeserSolver::test(string s, int key) {
	solve(decrypt(s, key *- 1));
}

string CaeserSolver::decrypt(string s, int key) {
	
	stringstream stream;

	for (int i = 0; i < s.length(); i++) {
		char j = s.at(i) - 97;


		j -= key;
		if (j < 0)
			j += 26;
		j %= 26;


		stream << char(j + 97);
	}
	return stream.str();
}



CaeserSolver::~CaeserSolver()
{
}
