#include "BST.h"

BST::BST()
{
	prev = nullptr;
	left = nullptr;
	right = nullptr;

	nodeInit = false;
}

BST::BST(int newData, BST* previousNode)
{
	data = newData;

	prev = previousNode;
	left = nullptr;
	right = nullptr;

	nodeInit = true;
}

void BST::add(int newData)
{
	// Root case
	if (prev == nullptr && !nodeInit)
	{
		data = newData;
		nodeInit = true;
	}
	else
	{
		// Left child case
		if (newData < data)
		{
			if (left == nullptr)
				left = new BST(newData, this);
			else
				left->add(newData);
		}

		// Right child case
		else
		{
			if (right == nullptr)
				right = new BST(newData, this);
			else
				right->add(newData);
		}
	}
}

void BST::print()
{
	std::vector<bool> explored;

	if (nodeInit)
	{
		explored.push_back(true);

		horizontalTraverse(explored);
	}
	else
	{
		std::cout << "Empty tree.";
		std::cout << std::endl << std::endl;
	}
}

void BST::horizontalTraverse(std::vector<bool>& explored)
{
	std::cout << "Working" << std::endl;
}
