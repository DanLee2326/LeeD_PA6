#include "BSTNode.h"

BSTNode::BSTNode(const char& newEnglish, const string& newMorse)
{
	this->mEnglish = newEnglish;
	this->mMorse = newMorse;

	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

BSTNode::BSTNode(const BSTNode& copyNode)
{

}

BSTNode::~BSTNode()
{
	cout << "Destroying: " << this->mEnglish << ' ' << this->mMorse << endl;
}

char BSTNode::getEnglish() const
{
	return this->mEnglish;
}

string BSTNode::getMorse() const
{
	return this->mMorse;
}

BSTNode* BSTNode::getLeftPtr() const
{
	return this->mpLeft;
}

BSTNode* BSTNode::getRightPtr() const
{
	return this->mpRight;
}

void BSTNode::setLeftPtr(BSTNode* newPtr)
{
	this->mpLeft = newPtr;
}

void BSTNode::setRightPtr(BSTNode* newPtr)
{
	this->mpRight = newPtr;
}

void BSTNode::setEnglish(char newEnglish)
{
	this->mEnglish = newEnglish;
}
void BSTNode::setMorse(string newMorse)
{
	this->mMorse = newMorse;
}