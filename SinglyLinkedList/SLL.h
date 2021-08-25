/*
Singly Linked List

Operations
- add(value)
	- Adds a value to the back of the list
- add(value, index)
	- Adds a value to the index provided
- del()
	- Deletes the back element of the list
- del(value)
	- Deletes the value provided
- back()
	- Gets the back of the list
- front()
	- Gets the front of the list
- search(value)
	- Searches for the value and returns the data if true
- print()
	- Prints the list
- toFile()
	- Converts the array to a text file

Features
- Operation overloading, works like a normal array
- Can turn your array into a text file
- One file implementation

Author: Anton Koetzler-Faust
*/

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

	// Creates a 1 element list, or adds to an existing list
	SLL(T newData)
	{
		data = new T(newData);
		next = nullptr;
	}

	~SLL()
	{
		delete next;
		delete data;
		next = nullptr;
		data = nullptr;
	}


	void add(T newData)
	{
		// Empty list
		if (data == nullptr)
			data = new T(newData);
		// Recurse
		else if (next != nullptr)
			next->add(newData);
		// Add SLL to existing list
		else
			next = new SLL(newData);
	}
	bool add(T newData, int index)
	{
		static int counter = 0;

		// Error handling
		if (counter == 0)
		{
			if (index > this->size() || index < 0)
				return false;
			// Makes life easier
			else if (index == this->size())
			{
				this->add(newData);
				return true;
			}
		}

		// Index found
		if (counter == index)
		{
			counter++;

			// Transfering data and making space after the add call
			T transferData = *data;
			delete data;
			data = nullptr;
			data = new T(newData);

			// Makes space for the other elements
			if (next != nullptr)
				next->makeSpace(transferData);

			return true;
		}
		// Recurse
		else if (next != nullptr)
		{
			counter++;
			next->add(newData, index);
		}
		// Object not found
		else
		{
			counter = 0;
			return false;
		}
	}
	void makeSpace(T transferData)
	{
		T transfer = *data;
		delete data;
		data = nullptr;
		data = new T(transferData);

		if (next != nullptr)
			next->makeSpace(transfer);
		else
			next = new SLL(transfer);
	}


	int size()
	{
		static int size = 0;

		// Empty list
		if (data == nullptr)
			return 0;

		size++;

		if (next != nullptr)
			next->size();
		else
		{
			int returnSize = size;
			size = 0; // Reset the static variable
			return returnSize;
		}
	}


	void print()
	{
		// Empty list
		if (data == nullptr)
		{
			std::cout << "Empty list" << std::endl;
			return;
		}

		std::cout << *data;

		if (next != nullptr)
		{
			std::cout << ", ";
			next->print();
		}
		else
			std::cout << std::endl;
	}

private:
	T* data;
	SLL<T>* next;
};