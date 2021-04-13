#include "DLL.h"

DLL::DLL()
{
	data = 0;
	prev = nullptr;
	rootInit = false;
}

DLL::DLL(int newData, DLL* previousNode)
{
	data = newData;
	prev = previousNode;
	rootInit = true;
}

void DLL::add(int newData)
{
	// Empty case
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
			next = new DLL(newData, this);
	}
}

bool DLL::search(int searchData)
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

bool DLL::del(int delData)
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

void DLL::fillGaps()
{
	// Only if there are elements
	if (rootInit)
	{
		// Only if there are elements
		// beyond this point.
		if (next != nullptr)
		{
			data = next->getData();

			// Recurse if there are
			// more elements to adjust
			if (next->next != nullptr)
				next->fillGaps();
			else
			{
				delete next;
				next = nullptr;
			}
		}
	}
}

void DLL::reversePrint()
{
	// Empty case
	if (!rootInit)
	{
		std::cout << "Empty list.";
		std::cout << std::endl << std::endl;
		return;
	}

	// One node case
	if (rootInit && next == nullptr)
		std::cout << data << std::endl << std::endl;

	recurse();
}

void DLL::recurse()
{
	if (next != nullptr)
		next->recurse();
	else
		reversePrintNodes();
}

void DLL::reversePrintNodes()
{
	std::cout << data;

	if (prev != nullptr)
	{
		std::cout << ", ";
		prev->reversePrintNodes();
	}
	else
		std::cout << std::endl << std::endl;
}

void DLL::print()
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
