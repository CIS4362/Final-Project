#include "stdafx.h"
#include "Node.h"
#include <sstream>


Node::Node()
{
	
	end = false;
}



bool Node::isWord(string s, int i) {


	if (i == s.length()) {
		return end;
	}
	else {

		if (nodes == NULL)
			return false;

		if (nodes[s.at(i)-97] == NULL) {
			return false;
		}
		else {
			return nodes[s.at(i)-97]->isWord(s, i+1);
		}
	}
}


void Node::addWord(string s, int i) {
	
	if (i == s.length()) {
		end = true;
	}
	else{
		if (nodes == NULL) {
			setupNodes();
		}

		if (nodes[s.at(i) - 97] == NULL) {
			nodes[s.at(i) - 97] = new Node();
		}
	
		nodes[s.at(i) - 97]->addWord(s, i + 1);		
	
	}

}


void Node::getWords(string s, int i, vector<int>* vec) {

	

	if (end) {
		vec->push_back(i-1);
	}

	if (i == s.length()) {
		return;
	}

	if (nodes == NULL) {
		return;
	}


	if (nodes[s.at(i) - 97] == NULL) {

		return;
	}

	
	nodes[s.at(i) - 97]->getWords(s, i + 1, vec);

}



void Node::setupNodes() {

	empty = false;

	nodes = new Node*[26];
	for (int j = 0; j < 26; j++) {
		nodes[j] = NULL;
	}

}



Node::~Node()
{
	delete[] nodes;
}



void Node::speak() {
	
}