#include "stdafx.h"
#include "Dictionary.h"


Dictionary::Dictionary()
{

	nodes = new Node*[26];

	for (int i = 0; i < 26; i++) {
		nodes[i] = NULL;
	}



}


bool Dictionary::isWord(string s) {

	if (nodes[s.at(0)-97] == NULL)
		return false;
	else {
		return nodes[s.at(0)-97]->isWord(s, 1);
	}
}


void Dictionary::addWord(string s) {

	
	if (nodes[s.at(0) - 97] == NULL) {
		nodes[s.at(0) - 97] = new Node();
	}
		
	nodes[s.at(0) - 97]->addWord(s, 1);

}



bool Dictionary::readFromFile(string file) {

	fstream f;

	
	f.open(file);

	if (f.fail())
		return false;
	
	string s;

	while (!f.eof()) {
		f >> s;
		this->addWord(s);
	}

	f.close();

	return true;
}


vector<int>* Dictionary::getWords(string s) {

	
	vector<int>* vec = new vector<int>();

	if (nodes[s.at(0) - 97] == NULL)
		return false;
	else {
		nodes[s.at(0) - 97]->getWords(s, 1, vec);

		return vec;

	}
}

vector<int>* Dictionary::getWords(string s, int i ) {




	vector<int>* vec = new vector<int>();

	if (nodes[s.at(i) - 97] == NULL)
		return vec;
	else {
		nodes[s.at(i) - 97]->getWords(s, i+1, vec);


		return vec;

	}
}


vector<char>* Dictionary::getChoicesFromWord(string s, int i) {



	vector<char>* v = new vector<char>();

	Node* n = nodes[s.at(i) - 97];


	if (n == NULL)
		return NULL;
	
	for (int j = i+1; j < s.length(); j++) {
		

		
		if (n->empty) {

			return NULL;
		}


		n =	n->nodes[s.at(j) - 97];

		if (n == NULL) {
			return NULL;
		}

	}
	
	for (int j = 0; j < 26; j++) {

		if (n->end) {
			v->push_back(j + 97);
		}

		else if(n->nodes!=NULL)
			if (n->nodes[j] != NULL) {
				v->push_back(j + 97);
			}


	}



	return v;
}


vector<char>* Dictionary::getChoices(string s) {



	vector<int>*  v = new vector<int>();


	
	getChoices(s, 0, v);

	
	vector<char>* c = new vector<char>();

	if (v->size() == 0) {
		return c;
	}

	if (v->back() >= s.length() - 1) {
		for (int j = 0; j < 26; j++) {
			c->push_back(j + 97);
		}
		return c;

	}



	for (int i = 0; i < v->size(); i++) {


		vector<char>* a = getChoicesFromWord(s, v->at(i));


		for (int j = 0; j < a->size(); j++) {
			c->push_back(a->at(j));
			
		}
	}





	return c;

}

void Dictionary::getChoices(string s, int i, vector<int>* vec) {


	
	if (i >= s.length() - 1) {

		//Finished the string

		//Means that anything is possible

		vec->push_back(i);

		return;
	}



	vector<int>* v = this->getWords(s, i);


	if (v->size() == 0) {
		//Is the tail end on track to being a word?
		//if so we found a good result

		

		if (this->getChoicesFromWord(s, i) != NULL) {
			vec->push_back(i);
		}


		return;
	}




	for (int j = v->size() - 1; j >= 0; j--) {

		getChoices(s, v->at(j) + 1, vec);

		if(vec->size() > 0)
		if (vec->back() >= s.length() -1) {
			return;
		}

	}

	return;
}



vector<int>* Dictionary::addSpaces(string s) {

	return addSpaces(s, 0);
}


vector<int>* Dictionary::addSpaces(string s, int i) {

	
	if (i >= s.length()) {
		//Finished the string
		return new vector<int>();
	}


	vector<int>* v = this->getWords(s, i);


	if (v->size() == 0) {
		return NULL;
	}

	


	vector<int>* vR;


	for (int j = v->size()-1; j >= 0; j--) {

		vR = addSpaces(s, v->at(j) + 1);

		if (vR != NULL) {
			vR->push_back(v->at(j));
			return vR;
		}

	}


	return NULL;

}




Dictionary::~Dictionary()
{
	delete[] nodes;
}
