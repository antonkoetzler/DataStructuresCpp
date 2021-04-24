#pragma once

#include <iostream>
#include <vector>

// Can set an integer to nullptr with this
struct Node
{
public:
	Node(int newData) : data(newData) {}

	int data;
};

class BST
{
public:
	BST(); // Empty tree constructor
	BST(int, BST*); // Child node constructor

	// Operations
	void add(int);
  // void print();

	// Getters
	int getLength();
	std::vector<int> getData();

private:
	Node* dataInit;

	BST* prev;
	BST* left;
	BST* right;
};
