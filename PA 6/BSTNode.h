#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;

class BSTNode
{
public:
	BSTNode(const char& newEnglish =  '/0', const string& newMorse = "");
	BSTNode(const BSTNode& copyNode);
	~BSTNode();

	char getEnglish() const;
	string getMorse() const;

	BSTNode* getLeftPtr() const;
	BSTNode* getRightPtr() const;

	void setLeftPtr(BSTNode* newPtr);
	void setRightPtr(BSTNode* newPtr);

	void setEnglish(char newEnglish);
	void setMorse(string newMorse);

private:
	char mEnglish;
	string mMorse;
	BSTNode* mpLeft;
	BSTNode* mpRight;
};