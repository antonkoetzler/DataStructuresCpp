#include "BST.h"

BST::BST()
{
	prev = left = right = nullptr;
}

BST::BST(int newData, BST* prevNode)
{
	data = newData;

	prev = prevNode;

	left = right = nullptr;
}

void BST::add(int newData)
{
	static int rootInit = false;

	// Root node case
	if (!rootInit)
	{
		data = newData; // Initialized
		rootInit = true;
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
