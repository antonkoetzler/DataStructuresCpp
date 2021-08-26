// Singly Linked List Demo
#include "SLL.h"

int main()
{
	SLL<int> myList;

	for (int i = 0; i < 5; i++)
		myList.add(i);

	// A list of 5!
	myList.print(); std::cout << std::endl << std::endl;

	myList.add(25, 2);
	myList.add(100, 6);
	myList.add(10, 0);

	// Modified the list
	myList.print(); std::cout << std::endl << std::endl;

	// Delete 3 elements
	for (int i = 0; i < 3; i++)
		myList.del();

	myList.print(); std::cout << std::endl << std::endl;

	std::cout << "Is the number 1 within this list?: ";
	if (myList.search(1))
		std::cout << "Yes." << std::endl;
	else
		std::cout << "No." << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "Finally, what is the size of our list?: " << myList.size() << std::endl;
		
	return 0;
}
