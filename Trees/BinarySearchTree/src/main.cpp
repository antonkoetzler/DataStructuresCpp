#include "BST.h"

int main()
{
	BST* tree = new BST();
	
	tree->add(5);
	tree->add(4);
	tree->add(8);
	
	delete tree; return 0;
}
