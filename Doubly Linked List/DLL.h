// Program: Doubly Linked List
// Author: Anton Koetzler-Faust
//
// Features
// - Any datatype may be used, as the class is templated
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
// - printReverse()
// 		- Showing the advantage of a doubly linked list, this prints the list in reverse
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
class DLL
{
public:
	// Creates an empty list
	DLL()
	{
		data = nullptr;
		prev = next = nullptr;
	}
	// Empty a 1 object list
	DLL(T newData)
	{
		data = new T(newData);
		prev = next = nullptr;
	}
	// Adds to an existing list
	DLL(T newData, DLL* argPrev)
	{
		data = new T(newData);
		prev = argPrev;
		next = nullptr;
	}
	~DLL()
	{
		delete data;
		// delete prev; // Recursively deletes the whole list
		delete next;
		data = nullptr;
		prev = nullptr;
		next = nullptr;
	}

	void add(T newData)
	{
		// Empty list case
		if (data == nullptr)
			data = new T(newData);
		// Free spot found
		else if (next == nullptr)
			next = new DLL<T>(newData, this);
		// Recurse case
		else
			next->add(newData);
	}
	bool add(T newData, int index)
	{
		// Empty list case
		if (data == nullptr && index != 0) return false;

		static int counter = 0;

		// Checking index is correct / function simplification
		if (counter == 0)
		{
			// index can't be greater than list size or less than 0
			if (index > this->size() || index < 0)
				return false;
			// A case where add(value) may be used
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
		else next = new DLL(transfer, this);
	}

	bool del()
	{
		// Empty list case
		if (data == nullptr) return false;
		// 1 object list case
		else if (prev == nullptr && next == nullptr)
		{
			delete data;
			data = nullptr;
			return true;
		}

		// Checking if we're at the end of the list
		if (next == nullptr) return prev->delNext(); // Delete this pointer by deleting with prev
		// Recurse case
		else return next->del();
	}
	// del() helper function
	bool delNext()
	{
		delete next;
		next = nullptr;
		return true;
	}
	bool del(int index)
	{
		// Empty list case
		if (data == nullptr) return true;
		// 1 object list case
		else if (index == 0 && prev == nullptr && next == nullptr)
		{
			delete data;
			data = nullptr;
			return true;
		}
		
		static int counter = 0;

		if (index == counter)
		{
			counter = 0;

			// If we're at the end of the list
			if (next == nullptr) return prev->delNext();
			else
			{
				fillGaps();
				return true;
			}
		}
		// Recurse case
		else if (next != nullptr)
		{
			counter++;
			return next->del(index);
		}
		// Error case
		else
		{
			counter = 0;
			return false;
		}
	}
	// Helper function shifts the list leftwards
	// after a deletion to reallocate the memory
	void fillGaps()
	{
		delete data;
		data = nullptr;
		data = new T(*next->data);

		// End case
		if (next->next == nullptr)
		{
			delete next;
			next = nullptr;
		}
		else
			next->fillGaps();
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

		if (datatype == "f" || datatype == "float" || datatype == "d" || datatype == "double")
			std::cout << std::fixed << std::setprecision(sizeof(*data)) << *data;
		else
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
	void reversePrint()
	{
		// Empty list case
		if (data == nullptr)
		{
			std::cout << "Empty list" << std::endl;
			return;
		}

		// (E)nd (O)f (L)ist
		static bool EOL = false;

		// Forward traversals, trying to reach EOL
		if (!EOL)
		{
			// End of the list reached
			if (next == nullptr)
			{
				EOL = true;
				reversePrint();
			}
			else
				next->reversePrint();
		}
		else
		{
			// Getting the datatype for neater printing
			std::string datatype = typeid(*data).name();

			// For float and double list
			if (datatype == "f" || datatype == "float" || datatype == "d" || datatype == "double")
				std::cout << std::fixed << std::setprecision(sizeof(*data)) << *data;
			else
				std::cout << *data;

			// Recurse case
			if (prev != nullptr)
			{
				std::cout << ", ";
				prev->reversePrint();
			}
			// End case
			else
			{
				EOL = false; // Reset static variable
				std::cout << std::endl;
			}
		}
	}
	int size()
	{
		// Empty list case
		if (data == nullptr) return false;

		static int size = 0;
		size++;

		// Recurse case
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
		if (next != nullptr) next->end();
		else return *data;
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
	DLL* prev;
	DLL* next;
};
