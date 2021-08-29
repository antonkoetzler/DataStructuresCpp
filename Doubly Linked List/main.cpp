#include "DLL.h"

int main()
{
	std::cout << std::endl << "Doubly Linked List Demo" << std::endl << std::endl;

	DLL<int> foo;

	// add(value)
	std::cout << "Adding values with add(value)" << std::endl;
	for (int i = 0; i < 5; i++) foo.add(i);
	foo.print(); std::cout << std::endl << std::endl;
	
	// add(value, index)
	std::cout << "Adding specific values with add(value, index)" << std::endl;
	foo.add(1000, 0); foo.add(1000, 3); foo.add(1000, 7);
	foo.print(); std::cout << std::endl << std::endl;

	// del()
	std::cout << "Using del() to remove the top 3 elements" << std::endl;
	for (int i = 0; i < 3; i++) foo.del();
	foo.print(); std::cout << std::endl << std::endl;

	// del(index)
	std::cout << "Deleting 3 specific elements with del(index)" << std::endl;
	foo.del(4); foo.del(1); foo.del(0);
	foo.print(); std::cout << std::endl << std::endl;

	// begin() & end()
	std::cout << "Adding a couple more values, than showing begin() and end()" << std::endl;
	for (int i = 0; i < 3; i++) foo.add(i + 3);
	std::cout << "New list: "; foo.print();
	std::cout << "foo.begin(): " << foo.begin() << std::endl;
	std::cout << "foo.end(): " << foo.end() << std::endl;
	foo.print(); std::cout << std::endl << std::endl;

	// size()
	std::cout << "Getting the size of our list with size()" << std::endl;
	std::cout << "Size of our list: " << foo.size() << std::endl << std::endl;

	// [] functionality
	std::cout << "Changing an element with the [] operator" << std::endl;
	std::cout << "Before: "; foo.print();
	foo[1] = 1500;
	std::cout << "After: "; foo.print(); std::cout << std::endl << std::endl;

	// reversePrint()
	std::cout << "Printing the list in reverse with reversePrint()" << std::endl;
	foo.print();
	foo.reversePrint(); std::cout << std::endl << std::endl;

	// clear()
	std::cout << "Clearing our list with clear()" << std::endl;
	foo.clear();
	foo.print(); std::cout << std::endl << std::endl;

	// [] error case
	std::cout << "To end off the program, I'll show what happens when you" << std::endl;
	std::cout << "reference an incorrect index using the [] operator" << std::endl;
	std::cout << std::endl << "ERROR CREATED: "; foo[-1];

	return 0;
}
