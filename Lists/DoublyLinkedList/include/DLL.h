#pragma once

#include <iostream>

class DLL
{
public:
	DLL();
	DLL(int, DLL*);

	// Operations
	void add(int);
	bool search(int);
	bool del(int);
		void fillGaps();

	// Doubly Linked List Operations
	void reversePrint(); // Forward then backward traversal
		void recurse(); // Does the work
		void reversePrintNodes(); // Prints the nodes

	// Getters
	int getData() { return data; }

	// Printing
	void print();

private:
	int data;

	DLL* prev;
	DLL* next = nullptr; // Always nullptr

	bool rootInit;
};
