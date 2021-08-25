/*
Program: Singly Linked List

Operations
- add(value) ~ Adds a new value to the end of the list
- add(value, index) ~ Adds a new value to the index provided
- del() ~ Deletes the end element of the list
- del(value) ~ Deletes the value provided
- del(index) ~ Deletes the value at the index provided
- search(value) ~ Searches for a value and returns true if it's in the list
- getElement(index) ~ Get's the element's data at the index provided
- getData() ~ Get's the list and converts it into a text file
- print() ~ Prints the list

Features
- One header file (easy to implement)
- Can create a text file of your list

Author: Anton Koetzler-Faust
*/

#pragma once

#include <iostream>

template <class T>
class SLL
{
public:
	SLL()
	{
		data = nullptr;
		next = nullptr;
	}
	SLL(T newData)
	{
		next = nullptr;
		data = new T(newData);
	}
	~SLL()
	{
		delete next;
	}

	void add(T newData)
	{
		// Checking if we have an empty list
		if (data == nullptr)
			data = new T(newData);
		else if (next == nullptr)
			next = new SLL<int>(newData);
		else
			next->add(newData);
	}

	void add(T newData, int index)
	{
		static int counter = 0; // Record where we are recursing to
		static int size;        // Get the size of the array

		// Making sure we don't have an index greater than the list
		if (counter == 0)
		{
			size = this->size();
			if (index > size)
			{
				std::cout << "Invalid index provided" << std::endl;
				return;
			}
		}

		counter++;

		if (counter == index)
			std::cout << "counter == index" << std::endl;
		else if (next != nullptr)
			next->add(newData, index);
	}

	void print()
	{
		// Checking if we have an empty list
		if (data == nullptr)
			std::cout << "This is an empty singly linked list." << std::endl;

		std::cout << *data;

		if (next == nullptr)
			std::cout << std::endl;
		else
		{
			std::cout << ", ";
			next->print();
		}
	}

	int size()
	{
		static int size = 0;

		// Empty list condition
		if (data == nullptr)
			return size;

		size++;

		if (next == nullptr)
		{
			int returnSize = size;
			size = 0; // Resetting the size
			return returnSize;
		}
		else
			return next->size();
	}
private:
	T* data;
	SLL<T>* next;
};