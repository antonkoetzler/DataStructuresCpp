// Program: Singly Linked List
// Author: Anton Koetzler-Faust
//
// Operations
// - add(value)
// 		- Adds value to the back of the list
// - add(value, index)
// 		- Adds value to index provided
// - del()
// 		- Delete the back of the list
// - search(value)
// 		- Returns either true or false if the value is in the list
// - print()
// 		- Prints the list
// - size()
// 		- Returns the size of the list

#pragma once
#include <iostream>

template <class T>
class SLL
{
public:
	// Creates an empty list
	SLL()
	{
		data = nullptr;
		next = nullptr;
	}
	// Creates a 1 object list or adds to an existing list recursively
	SLL(T newData)
	{
		data = new T(newData);
		next = nullptr;
	}
	~SLL()
	{
		delete data;
		delete next;
		data = nullptr;
		next = nullptr;
	}

	
	void add(T newData)
	{
		// Empty list case
		if (data == nullptr)
			data = new T(newData);
		// next is nullptr, place newData here (end of list)
		else if (next == nullptr)
			next = new SLL<T>(newData);
		// Recurse again case
		else
			next->add(newData);
	}
	bool add(T newData, int index)
	{
		static int counter = 0;

		// Error handling; at counter = 0 bc we're at the root of the list
		if (counter == 0)
		{
			// If the index outmatches list size or if index is less than zero
			if (index > this->size() || index < 0)
				return false;
			// If add(T) can be called instead of this function,
			// this reduces one error case within this function
			else if (index == this->size())
			{
				this->add(newData);
				return true;
			}
		}

		// Object found case
		if (counter == index)
		{
			counter = 0; // Reset static variable
			makeSpace(newData);
			return true;
		}
		// Recurse again
		else if (next != nullptr)
		{
			counter++;
			next->add(newData, index);
		}
		// Error case
		else
		{
			counter = 0;
			return false;
		}
	}
	// Makes room for other elements that were
	// budded into during add(value, index) call
	void makeSpace(T transferData)
	{
		// Replace data and prepare for recursion
		T transfer = *data;
		delete data;
		data = nullptr;
		data = new T(transferData);

		// Recurse case
		if (next != nullptr)
			next->makeSpace(transfer);
		// End case
		else
			next = new SLL(transfer);
	}

	bool del()
	{
		static bool rootChecked = false;

		// Empty list case
		if (data == nullptr)
			return false;
		// Root node case
		else if (!rootChecked && next == nullptr)
		{
			delete data;
			data = nullptr;
			return true;
		}
		else if (next != nullptr)
		{
			// End case
			if (next->next == nullptr)
			{
				rootChecked = false;
				delete next;
				next = nullptr;
				return true;
			}
			// Recurse case
			else
			{
				rootChecked = true;
				next->del();
			}
		}
		// Error
		else
		{
			rootChecked = false;
			return false;
		}
	}
	void print()
	{
		// Empty list case
		if (data == nullptr)
		{
			std::cout << "Empty list" << std::endl;
			return;
		}

		std::cout << *data;

		// Recurse case
		if (next != nullptr)
		{
			std::cout << ", ";
			next->print();
		}
		// Stop printing
		else
			std::cout << std::endl;
	}
	int size()
	{
		static int size = 0;

		// Empty list case
		if (data == nullptr)
			return 0;

		size++;

		// Recurse case
		if (next != nullptr)
			next->size();
		else
		{
			int returnSize = size;
			size = 0; // Reset static variable
			return returnSize;
		}
	}
	bool search(T value)
	{
		if (data == nullptr)
			return false;
		else if (value == *data)
			return true;
		else if (next != nullptr)
			next->search(value);
		else
			return false;
	}
private:
	T* data;
	SLL* next;
};
