#include "BST.h"

BST::BST()
{
	prev = nullptr;
	left = nullptr;
	right = nullptr;
}

BST::BST(int newData, BST* previousNode)
{
	data = newData;

	prev = previousNode;
	left = nullptr;
	right = nullptr;
}

void BST::add(int newData)
{
	// Root node case
	if (prev == nullptr)
	{
		data = newData;
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
