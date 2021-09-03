#pragma once
#include <iostream>

class BST
{
public:
	// Creates an empty BST
	BST()
	{
		data = nullptr;
		prev = nullptr;
		left = nullptr;
		right = nullptr;
	}
	// Creates a BST with an initialized root node
	BST(int newData)
	{
		data = new int(newData);
		prev = nullptr;
		left = nullptr;
		right = nullptr;
	}
	~BST()
	{
		delete data; data = nullptr;
		prev = nullptr;
		delete left; left = nullptr;
		delete right; right = nullptr;
	}

	void add(int newData)
	{
		// Empty BST case
		if (data == nullptr)
		{
			data = new int(newData);
			return;
		}

		// Traverses the left end of the tree
		if (newData < *data)
		{
			if (left == nullptr)
				left = new BST(newData);
			else
				left->add(newData);
		}
		// Traverses the right end of the tree
		else
		{
			if (right == nullptr)
				right = new BST(newData);
			else
				right->add(newData);
		}
	}

	bool search(int searchData)
	{
		if (data == nullptr) return false;

		if (searchData == *data) return true;
		else
		{
			if (searchData >= *data && right != nullptr)
				return right->search(searchData);
			else if (searchData < *data && left != nullptr)
				return left->search(searchData);
			else
				return false;
		}
	}

	void print()
	{
		if (data == nullptr)
		{
			std::cout << "Empty BST" << std::endl;
			return;
		}

		std::cout << *data << std::endl;

		if (left != nullptr)
			left->print();
		if (right != nullptr)
			right->print();
	}
private:
	int* data;
	BST* prev;
	BST* left;
	BST* right;
};
