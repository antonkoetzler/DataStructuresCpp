#include "SLL.h"

SLL::SLL()
{
	data = 0;

	index = 0;
	
	rootInit = false;
}

SLL::SLL(int newData, SLL* prevNode)
{
	data = newData;

	index = prevNode->getIndex() + 1;

	rootInit = true;
}

void SLL::add(int newData)
{
	if (index == 0 && !rootInit)
	{
		data = newData;
		rootInit = true;
	}
	else
	{
		if (next == nullptr)
			next = new SLL(newData, this);
		else
			next->add(newData);
	}
}

bool SLL::search(int searchData)
{
	if (data == searchData)
	{
		return true;
	}
	else
	{
		if (next != nullptr)
		{
			return next->search(searchData);
		}
		else
		{
			return false;
		}
	}
}

void SLL::print()
{
	if (rootInit)
	{
		std::cout << data;

		if (next != nullptr)
		{
			std::cout << ", ";
			next->print();
		}
		else
		{
			std::cout << std::endl << std::endl;
		}
	}
	else
	{
		std::cout << "Empty" << std::endl;
	}
}

bool SLL::del(int delData)
{
	if (data == delData)
	{
		if (index == 0)
		{
			data = 0;
			rootInit = false;
		}
		else
		{
			fillGaps();
		}
		return true;
	}
	else
	{
		if (next == nullptr)
		{
			return false;
		}
		else
			return next->del(delData);
	}
}

void SLL::fillGaps()
{
	if (next != nullptr)
	{
		data = next->getData();

		if (next->next == nullptr)
		{
			delete next; next = nullptr;
		}
		else if (next->next != nullptr)
		{
			next->fillGaps();
		}
	}
}
