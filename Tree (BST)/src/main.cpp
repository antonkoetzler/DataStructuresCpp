/*
A flexible BST data structure. Flexible as in it
can be intialized however, and it works perfectly.

Operations
- add
- remove
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

	if (tree->search(6))
		std::cout << "6 found" << std::endl << std::endl;
	else
		std::cout << "6 not found" << std::endl;

	if (tree->del(8))
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
