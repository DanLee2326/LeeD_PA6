#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "BSTNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;

class BST
{
public:
	BST();
	BST(const BST& copyBST);
	~BST();

	void insert(const char& newEnglish, const string& newMorse);
	void print() const;
	string search(char& eng) const;
	void convert() const;
	

private:
	void destroyTree(BSTNode* pTree);
	void insert(BSTNode* pTree, const char& newEnglish, const string& newMorse);
	void print(BSTNode* pTree) const;
	string search(BSTNode* pTree, char& eng) const;

	BSTNode* mpRoot;
};