#include "SLL.h"

SLL::SLL()
{
	rootInit = false;
}

SLL::SLL(int newData)
{
	data = newData;
	rootInit = true;
}

void SLL::add(int newData)
{
	// Empty Case
	if (!rootInit)
	{
		data = newData;
		rootInit = true;
	}
	else
	{
		if (next != nullptr)
			next->add(newData);
		else
			next = new SLL(newData);
	}
}

bool SLL::search(int searchData)
{
	// Empty case
	if (!rootInit)
		return false;
	else
	{
		if (searchData == data)
			return true;
		else
		{
			if (next != nullptr)
				return next->search(searchData);
			else
				return false;
		}
	}
}

bool SLL::del(int delData)
{
	// Empty case
	if (!rootInit)
		return false;
	else
	{
		if (delData == data)
		{
			fillGaps();
			return true;
		}
		else
		{
			if (next != nullptr)
				return next->del(delData);
			else
				return false;
		}
	}
}

void SLL::fillGaps()
{
	// Only fills gaps of elements
	// with latter elements available
	if (next != nullptr)
	{
		data = next->getData();

		if (next->next == nullptr)
		{
			delete next;
			next = nullptr;
		}
		else
			next->fillGaps();
	}
}

void SLL::print()
{
	// Empty case
	if (!rootInit)
		std::cout << "Empty" << std::endl << std::endl;
	else
	{
		std::cout << data;

		if (next != nullptr)
		{
			std::cout << ", ";
			next->print();
		}
		else
			std::cout << std::endl << std::endl;
	}
}
