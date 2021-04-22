#pragma once

#include <iostream>
#include <vector>

class BST
{
public:
	BST(); // Empty tree constructor
	BST(int, BST*); // Child constructor

	// Operations
	void add(int);

	void print();
		void horizontalTraverse(std::vector<bool>&);

private:
	int data;

	BST* prev;
	BST* left;
	BST* right;

	bool nodeInit;
};
