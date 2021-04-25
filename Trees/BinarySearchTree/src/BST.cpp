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
	int length = getLength(); // For spacing

	// Empty case
	if (length == 0)
	{
		std::cout << "Empty Tree" << std::endl << std::endl;
		return;
	}
	else
	{
		std::vector<int> values; getData(values);

		std::vector<std::vector<Node*>> BFS = BFSOrder(values);
	}
}

std::vector<std::vector<Node*>> BST::BFSOrder(std::vector<int>& values)
{
	// PRODUCT
	std::vector<std::vector<Node*>> BFS;

	// Variables needed for this operations
	std::vector<Node*> transfer;
	Node* parent = nullptr;
	Node* current = nullptr;

	//// ROOT NODE CASE

	// Placing the root node
	transfer.push_back(new Node(values[0]));
	BFS.push_back(transfer);
	transfer.clear();

	// Finding left subtree
	for (int i = 1; i < (int)values.size(); i++)
	{
		if (values[i] < values[0])
		{
			transfer.push_back(new Node(values[i]));
			values.erase(values.begin() + i);
			break;
		}

		// No neighbour case
		if (i == (int)values.size() - 1 && values[i] >= values[0])
			transfer.push_back(nullptr);
	}

	// Finding right subtree
	for (int i = 1; i < (int)values.size(); i++)
	{
		if (values[i] >= values[0])
		{
			transfer.push_back(new Node(values[i]));
			values.erase(values.begin() + i);
			break;
		}

		// No neighbour case
		if (i == (int)values.size() - 1 && values[i] < values[0])
			transfer.push_back(nullptr);
	}

	BFS.push_back(transfer); // Added to our product
	transfer.clear();

	values.erase(values.begin()); // Deleting the root node

	////



	//// GENERAL NODE CASE

	for (int i = 0; i < (int)BFS[BFS.size() - 1].size(); i++)
	{
		// Current node
		if (BFS[BFS.size() - 1][i])
			current = new Node(BFS[BFS.size() - 1][i]->data);

		// Finding the parent node
		float multiplier = i * 0.5f; // 0.5 always divider
		if (BFS[BFS.size() - 2][multiplier])
			parent = new Node(BFS[BFS.size() - 2][multiplier]->data);


		std::cout << "current: " << current->data << std::endl;
		std::cout << "parent: " << parent->data << std::endl;

		delete current; current = nullptr;
		delete parent; parent = nullptr;
	}

	BFS.push_back(transfer);
	transfer.clear();

	////

	values.clear(); return BFS;
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

void BST::getData(std::vector<int>& values)
{
	if (dataInit)
		values.push_back(dataInit->data);

	if (left) left->getData(values);
	if (right) right->getData(values);
}
