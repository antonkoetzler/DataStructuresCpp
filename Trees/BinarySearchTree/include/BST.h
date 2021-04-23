#pragma once

#include <iostream>

class BST
{
public:
	BST(); // Empty tree constructor
	BST(int, BST*); // Child node constructor

	// Operations
	void add(int);

	void print();
		void BFS();

private:
	int data;

	BST* prev;
	BST* left;
	BST* right;
};
