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
	// Root Node Case
	if (prev == nullptr && !nodeInit)
		data = newData;
	else
	{
		// Left Child Case
		if (newData < data)
		{
			if (left == nullptr)
				left = new BST(newData, this);
			else
				left->add(newData);
		}
		
		// Right Child Case
		else if (newData >= data)
		{
			if (right == nullptr)
				right = new BST(newData, this);
			else
				right->add(newData);
		}
	}
}
