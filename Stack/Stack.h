// Program: Stack Data Structure
// Author: Anton Koetzler-Faust
//
// Features
// - push(T)
// 		- Adds one element to the back of the stack
// - pop()
// 		- Removes the last element in the stack
// - isEmpty()
// 		- Checks if the stack is empty
// - getSize()
// 		- Returns the size of the stack
// - print()
// 		- Prints the stack

#pragma once
#include <iostream>
#include <typeinfo>
#include <iomanip>

template <class T>
class Stack
{
public:
	// Empty stack
	Stack()
	{
		data = nullptr;
		size = 0;
	}
	// 1 element stack
	Stack(T obj)
	{
		data = new T[1];
		data[0] = obj;
		size = 1;
	}
	~Stack()
	{
		delete[] data;
		data = nullptr;
		size = 0;
	}

	void push(T obj)
	{
		// Empty stack case
		if (data == nullptr)
		{
			data = new T[1];
			data[0] = obj;
			size = 1;
		}
		// Stack reallocation case
		else
		{
			T* newData = new T[size + 1];

			// Transferring our data to the new stack
			for (int i = 0; i < size; i++)
				newData[i] = data[i];

			// Adding obj to the new stack
			newData[size] = obj;

			// Updating the size of our stack
			size++;

			delete[] data;
			data = nullptr;
			data = newData;
		}
	}
	bool pop()
	{
		// Empty stack case
		if (data == nullptr) return false;
		// Stack reallocation case
		else
		{
			// Turning the stack into an empty stack
			if (size == 1)
			{
				delete[] data;
				data = nullptr;
				size = 0;
			}
			else
			{
				T* newData = new T[size + 1];

				// Transfering data to new stack
				for (int i = 0; i < (size - 1); i++)
					newData[i] = data[i];

				// Updating size of our stack
				size--;

				delete[] data;
				data = nullptr;
				data = newData;
			}
			
			return true;
		}
	}
	bool isEmpty()
	{
		if (data == nullptr) return true;
		else return false;
	}
	void print()
	{
		// Empty stack case
		if (data == nullptr)
		{
			std::cout << "Empty stack" << std::endl;
			return;
		}
		else
		{
			// Neater printing for float and double stack
			std::string datatype;

			for (int i = 0; i < size; i++)
			{
				datatype = typeid(data[i]).name();

				if (datatype == "f" || datatype == "float" || datatype == "d" || datatype == "double")
					std::cout << std::fixed << std::setprecision(sizeof(data[i])) << data[i];
				else
					std::cout << data[i];

				if (i == (size - 1)) std::cout << std::endl;
				else std::cout << ", ";
			}
		}
	}
	int getSize() { return size; }
private:
	T* data;  // Our array
	int size; // Size of our array
};
