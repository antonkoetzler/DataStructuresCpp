// Program: Singly Linked List
// Author: Anton Koetzler-Faust
//
// Features
// - add(value)
// 		- Adds the value to the back of the list
// - add(value, index)
// 		- Adds value to the index specified
// - del()
// 		- Deletes the back element of the list
// - del(index)
// 		- Deletes the index specified
// - print()
// 		- Prints the list
// - clear()
// 		- Clears all elements in the list
// - size() 
// 		- Returns the size of the list
// - begin() & end()
// 		- Returns the beginning or end element of the list
// - Works like an array with [] functionality
// 		- You can reference elements and change singular elements how you would in a normal array

#pragma once
#include <iostream>
#include <typeinfo>
#include <iomanip>

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
	// Creates a 1 object list or adds to an existing list
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
		// Free spot (nullptr next) found for newData
		else if (next == nullptr)
			next = new SLL(newData);
		// Recurse case
		else
			next->add(newData);
	}
	bool add(T newData, int index)
	{
		// Empty list case
		if (data == nullptr && index != 0) return false;

		static int counter = 0;

		// Checking that index is appropriate / function simplification
		if (counter == 0) // At counter == 0 since we're at the root of the list
		{
			// index can't be greater than the list size or less than 0
			if (index > this->size() || index < 0) return false;
			// A case where we can use add() instead of this function
			else if (index == this->size())
			{
				this->add(newData);
				return true;
			}
		}

		if (counter == index)
		{
			counter = 0;
			makeSpace(newData);
			return true;
		}
		// Recurse case
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
	void makeSpace(T transferData)
	{
		T transfer = *data;
		delete data;
		data = nullptr;
		data = new T(transferData);

		if (next != nullptr) next->makeSpace(transfer);
		else next = new SLL(transfer);
	}

	bool del()
	{
		static bool rootChecked = false;

		// Portion to check the first element
		if (data == nullptr) return false;
		else if (!rootChecked && next == nullptr)
		{
			// Now an empty list
			delete data;
			data = nullptr;
			return true;
		}

		rootChecked = true;

		// Portion analyzing next pointers
		if (next != nullptr)
		{
			// End case, we're at the last index
			if (next->next == nullptr)
			{
				rootChecked = false;
				delete next;
				next = nullptr;
				return true;
			}
			// Recurse case
			else
				next->del();
		}
		// Error case
		else
		{
			rootChecked = false;
			return false;
		}
	}
	bool del(int index)
	{
		// Empty list case
		if (data == nullptr) return false;

		static int counter = 0;

		// Checking index / function simplification / checking root node
		if (counter == 0)
		{
			// appropriate error case
			if (index > this->size() || index < 0)
				return false;
			// 1 object list case
			else if (counter == index && next == nullptr)
			{
				delete data;
				data = nullptr;
				return true;
			}
			// index == 0, not a 1 object list
			else if (counter == index && next != nullptr)
			{
				counter = 0;
				fillGaps();
				return true;
			}
			// del() case
			else if (index == (this->size() - 1))
				return this->del();
		}

		// Portion analyzing next pointers
		counter++; // counter = 1 on the first run, indicating the second element (next)
		
		if (counter == index && next != nullptr)
		{
			counter = 0;
			next->fillGaps();
			return true;
		}
		// Recurse case
		else if (next->next != nullptr)
			next->del(index);
		// Error case
		else
		{
			std::cout << "data: " << *data << " counter: " << counter << std::endl;
			counter = 0;
			return false;
		}
	}
	// Helper function that deletes the node and reallocates the list
	void fillGaps()
	{
		if (next != nullptr)
		{
			// Replacing data
			delete data;
			data = nullptr;
			data = new T(*next->data);

			// End case
			if (next->next == nullptr)
			{
				delete next;
				next = nullptr;
			}
			// Recurse case
			else
				next->fillGaps();
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

		// Getting the datatype for neater printing
		std::string datatype = typeid(*data).name();
		
		// For float and double list
		if (datatype == "f" || datatype == "float" || datatype == "d" || datatype == "double")
			std::cout << std::fixed << std::setprecision(sizeof(*data)) << *data;
		else
			std::cout << *data;

		if (next != nullptr)
		{
			std::cout << ", ";
			next->print();
		}
		else
			std::cout << std::endl;
	}
	int size()
	{
		// Empty list case
		if (data == nullptr) return 0;

		static int size = 0;
		size++;

		if (next != nullptr) next->size();
		else
		{
			int returnSize = size;
			size = 0; // Reset static variable
			return returnSize;
		}
	}
	bool clear()
	{
		// Empty list case
		if (data == nullptr) return false;

		// Using del() to make life easier
		int listSize = this->size();
		for (int i = 0; i < listSize; i++) this->del();

		return true;
	}
	T begin() { if (data != nullptr) return *data; }
	T end()
	{
		if (next != nullptr)
			next->end();
		else
			return *data;
	}

	T& operator[] (int index)
	{
		// Error check
		if (index >= this->size() || index < 0)
		{
			std::cout << "Incorrect index" << std::endl;
			exit(0);
		}

		return *data;
	}
private:
	T* data;
	SLL* next;
};
