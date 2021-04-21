#pragma once

#include <iostream>

class BST
{
public:
	BST(); // Empty Tree Constructor
	BST(int, BST*); // Child Node Constructor
	
	// Operations
	void add(int);
	
	// Getters
	int getLength();

private:
	int data;
	
	BST* prev;
	BST* left;
	BST* right;
	
	bool nodeInit; // This is to check if the
				   // root was initalized
};
