// CryptoProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Dictionary.h"
#include <iostream>
#include <string>
#include "Node.h"
#include <vector>
#include "MASCSolver.h"
#include "CaeserSolver.h"
#include "AffineSolver.h"


using namespace std;




int main()
{


	Dictionary* dict = new Dictionary();


	string s;

	s = "new.txt";
	bool read = true;

	if (read)
		if (!dict->readFromFile(s)) {
			cout << "File Not Found" << endl;
			return 1;
		}

	cout << "Ready" << endl;
	
	
	MASCSolver solver(dict);

	cin >> s;

	cout << solver.solve("qbpq");
	
	//solver.test("test", 5);
	
	
	return 0;
	
	/*
	
	MASCSolver solver(dict);


	unsigned char c;
	stringstream stream;
	
	
	/*
	while (!cin.eof()) {
		cin >> c;

		if(c >= 97 && c <= 97+25)
			stream << c;
	}
	*/

	//cin >> s;

	
	//solver.test(s);


	//return 0;




	
	while (true) {


		cout << endl << endl;

		cin >> s;
	

		// << dict->isWord(s);

		//continue;

		vector<int>* vec = dict->addSpaces(s);


		if (vec == NULL) {
			cout << endl << "Can't be done" << endl;
		}
		else
			for (int i = 0; i < s.length(); i++) {
				cout << s.at(i);
				for (int j = 0; j < vec->size(); j++) {
					if (vec->at(j) == i)
						cout << ' ';
				}
			}

	}


	return 0;
	


    return 0;
}
