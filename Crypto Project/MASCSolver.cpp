#include "stdafx.h"
#include "MASCSolver.h"




MASCSolver::MASCSolver(Dictionary* dict)
{
	this->dict = dict;


	freq = new double[26];

	freq[0] =  0.0817;
	freq[1] =  0.01492;
	freq[2] =  0.02782;
	freq[3] =  0.04253;
	freq[4] =  0.12702;
	freq[5] =  0.0228;
	freq[6] =  0.02015;
	freq[7] =  0.06094;
	freq[8] =  0.06996;//i
	freq[9] =  0.00153;
	freq[10] = 0.00773; // k
	freq[11] = 0.04025;
	freq[12] = 0.02406;
	freq[13] = 0.06749;
	freq[14] = 0.07507;
	freq[15] = 0.01929;
	freq[16] = 0.00095; //q
	freq[17] = 0.05987;
	freq[18] = 0.06327;
	freq[19] = 0.09056;
	freq[20] = 0.02758;
	freq[21] = 0.00978;
	freq[21] = 0.0236;
	freq[22] = 0.0236;
	freq[23] = 0.0015;
	freq[24] = 0.01974;
	freq[25] = 0.00074;


	sortedF = "etaoinshrdlcumwfgypbvkjxqz";


}



void MASCSolver::solve(string s) {


	//Get Frequency Diagram

	int* hist = countFreq(s);


	// Each letter needs a sorted list of its most likely destinations


	char** array = new char*[25];


	for (int i = 0; i < 26; i++) {

		int* b = new int[26 * 2];

		for (int j = 0; j < 26; j++) {


			//store differences as negative integers to work well with quicksort method

			double difference = (double)(hist[i]) / (double)(s.length()) - freq[j];

			difference *= 10000;

			if (difference > 0)
				difference *= -1;



			b[j * 2] = (int)(difference);

			b[j * 2 + 1] = j;

		}


		//Sort Differences

		quicksort(b, 0, 25);

		//store the order of the letters from lowest difference to highest in the array

		array[i] = new char[26];

		for (int j = 0; j < 26; j++) {
			array[i][j] = b[j * 2 + 1] + 97;
		}

	}

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
		//	cout << array[i][j];// = b[j * 2 + 1] + 97;
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;
	cout << endl;

	char* key = new char[26];

	if (solveS(s, array, key)) {
		cout << endl << "Success!" << endl;

		cout << decrypt(s, key);

	}
	else {
		cout << endl << "Fail" << endl;

	}





	return;








	/*

	char* key = new char[26];
	char* f = new char[26];

	for (int i = 0; i < 26; i++) {
		f[i] = sorted[i*2+1] + 97;
		key[i] = 0;

	}
	
	
	checkPartialKey(s, key, f, 0);



	return;

	for (int i = 0; i < 26; i++) {
		key[sorted[i * 2 + 1]] = sortedF.at(i);
	}

	string a = this->decrypt(s, key);


	if (dict->addSpaces(a) != NULL) {
	//	cout << a << endl;
		return;
	}


	cout << a << endl;
	return;

	*/
}


bool MASCSolver::solveS(string s, char** array, char* key) {

	char c = s.at(0);



	for (int i = 0; i < 26; i++) {
		key[i] = '-';
	}

	for (int i = 0; i < 26; i++) {

		key[s.at(0) - 97] = array[0][i];

	
		if (solveR(s, array, key, 1, 1))
			return true;
	}
	return false;
}

