#pragma once
#include <iostream>
#include <typeinfo>
#include <iomanip>

template <class T>
class Queue
{
public:
	Queue()
	{
		data = nullptr;
		size = 0;
	}
	Queue(T obj)
	{
		data = new T[1];
		data[0] = obj;
		size = 1;
	}
	~Queue()
	{
		delete[] data;
		data = nullptr;
		size = 0;
	}

	void push(T obj)
	{
		// Empty queue case
		if (data == nullptr)
		{
			data = new T[1];
			data[0] = obj;
			size = 1;
		}
		// Reallocating data case
		else
		{
			T* newData = new T[size + 1];

			// Transfering the data
			for (int i = 1; i < (size + 1); i++)
				newData[i] = data[i - 1];

			// Adding obj to the queue
			newData[0] = obj;

			// Updating size
			size++;

			delete[] data;
			data = nullptr;
			data = newData;
		}
	}
	bool pop()
	{
		// Empty queue case
		if (data == nullptr) return false;
		else
		{
			// Turning into an empty queue case
			if (size == 1)
			{
				delete[] data;
				data = nullptr;
				return true;
			}
			else
			{
				T* newData = new T[size - 1];

				// Updating size
				size--;

				for (int i = 0; i < size; i++)
					newData[i] = data[i];

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
	int getSize() { return size;  }
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
private:
	T* data;
	int size;
};
