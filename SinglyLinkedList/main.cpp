#include "SLL.h"

int main()
{
	SLL<int>* foo1 = new SLL<int>();
	SLL<int>* foo2 = new SLL<int>(5);

	foo1->add(3);
	foo1->add(2);
	foo1->add(1);
	foo1->add(3, 1);
	foo1->print();

	delete foo1;
	delete foo2;

	return 0;
}