bool MASCSolver::solveR(string s, char** array, char* key, int i, int totalKeys) {

	/*
	cout << i << '\t';
	for (int i = 0; i < 26; i++) {
		cout << key[i];
	}
	cout << endl;
	*/
	//cout << "i: " << i << "\t" << s.substr(0, i) << '\t' << decrypt(s.substr(0, i), key) << endl;

	
//	cout << endl;// << endl;
	//Get a list of possible choices:



	vector<char>* choices = dict->getChoices(decrypt(s.substr(0, i), key));

	//cout << "Have choices" << endl;


	if (choices == NULL) {
		//cout << "NULL choices" << endl;
		return false;
	}

	if (choices->size() == 0)
		return false;

	string d = decrypt(s.substr(0, i), key);

	//cout << d << '\t' << "Choices: ";

	//cout << endl;

	if (i >= s.length()) {

		//cout << "End of string" << endl;

		cout << decrypt(s, key) << endl;

		
		vector<int>* vec = dict->addSpaces(decrypt(s, key));


		if (vec == NULL) {
			return false;
		}
		else {
			for (int i = 0; i < s.length(); i++) {
				cout << decrypt(s,key).at(i);
				for (int j = 0; j < vec->size(); j++) {
					if (vec->at(j) == i)
						cout << ' ';
				}
			}
			return true;
		}






		return dict->addSpaces(decrypt(s, key)) != NULL;
	}


	if (totalKeys == 26) {
		//cout << "Found all keys" << endl;

		//all keys found
		return true;
	}

	if (key[s.at(i) - 97] != '-') {

	//	cout << "Key here" << endl;
	//	cout << choices->size();

		//key already found for this letter

		//Check if its in the list of choices

		bool good = false;
		for (int j = 0; j < choices->size(); j++) {
		//	cout << choices->at(j) << " " << key[s.at(i)-97] << endl;
			if (choices->at(j) == key[s.at(i) - 97]) {
				
				good = true;
				break;
			}

		}

		//Go on to the next if its a good choice

		if (good) {
		//	cout << "Try " << key[s.at(i) - 97] << endl;
			return solveR(s, array, key, i + 1, totalKeys);
		}
		else {
			return false;
		}

	}
	else {

	}


	for (int j = 0; j < 26; j++) {


		key[s.at(i) - 97] = array[i][j];
		

		bool good = false;
		for (int k = 0; k < choices->size(); k++) {
			if (choices->at(k) == key[s.at(i) - 97]) {
				good = true;
				break;
			}
		}

		if (good)
			for (int k = 0; k < 26; k++) {
				if (key[s.at(i) - 97] == key[k] && k != s.at(i) - 97){
					good = false;
					break;
				}
			}


		//go on to the next
		if (good) {
			if (solveR(s, array, key, i + 1, totalKeys + 1))
				return true;
		}
	}

	key[s.at(i) - 97] = '-';
	return false;
}



bool MASCSolver::checkPartialKey(string s, char* key, char* freq, int i) {

	if (i > 25) {

		for (int j = 0; j < 26; j++) {
			cout << key[j];
		}
		cout << endl;
	
	//	string a = this->decrypt(s, key);

		return false;

		//return dict->addSpaces(a) != NULL;	

	}




	for (int j = 0; j < 26; j++) {
		
		bool inKey = false;
		for (int k = 0; k < 26; k++) {
			if (key[k] == sortedF.at(j)) {
				inKey = true;
				break;
			}
		}

		if (!inKey) {
			key[freq[i]-97] = sortedF.at(j);

			checkPartialKey(s, key, freq, i + 1);
		}
	}
	key[freq[i] - 97] = 0;
	return false;
}



string MASCSolver::decrypt(string s, char* key) {
	

	stringstream stream;

	for (int i = 0; i < s.length(); i++) {
		stream << key[s.at(i) - 97];
	}
	

	return stream.str();
}


int* MASCSolver::countFreq(string s) {
	
	int* hist = new int[26 * 2];


	//Setup values

	for (int i = 0; i < 26; i++) {
		hist[i * 2] = 0;
		hist[i * 2 + 1] = i;
	}



	for (int i = 0; i < s.length(); i++){
		
		unsigned char c = s.at(i) - 97;

		hist[c * 2]++;
	}

	
	
	return hist;
}





void MASCSolver::test(string s) {

	//Generate key

	char* key = new char[26];



	for (int i = 0; i < 26; i++) {
		key[i] = 97+25 - i;
		//cout << key[i];
	}

	cout << endl;
	//encrypt
	
	//Note that the key is reflected

	string a = decrypt(s, key);


	
	//solve

	solve(a);


}

void MASCSolver::quicksort(int* array, int first, int last) {

	//Pick something to be in the middle
	//Smaller goes on left
	//Bigger goes on right
	//Do two more quick sorts if there is room for it

	double mid = array[((last - first) / 2 + first) * 2] - array[((last - first) / 2 + first) * 2 + 1] * 0.001;


	int left = first;
	int right = last;


	while (left <= right) {
		while (array[left * 2] - array[left * 2 + 1] * 0.001 > mid && left < right) {
			left++;
		}
		while (array[right * 2] - array[right * 2 + 1] * 0.001 < mid && right > left) {
			right--;
		}

		if (left == right)
			break;

		int temp = array[left * 2];
		array[left * 2] = array[right * 2];
		array[right * 2] = temp;

		temp = array[left * 2 + 1];
		array[left * 2 + 1] = array[right * 2 + 1];
		array[right * 2 + 1] = temp;


		if (array[left * 2] - array[left * 2 + 1] * 0.001 == array[right * 2] - array[right * 2 + 1] * 0.001)
			left++;

	}

	if ((left)-first > 1)
		quicksort(array, first, left - 1);
	if (last - right > 1)
		quicksort(array, right, last);

}




MASCSolver::~MASCSolver()
{
}
