#include "Queue.h"
#include <vector>

int main()
{
	std::cout << std::endl << "Queue Demo" << std::endl << std::endl << std::endl;

	Queue<std::string> foo;

	// push(T)
	std::cout << "push(T)" << std::endl;
	std::vector<std::string> stringValues {"This", "is", "a", "string", "stack"};
	for (int i = 0; i < 5; i++) foo.push(stringValues[i]);
	foo.print(); std::cout << std::endl << std::endl;

	// pop()
	std::cout << "pop()" << std::endl;
	foo.pop();
	foo.print(); std::cout << std::endl << std::endl;

	// isEmpty()
	std::cout << "isEmpty()" << std::endl;
	std::cout << "Is our stack empty?: " << foo.isEmpty() << std::endl << std::endl << std::endl;

	// getSize()
	std::cout << "getSize()" << std::endl;
	std::cout << foo.getSize() << std::endl;

	return 0;
}
