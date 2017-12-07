#include "stdafx.h"
#include "AffineSolver.h"


AffineSolver::AffineSolver(Dictionary* dict)
{
	this->dict = dict;
}


string AffineSolver::solve(string s) {


	int* relPrimes = new int[12];

	relPrimes[0] = 1;
	relPrimes[1] = 3;
	relPrimes[2] = 5;
	relPrimes[3] = 7;
	relPrimes[4] = 9;
	relPrimes[5] = 11;
	relPrimes[6] = 15;
	relPrimes[7] = 17;
	relPrimes[8] = 19;
	relPrimes[9] = 21;
	relPrimes[10] = 23;
	relPrimes[11] = 25;
	


	for(int i = 0; i < 12; i++){
		int a = relPrimes[i];
		for (int b = 0; b < 25; b++) {

			string d = decrypt(s, a, b);


			vector<int>* vec = dict->addSpaces(d);


			if (vec != NULL) {

				stringstream stream;

				stream << "Key: " << a << " " << b << endl;

				keyString = stream.str();
				return d;
			}


		}

	}

	cout << "Couldn't solve" << endl;

}


void AffineSolver::test(string s, int a, int b) {
	solve(decrypt(s, a, b));
}

string AffineSolver::decrypt(string s, int a, int b) {

	stringstream stream;

	for (int i = 0; i < s.length(); i++) {
		int j = s.at(i) - 97;


		j = j * a + b;
	
		if (j < 0)
			j += 26;
		
		j = j % 26;

		stream << char(j + 97);
	}
	return stream.str();
}



AffineSolver::~AffineSolver()
{
}
