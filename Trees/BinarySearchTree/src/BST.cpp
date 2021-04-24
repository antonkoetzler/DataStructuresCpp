#include "BST.h"
#include <string>

BST::BST()
{
	dataInit = nullptr;

	prev = left = right = nullptr;
}

BST::BST(int newData, BST* prevNode)
{
	dataInit = new Node(newData);

	prev = prevNode;

	left = right = nullptr;
}

void BST::add(int newData)
{
	// Root node case
	if (!prev && !dataInit)
		dataInit = new Node(newData);

	else
	{
		// Left child case
		if (newData < dataInit->data)
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
	std::cout << dataInit->data << ", ";

	if (left) left->print();
	if (right) right->print();
}

int BST::getLength()
{
	int leftHeight = 0;
	int rightHeight = 0;

	// Empty case
	if (!prev && !dataInit)
		return 0;

	else
  {
    	if (left)
			  leftHeight = left->getLength();
    	if (right)
    		rightHeight = right->getLength();

    	if (leftHeight >= rightHeight)
    		return leftHeight + 1;
    	else
    		return rightHeight + 1;
    }
}
