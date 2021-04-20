#pragma once

#include <iostream>

class BST
{
public:
	BST();
	BST(int, BST*);

	// Operations
	void add(int);

private:
	int data;

	BST* prev;
	BST* left;
	BST* right;
};
