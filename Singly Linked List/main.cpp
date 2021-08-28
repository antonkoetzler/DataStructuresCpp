#include "SLL.h"

#include <vector>

int main()
{
	std::cout << std::endl << "Singly Linked List Demo" << std::endl;

	SLL<int> in(5);
	SLL<double> db;

	// Showing constructors
	std::cout << std::endl << "Empty list constructor & non-empty" << std::endl;
	std::cout << "SLL object 'in': "; in.print();
	std::cout << "SLL object 'db': "; db.print();

	// add(value)
	std::cout << std::endl << "Adding values with add(value)" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		in.add(i);

		double addToDouble = i * float(0.00000001);
		db.add(addToDouble);
	}

	std::cout << "SLL object 'in': "; in.print();
	std::cout << "SLL object 'db': "; db.print();

	// add(value, indeX)
	std::cout << std::endl << "Adding specific values with add(value, index)" << std::endl;
	in.add(1000, 0); in.add(1000, 3); in.add(1000, 8);
	db.add(1000, 0); db.add(1000, 3); db.add(1000, 7);
	std::cout << "SLL object 'in': "; in.print();
	std::cout << "SLL object 'db': "; db.print();

	// del()
	std::cout << std::endl << "Using del() to remove the top 3 elements" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		in.del();
		db.del();
	}
	std::cout << "SLL object 'in': "; in.print();
	std::cout << "SLL object 'db': "; db.print();

	// del(index)
	std::cout << std::endl << "Deleting 3 specific elements with del(index)" << std::endl;
	in.del(5); in.del(0); in.del(2);
	db.del(4); db.del(0); db.del(2);
	std::cout << "SLL object 'in': "; in.print();
	std::cout << "SLL object 'db': "; db.print();
	
	// begin() & end()
	std::cout << std::endl << "Getting the front and back elements with begin() and end()" << std::endl;
	std::cout << "in.begin(): " << in.begin() << std::endl;
	std::cout << "in.end(): " << in.end() << std::endl;

	// size()
	std::cout << std::endl << "Getting the size of our two lists with size()" << std::endl;
	std::cout << "in's size: " << in.size() << std::endl;
	std::cout << "db's size: " << db.size() << std::endl;

	// [] functionality
	std::cout << std::endl << "Changing an element with the [] operator" << std::endl;
	in[1] = 1500; std::cout << "SLL object 'in': "; in.print();
	db[0] = 2000; std::cout << "SLL object 'db': "; db.print();

	// clear()
	std::cout << std::endl << "Clearing our lists with clear()" << std::endl;
	in.clear(); db.clear();
	std::cout << "SLL object 'in': "; in.print();
	std::cout << "SLL object 'db': "; db.print();

	return 0;
}
