#include "BST.h"

BST::BST()
{
	this->mpRoot = nullptr;

	fstream infile;
	infile.open("MorseTable.txt", std::ios::in);

	while (infile.is_open() && !infile.eof())
	{
		char read[100] = "";
		char english;
		string morse = "";

		infile.getline(read, 100, ' ');
		english = read[0];
		infile.getline(read, 100);
		morse = read;

		insert(english, morse);
	}
	infile.close();
}

BST::BST(const BST& copyBST)
{
	
}

BST::~BST()
{
	destroyTree(this->mpRoot);
}

void BST::destroyTree(BSTNode* pTree)
{
	if (pTree != nullptr)
	{
		// recursive
		destroyTree(pTree->getLeftPtr());
		destroyTree(pTree->getRightPtr());
		// process - deleting one node
		delete pTree;
	}
}

void BST::insert(const char& newEnglish, const string& newMorse)
{
	insert(this->mpRoot, newEnglish, newMorse);
}

void BST::insert(BSTNode* pTree, const char& newEnglish, const string& newMorse)
{
	if (pTree == nullptr)
	{
		// yes, it's an empty tree
		this->mpRoot = new BSTNode(newEnglish, newMorse);
	}
	else // recursive steps
	{
		if (pTree->getEnglish() > newEnglish)
		{
			if (pTree->getLeftPtr() == nullptr)
			{
				// should insert here! left ptr
				pTree->setLeftPtr(new BSTNode(newEnglish, newMorse));
			}
			else
			{
				// traverse the left subtree - recursive
				insert(pTree->getLeftPtr(), newEnglish, newMorse);
			}
		} // end if
		else if (pTree->getEnglish() < newEnglish)
		{
			// go right
			if (pTree->getRightPtr() == nullptr)
			{
				// should insert
				pTree->setRightPtr(new BSTNode(newEnglish, newMorse));
			}
			else
			{
				// recursive - go right
				insert(pTree->getRightPtr(), newEnglish, newMorse);
			}
		}
		else // duplicates
		{
			cout << "Duplicate: " << newEnglish << endl;
		}
	}
}

void BST::print() const
{
	print(this->mpRoot);
}

void BST::print(BSTNode* pTree) const
{
	if (pTree != nullptr)
	{
		print(pTree->getLeftPtr());
		cout << pTree->getEnglish() << " " << pTree->getMorse() << endl;
		print(pTree->getRightPtr());
	}
}

string BST::search(char& eng) const
{
	return search(this->mpRoot, eng);
}

string BST::search(BSTNode* pTree, char& eng) const
{
	bool success = false;

	if (pTree->getEnglish() == eng)
	{
		success = true;
		return pTree->getMorse();
	}
	else if (pTree->getEnglish() > eng)
	{
		return search(pTree->getLeftPtr(), eng);
	}
	else if (pTree->getEnglish() < eng)
	{
		return search(pTree->getRightPtr(), eng);
	}
}

void BST::convert() const
{
	fstream infile2;
	infile2.open("Convert.txt", std::ios::in);

	while (infile2.is_open() && !infile2.eof())
	{
		char conv[100] = "";
		infile2.getline(conv, 100);

		for (int n = 0; n < strlen(conv); n++)
		{
			conv[n] = toupper(conv[n]);
		}
	
		for (int i = 0; i < strlen(conv); i++)
		{
			if (conv[i] == ' ')
			{
				conv[i + 1];
				cout << "   ";
			}
			else
			{
				cout << search(conv[i]) << " ";
			}
		}
		cout << endl;
	}
	infile2.close();
}