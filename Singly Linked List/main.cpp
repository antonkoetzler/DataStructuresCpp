// Singly Linked List Demo
#include "SLL.h"

int main()
{
	SLL<int> myList;

	std::cout << std::endl;

	// add(value)
	for (int i = 0; i < 5; i++)
		myList.add(i);
	std::cout << "A list of 5!" << std::endl;
	myList.print(); std::cout << std::endl << std::endl;

	// add(value, index)
	myList.add(25, 2);
	myList.add(100, 6);
	myList.add(10, 0);
	std::cout << "Adding to specific indices" << std::endl;
	myList.print(); std::cout << std::endl << std::endl;

	// del()
	for (int i = 0; i < 3; i++)
		myList.del();
	std::cout << "Removed top 3 elements" << std::endl;
	myList.print(); std::cout << std::endl << std::endl;

	// del(value)
	myList.del(10); myList.del(2); myList.del(1);
	std::cout << "Removed 3 specific elements" << std::endl;
	myList.print(); std::cout << std::endl << std::endl;

	// search(value)
	std::cout << "Is the number 1 within this list?: ";
	if (myList.search(1))
		std::cout << "Yes." << std::endl;
	else
		std::cout << "No." << std::endl;
	std::cout << "Is the number 25 within this list?: ";
	if (myList.search(25))
		std::cout << "Yes." << std::endl;
	else
		std::cout << "No." << std::endl;
	std::cout << std::endl << std::endl;

	// size()
	std::cout << "Finally, what is the size of our list?: " << myList.size() << std::endl;
		
	return 0;
}
