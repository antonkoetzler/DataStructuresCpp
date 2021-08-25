// Demo for my Singly Linked List

#include "SLL.h"

int main()
{
	SLL<int>* foo1 = new SLL<int>();

	for (int i = 0; i < 5; i++)
		foo1->add(i);

	std::cout << "foo1->add: " << foo1->add(10, 0) << std::endl;
	foo1->print();

	delete foo1;
	return 0;
}