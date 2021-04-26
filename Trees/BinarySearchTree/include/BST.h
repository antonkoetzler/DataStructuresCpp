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
	void print();
		std::vector<std::vector<Node*>> BFSOrder(std::vector<int>&);
	bool search(int);
	bool del(int);
		void fillGaps();

	// Getters
	int getLength();
	void getData(std::vector<int>&);
	int getData() { return dataInit->data; }

private:
	Node* dataInit;

	BST* prev;
	BST* left;
	BST* right;
};
