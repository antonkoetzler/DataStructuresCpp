#include "BST.h"
#include <fstream>

void extractInformation(BST*);

int main()
{
	BST* tree = new BST();

	extractInformation(tree);

	delete tree; return 0;
}

void extractInformation(BST* tree)
{
	std::ifstream inputStream("./input.txt");
	int data;

	if (inputStream.is_open())
	{
		while (!inputStream.eof())
		{
			inputStream >> data;
			tree->add(data);
		}
	}

	inputStream.close();
}