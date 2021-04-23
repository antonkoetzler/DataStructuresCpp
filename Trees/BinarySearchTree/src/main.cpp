#include "BST.h"

int main()
{
	BST* tree = new BST();

	tree->add(5);
	tree->add(2);
	tree->add(7);
	tree->add(4);

	tree->print();

	delete tree; return 0;
}