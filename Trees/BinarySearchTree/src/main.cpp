/*
A flexible BST data structure. Flexible as in it
can be intialized however, and it works perfectly.

Operations
- add
- remove
	- removeMin
- search
- print

Author: Anton Koetzler-Faust
Email: antonkoetzler-faust@hotmail.com
*/

#include "BST.h"
#include <vector>
#include <fstream>

BST* extractInformation();

int main()
{
	BST* tree = extractInformation();

	tree->print();

	delete tree; return 0;
}

BST* extractInformation()
{
	BST* tree = new BST();
	std::ifstream inputStream("./input.txt");

	int data; char comma;

	if (inputStream.is_open())
	{
		while (!inputStream.eof())
		{
			inputStream >> data >> comma;
			tree->add(data);
		}
	}

	inputStream.close(); return tree;
}
