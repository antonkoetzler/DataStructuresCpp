#pragma once

#include <iostream>

class SLL
{
public:
	SLL();
	SLL(int, SLL*);

	// Operations
	void add(int);
	bool search(int);
	void print();
	bool del(int); void fillGaps();

	// Getters
	int getIndex() { return index; }
	int getData() { return data; }

private:
	int data, index;

	bool rootInit; // If first element is set

	SLL* next = nullptr;
};
