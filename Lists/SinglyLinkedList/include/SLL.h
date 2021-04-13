#pragma once

#include <iostream>

class SLL
{
public:
	SLL();
	SLL(int);

	// Operations
	void add(int);
	bool search(int);
	bool del(int); void fillGaps();

	// Getters
	int getData() { return data; }

	// Printing
	void print();

private:
	int data;

	SLL* next = nullptr;

	bool rootInit;
};
