#include "BST.h"

int main(void)
{
	const BST tree;

	cout << "-----Print Tree In Order-----" << endl;
	tree.print();
	cout << endl;
	cout << "-----Convert Text to Morse Code-----" << endl;
	tree.convert();
	cout << endl;
	cout << "-----Destroying Nodes-----" << endl;

	return 0;
}